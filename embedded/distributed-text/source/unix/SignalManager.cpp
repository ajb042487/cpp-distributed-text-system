
#include <csignal>
#include "unix/SignalManager.h"

namespace Unix
{
	SignalManager::SignalManager()
	{
		_initialized = false;
	}

	SignalManager::~SignalManager()
	{

	}

	SignalManager& SignalManager::getInstance()
	{
		static SignalManager _instance;
		return _instance;
	}

	bool SignalManager::registerHandler(void (*handler) (int))
	{
		if(!_initialized)
		{
			_sigAction.sa_handler = handler;
			sigemptyset (&_sigAction.sa_mask);
			_sigAction.sa_flags = 0;
			_initialized = true;
		}
		return _initialized;
	}

	bool SignalManager::registerSignal(int signum)
	{
		if(_initialized)
		{
			sigaction (signum, &_sigAction, 0);
		}
		return _initialized;
	}
}
