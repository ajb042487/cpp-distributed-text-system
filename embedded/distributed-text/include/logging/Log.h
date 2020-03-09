#ifndef LOGGING_LOG_H
#define LOGGING_LOG_H

namespace Logging
{

class Log
{
public:
	virtual ~Log();
	static Log& getInstance();
	bool initialize();
	bool logTrace(char* format, ...);
	bool logDebug(char* format, ...);
	bool logInfo(char* format, ...);
	bool logWarning(char* format, ...);
	bool logError(char* format, ...);
private:
	Log();
	//Disallow Copy and Assign
	Log(Log const&); // Don't Implement
	void operator=(Log const&); // Don't implement
	bool _initialized;
};

}

#endif /* LOGGING_LOG_H */
