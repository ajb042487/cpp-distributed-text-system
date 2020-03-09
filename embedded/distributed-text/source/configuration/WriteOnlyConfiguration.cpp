#include "config/WriteOnlyConfiguration.h"

namespace Config
{
	WriteOnlyConfiguration::WriteOnlyConfiguration()
	{

	}

	WriteOnlyConfiguration::~WriteOnlyConfiguration()
	{

	}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
	bool WriteOnlyConfiguration::setValue(const std::string path, const uint8_t& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const uint16_t& value)
	{
		return false;
	}
	
	bool WriteOnlyConfiguration::setValue(const std::string path, const uint32_t& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const uint64_t& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const int8_t& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const int16_t& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const int32_t& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const int64_t& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const double& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const std::string& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<uint8_t>& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<uint16_t>& value)
	{
		return false;
	}
	
	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<uint32_t>& value)
	{
		return false;
	}
	
	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<uint64_t>& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<int8_t>& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<int16_t>& value)
	{
		return false;
	}
	
	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<int32_t>& value)
	{
		return false;
	}
	
	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<int64_t>& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<double>& value)
	{
		return false;
	}

	bool WriteOnlyConfiguration::setValue(const std::string path, const std::vector<std::string>& value)
	{
		return false;
	}
#pragma GCC diagnostic pop
}
