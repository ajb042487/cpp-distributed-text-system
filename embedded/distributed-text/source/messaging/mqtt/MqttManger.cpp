
#include <limits>
#include <time.h>
#include "utility/StringSerializer.h"
#include "messaging/mqtt/MqttManager.h"

namespace Messaging
{
namespace Mqtt
{

using Utility::StringSerializer;

	MqttManager::MqttManager(std::string hostname, uint16_t port) :
		_serverHost(hostname)
	{
		uint16_t randomID;
		srand (time(NULL));
		randomID = rand() % std::numeric_limits<uint16_t>::max();
		StringSerializer::toString (randomID, clientID);
		clientID = "embedded-client" + clientID;

		StringSerializer::toString (port, _serverPort);
		_serverAddress = std::string("ws://" + _serverHost + ":" + _serverPort + "/mqtt");

		printf("Creating MQTT Client\n");
		printf("[MQTT-%s] %s\n", clientID.c_str(), _serverAddress.c_str());
		MQTTClient_create(
			&_client,
			_serverAddress.c_str(),
			clientID.c_str(),
			MQTTCLIENT_PERSISTENCE_NONE,
			NULL
		);
		MQTTClient_setCallbacks(_client, NULL, MqttManager::onConnectionLost, MqttManager::onMessageArrived, MqttManager::onMessageDelivered);
	}

	MqttManager::~MqttManager()
	{
		MQTTClient_disconnect(_client, 10000);
		MQTTClient_destroy(&_client);
	}

	bool MqttManager::connect()
	{
		int rc;
		MQTTClient_connectOptions conn_opts = MQTTClient_connectOptions_initializer;
		conn_opts.keepAliveInterval = 20;
		conn_opts.cleansession = 1;
		printf("[MQTT-%s] Connecting...\n", clientID.c_str());
		if ((rc = MQTTClient_connect(_client, &conn_opts)) != MQTTCLIENT_SUCCESS)
		{
			printf("[MQTT-%s] Failed to connect, return code %d\n", clientID.c_str(), rc);
			return false;
		}
		printf("[MQTT-%s] Connected\n", clientID.c_str());
		return true;
	}

	void MqttManager::subscribe(std::string topic, int qos)
	{
		MQTTClient_subscribe(_client, topic.c_str(), qos);
	}

	bool MqttManager::send(std::string payload)
	{
		int rc;
		MQTTClient_deliveryToken token;
		MQTTClient_message pubmsg = MQTTClient_message_initializer;
		pubmsg.payload = (void*)payload.c_str();
		pubmsg.payloadlen = payload.length();
		pubmsg.qos = 2;
		pubmsg.retained = 0;
		MQTTClient_publishMessage(_client, "/us/uchat/pub", &pubmsg, &token);

		printf("[MQTT-%s] Publishing...\n", clientID.c_str());
		printf(
			"[MQTT-%s] Waiting for up to %d seconds for publication of %s\n"
			"on topic %s\n",
			clientID.c_str(),
			(int)(10),
			payload.c_str(),
			"/us/uchat/pub"
		);
		if ((rc = MQTTClient_waitForCompletion(_client, token, 10000)) != MQTTCLIENT_SUCCESS)
		{
			printf("[MQTT-%s] Failed to deliver token %d\n", clientID.c_str(), token);
			return false;
		}
		printf("[MQTT-%s] Delivered token %d\n", clientID.c_str(), token);
		return true;
	}

	void MqttManager::onConnectionLost(void* context, char* cause)
	{
		printf("Connection lost with cause %s\n", cause);
	}

	void MqttManager::onMessageDelivered(void *context, MQTTClient_deliveryToken dt)
	{
		printf("Message with token value %d delivery confirmed\n", dt);
	};

	int MqttManager::onMessageArrived(void *context, char *topicName, int topicLen, MQTTClient_message *message)
	{
		printf("Received from: %s, payload: %.*s\n", topicName, message->payloadlen, message->payload);
		/*
		int i;
		char* payloadptr;

		printf("Message arrived\n");
		printf("     topic: %s\n", topicName);
		printf("   message: ");

		payloadptr = message->payload;
		for(i=0; i<message->payloadlen; i++)
		{
			putchar(*payloadptr++);
		}
		putchar('\n');
		MQTTClient_freeMessage(&message);
		MQTTClient_free(topicName);
		return 1;
		var jsonObject = JSON.parse(message.payloadString);
		console.log("onMessageArrived:"+ message.payloadString);
		if(jsonObject.name == "update")
		{
		console.log("onSubscribeFail:", jsonObject);
		if (jsonObject.key == "Backspace")
		{
		if(jsonObject.startPosition > 0)
		{
		textArea.value = (
		textArea.value.slice(0, jsonObject.startPosition - 1) +
		textArea.value.slice(jsonObject.startPosition)
		);
		}
		}
		else if (jsonObject.key == "Delete")
		{
		if(jsonObject.startPosition < textArea.value.length)
		{
		textArea.value = (
		textArea.value.slice(0, jsonObject.startPosition) +
		textArea.value.slice(jsonObject.startPosition + 1)
		);
		}
		}
		else if (jsonObject.key == "Enter")
		{
		textArea.value = (
		textArea.value.slice(0, jsonObject.startPosition) +
		'\r' +
		textArea.value.slice(jsonObject.startPosition)
		);
		}
		else
		{
		textArea.value = (
		textArea.value.slice(0, jsonObject.startPosition) +
		jsonObject.key +
		textArea.value.slice(jsonObject.startPosition)
		);
		}
		}
		*/
		MQTTClient_freeMessage(&message);
		MQTTClient_free(topicName);
		return 1;
	}
}
}
