#ifndef CONFIG_CONFIGURATION_H
#define CONFIG_CONFIGURATION_H

#include "config/ReadOnlyConfiguration.h"
#include "config/WriteOnlyConfiguration.h"

namespace Config
{

class Configuration : public ReadOnlyConfiguration, public WriteOnlyConfiguration
{
public:
	Configuration();
	virtual ~Configuration();

private:
	//Disallow Copy and Assign
	Configuration(Configuration const&); // Don't Implement
	void operator=(Configuration const&); // Don't implement
	ReadOnlyConfiguration _readOnlyConfig;
	WriteOnlyConfiguration _writeOnlyConfig;
};


}

#endif /* CONFIG_CONFIGURATION_H */
