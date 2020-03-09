
#include "messaging/server/WebServerManager.h"

namespace Messaging
{
namespace Server
{

WebServerManager::WebServerManager(
	std::vector<std::string> options
)
{
	const char* c_options[41] = {0};
	if(options.size()%2 == 0 && options.size() <= 40)
	{
		int i = 0;
		std::vector<std::string>::iterator it = options.begin();
		for(;it != options.end(); ++it, i++)
		{
			c_options[i] = (*it).c_str();
			printf("[New Option] %s\n", c_options[i]);
		}
		c_options[i] = NULL;
	}

	mg_init_library(0);
	ctx = mg_start(NULL, 0, c_options);
}

WebServerManager::~WebServerManager()
{
	mg_stop(ctx);
	mg_exit_library();
}

}
}
