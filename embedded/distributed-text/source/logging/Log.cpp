
#include <cstdarg>
#include <cstdio>
#include "logging/Log.h"

namespace Logging
{
	Log::Log()
	{
		_initialized = false;
	}

	Log::~Log()
	{

	}

	Log& Log::getInstance()
	{
		static Log _instance;
		return _instance;
	}

	bool Log::initialize()
	{
		if(!_initialized)
		{
			_initialized = true;
		}
		return _initialized;
	}

	bool logTrace(char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
		return false;
	}

	bool logDebug(char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
		return false;
	}

	bool logInfo(char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
		return false;
	}

	bool logWarning(char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
		return false;
	}

	bool logError(char* format, ...)
	{
		va_list args;
		va_start(args, format);
		vprintf(format, args);
		va_end(args);
		return false;
	}
}
