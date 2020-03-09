#ifndef UNIX_SIGNALMANGER_H
#define UNIX_SIGNALMANGER_H

#include <signal.h>

namespace Unix
{

class SignalManager
{
public:
	virtual ~SignalManager();
	static SignalManager& getInstance();
	bool registerHandler(void (*handler) (int));
	bool registerSignal(int signum);
private:
	SignalManager();
	//Disallow Copy and Assign
	SignalManager(SignalManager const&); // Don't Implement
	void operator=(SignalManager const&); // Don't implement
	struct sigaction _sigAction;
	bool _initialized;
};

}

#endif /* UNIX_SIGNALMANGER_H */
