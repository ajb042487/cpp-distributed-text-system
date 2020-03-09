
#include "utility/StringSerializer.h"

namespace Utility
{
	bool StringSerializer::toString (const uint8_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const uint16_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const uint32_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const uint64_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const int8_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const int16_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const int32_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const int64_t& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const float& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const double& haystack, std::string& value)
	{
		value = std::to_string(haystack);
		return true;
	}

	bool StringSerializer::toString (const std::string& haystack, std::string& value)
	{
		value = std::string(haystack);
		return true;
	}
}
