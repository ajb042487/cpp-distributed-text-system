#ifndef MESSAGING_SERVER_WEBSERVERMANGER_H
#define MESSAGING_SERVER_WEBSERVERMANGER_H

#include <vector>
#include <string>
#include "civetweb.h"

namespace Messaging
{
namespace Server
{

class WebServerManager
{
public:
	WebServerManager(
		std::vector<std::string> options
);
	virtual ~WebServerManager();
	bool create(){ return false; };
private:
	//Disallow Copy and Assign
	WebServerManager(WebServerManager const&); // Don't Implement
	void operator=(WebServerManager const&); // Don't implement
	struct mg_context *ctx;
};

}
}

#endif /* MESSAGING_SERVER_WEBSERVERMANGER_H */
