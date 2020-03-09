
#include <unistd.h>
#include <string>

#include "unix/SignalManager.h"
using Unix::SignalManager;

#include "logging/Log.h"
using Logging::Log;

#include "config/ReadOnlyConfiguration.h"
using Config::ReadOnlyConfiguration;

#include "messaging/server/WebServerManager.h"
using Messaging::Server::WebServerManager;

#include "messaging/mqtt/MqttManager.h"
using Messaging::Mqtt::MqttManager;

#include "utility/StringDeserializer.h"
using Utility::StringDeserializer;

#include "utility/StringSerializer.h"
using Utility::StringSerializer;

static bool runLoop = true;
static const std::string CONFIGURATION_LOGGING_LEVEL = "logging.level";

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
static void signalHandler (int signal)
{
	runLoop = false;
}
#pragma GCC diagnostic pop

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
int main(int argc, char** argv)
{
	uint16_t mqttPort = 8000;
	uint16_t webServerPort = 0;
	std::string webserverPortString = "8080";
	std::string mqttHostname = "broker.mqttdashboard.com";
	std::string initalTextPath = "intialText.txt";
	std::vector<std::string> webserverOptions;

	Log& logger = Log::getInstance();
	logger.initialize();

	if(3 != argc)
	{
		printf("Error: The incorrect number of arguments were provided\n");
		printf("./distributed-text <webserver_port> <configuration_file_path.json>\n");
		exit(-1);
	}

	if(StringDeserializer::toNumeric(argv[1], webServerPort))
	{
		printf("Webserver Listening on: %d\n", webServerPort);
	}

	ReadOnlyConfiguration config;
	std::string configurationFilePath(argv[2]);
	if(config.readConfiguration(configurationFilePath))
	{
		printf("Reading configuration file %s\n", configurationFilePath.c_str());
		if(config.getValue("mqtt_port", mqttPort))
		{
			printf("mqtt_port: %d\n", mqttPort);
		}

		if(config.getValue("mqtt_hostname", mqttHostname))
		{
			printf("mqtt_hostname: %s\n", mqttHostname.c_str());
		}

		if(config.getValue("inital_text_path", initalTextPath))
		{
			printf("inital_text_path: %s\n", initalTextPath.c_str());
		}
	}

	webserverOptions.push_back("document_root");
	webserverOptions.push_back("www");
	WebServerManager webServer(webserverOptions);

	SignalManager& manager = SignalManager::getInstance();
	manager.registerHandler(signalHandler);
	manager.registerSignal(SIGINT);
	manager.registerSignal(SIGTERM);
	printf("Entering main loop (Ctrl + c) to quit\n");

	MqttManager mqttClient(mqttHostname, mqttPort);
	if(StringSerializer::toString (webServerPort, webserverPortString))
	{
		webserverOptions.push_back("listening_ports");
		webserverOptions.push_back(webserverPortString);		
	}

	if(mqttClient.connect())
	{
		mqttClient.subscribe("/us/uchat/pub", 2);
	}
	printf("Allow us through your firewall ;)\n");

	while(runLoop)
	{
		usleep(10000);
	}

	printf("\nProgram stopped by user.\n");
	return 0;
}
#pragma GCC diagnostic pop
