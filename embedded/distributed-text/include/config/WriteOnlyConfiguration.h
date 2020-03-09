#ifndef CONFIG_WRITEONLYCONFIGURATION_H
#define CONFIG_WRITEONLYCONFIGURATION_H

#include <cstdint>
#include <string>
#include <vector>

namespace Config
{

class WriteOnlyConfiguration
{
public:
	WriteOnlyConfiguration();
	virtual ~WriteOnlyConfiguration();

	// Only shown function signatures are supported!
	bool setValue(const std::string path, const uint8_t& value);
	bool setValue(const std::string path, const uint16_t& value);
	bool setValue(const std::string path, const uint32_t& value);
	bool setValue(const std::string path, const uint64_t& value);

	bool setValue(const std::string path, const int8_t& value);
	bool setValue(const std::string path, const int16_t& value);
	bool setValue(const std::string path, const int32_t& value);
	bool setValue(const std::string path, const int64_t& value);

	bool setValue(const std::string path, const double& value);

	bool setValue(const std::string path, const std::string& value);

	bool setValue(const std::string path, const std::vector<uint8_t>& value);
	bool setValue(const std::string path, const std::vector<uint16_t>& value);
	bool setValue(const std::string path, const std::vector<uint32_t>& value);
	bool setValue(const std::string path, const std::vector<uint64_t>& value);

	bool setValue(const std::string path, const std::vector<int8_t>& value);
	bool setValue(const std::string path, const std::vector<int16_t>& value);
	bool setValue(const std::string path, const std::vector<int32_t>& value);
	bool setValue(const std::string path, const std::vector<int64_t>& value);

	bool setValue(const std::string path, const std::vector<double>& value);

	bool setValue(const std::string path, const std::vector<std::string>& value);

private:
	//Disallow Copy and Assign
	WriteOnlyConfiguration(WriteOnlyConfiguration const&); // Don't Implement
	void operator=(WriteOnlyConfiguration const&); // Don't implement
};

}

#endif /* CONFIG_WRITEONLYCONFIGURATION_H */
