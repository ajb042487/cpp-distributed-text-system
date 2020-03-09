
#include <limits>
#include <cstdlib>
#include "utility/StringDeserializer.h"

namespace Utility
{
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-parameter"
	bool StringDeserializer::toNumeric (const std::string& haystack, uint8_t& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, uint16_t& value)
	{
		int32_t tmp = 0;
		tmp = atoi (haystack.c_str());
		if(std::numeric_limits<uint16_t>::min() <= tmp && std::numeric_limits<uint16_t>::max() >= tmp)
		{
			value = tmp;
			return true;
		}
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, uint32_t& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, uint64_t& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, int8_t& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, int16_t& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, int32_t& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, int64_t& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, float& value)
	{
		return false;
	}

	bool StringDeserializer::toNumeric (const std::string& haystack, double& value)
	{
		return false;
	}
#pragma GCC diagnostic pop
}