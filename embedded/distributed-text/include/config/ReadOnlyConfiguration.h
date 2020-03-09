#ifndef CONFIG_READONLYCONFIGURATION_H
#define CONFIG_READONLYCONFIGURATION_H

#include <cstdint>
#include <string>
#include <vector>

#include "rapidjson/document.h" //#TODO: Forward-declare

namespace Config
{

using rapidjson::Document;

class ReadOnlyConfiguration
{
public:
	ReadOnlyConfiguration();
	virtual ~ReadOnlyConfiguration();

	bool readConfiguration(std::string configurationFile);

	// Only shown function signatures are supported!
	bool getValue(const std::string path, uint8_t& value);
	bool getValue(const std::string path, uint16_t& value);
	bool getValue(const std::string path, uint32_t& value);
	bool getValue(const std::string path, uint64_t& value);

	bool getValue(const std::string path, int8_t& value);
	bool getValue(const std::string path, int16_t& value);
	bool getValue(const std::string path, int32_t& value);
	bool getValue(const std::string path, int64_t& value);

	bool getValue(const std::string path, double& value);

	bool getValue(const std::string path, std::string& value);

	bool getValue(const std::string path, std::vector<uint8_t>& value);
	bool getValue(const std::string path, std::vector<uint16_t>& value);
	bool getValue(const std::string path, std::vector<uint32_t>& value);
	bool getValue(const std::string path, std::vector<uint64_t>& value);

	bool getValue(const std::string path, std::vector<int8_t>& value);
	bool getValue(const std::string path, std::vector<int16_t>& value);
	bool getValue(const std::string path, std::vector<int32_t>& value);
	bool getValue(const std::string path, std::vector<int64_t>& value);

	bool getValue(const std::string path, std::vector<double>& value);

	bool getValue(const std::string path, std::vector<std::string>& value);

private:
	//Disallow Copy and Assign
	ReadOnlyConfiguration(ReadOnlyConfiguration const&); // Don't Implement
	void operator=(ReadOnlyConfiguration const&); // Don't implement
	rapidjson::Document* _json;
};

}

#endif /* CONFIG_READONLYCONFIGURATION_H */
