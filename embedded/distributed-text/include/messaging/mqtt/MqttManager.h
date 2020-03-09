#ifndef MESSAGING_MQTT_MQTTMANGER_H
#define MESSAGING_MQTT_MQTTMANGER_H

#include "MQTTClient.h"

namespace Messaging
{
namespace Mqtt
{

class MqttManager
{
public:
	MqttManager(std::string hostname, uint16_t port);
	virtual ~MqttManager();
	bool connect();
	bool send(std::string payload);
	void subscribe(std::string topic, int qos);
	static void onConnectionLost(void* context, char* cause);
	static void onMessageDelivered(void *context, MQTTClient_deliveryToken dt);
	static int onMessageArrived(void *context, char *topicName, int topicLen, MQTTClient_message *message);
	std::string clientID;
private:
	//Disallow Copy and Assign
	MqttManager(MqttManager const&); // Don't Implement
	void operator=(MqttManager const&); // Don't implement
	std::string _serverAddress;
	std::string _serverHost;
	std::string _serverPort;
	MQTTClient _client;
};

}
}

#endif /* MESSAGING_MQTT_MQTTMANGER_H */
