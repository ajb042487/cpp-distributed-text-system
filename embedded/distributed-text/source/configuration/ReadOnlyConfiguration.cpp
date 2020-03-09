
#include <limits>
#include "rapidjson/document.h"
#include "rapidjson/filereadstream.h"
#include "config/ReadOnlyConfiguration.h"

namespace Config
{
	ReadOnlyConfiguration::ReadOnlyConfiguration()
	{
		_json = new rapidjson::Document;
	}

	ReadOnlyConfiguration::~ReadOnlyConfiguration()
	{
		delete _json;
	}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
	bool ReadOnlyConfiguration::readConfiguration(std::string configurationFile)
	{
		char buffer[4096] = {0};
		FILE* pFile = fopen(configurationFile.c_str(), "r");
		if(!pFile)
		{
			return false;
		}
		rapidjson::FileReadStream is(pFile, buffer, sizeof(buffer));
		_json->ParseStream<0>(is);
		fclose(pFile);
		return true;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, uint8_t& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, uint16_t& value)
	{
		uint32_t tmp = 0;
		rapidjson::Value::ConstMemberIterator itr = _json->FindMember(path.c_str());
		if (itr != _json->MemberEnd() && itr->value.IsUint())
		{
			tmp = itr->value.GetUint();
			if(std::numeric_limits<uint16_t>::min() <= tmp && std::numeric_limits<uint16_t>::max() >= tmp)
			{
				value = tmp;
				return true;
			}
		}
		return false;
	}
	
	bool ReadOnlyConfiguration::getValue(const std::string path, uint32_t& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, uint64_t& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, int8_t& value)
	{
		return false;
	}
	
	bool ReadOnlyConfiguration::getValue(const std::string path, int16_t& value)
	{
		return false;
	}
	
	bool ReadOnlyConfiguration::getValue(const std::string path, int32_t& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, int64_t& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, double& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::string& value)
	{
		rapidjson::Value::ConstMemberIterator itr = _json->FindMember(path.c_str());
		if (itr != _json->MemberEnd() && itr->value.IsString())
		{
			std::string tmpString(itr->value.GetString(), itr->value.GetStringLength());
			value = tmpString;
			return true;
		}
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<uint8_t>& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<uint16_t>& value)
	{
		return false;
	}
	
	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<uint32_t>& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<uint64_t>& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<int8_t>& value)
	{
		return false;
	}
	
	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<int16_t>& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<int32_t>& value)
	{
		return false;
	}
	
	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<int64_t>& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<double>& value)
	{
		return false;
	}

	bool ReadOnlyConfiguration::getValue(const std::string path, std::vector<std::string>& value)
	{
		return false;
	}
#pragma GCC diagnostic pop
}
