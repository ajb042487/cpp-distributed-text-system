#ifndef UTILITY_STRINGDESERIALIZER_H
#define UTILITY_STRINGDESERIALIZER_H

#include <string>

namespace Utility
{

class StringDeserializer
{
public:
	static bool toNumeric (const std::string& haystack, uint8_t& value);
	static bool toNumeric (const std::string& haystack, uint16_t& value);
	static bool toNumeric (const std::string& haystack, uint32_t& value);
	static bool toNumeric (const std::string& haystack, uint64_t& value);

	static bool toNumeric (const std::string& haystack, int8_t& value);
	static bool toNumeric (const std::string& haystack, int16_t& value);
	static bool toNumeric (const std::string& haystack, int32_t& value);
	static bool toNumeric (const std::string& haystack, int64_t& value);

	static bool toNumeric (const std::string& haystack, float& value);
	static bool toNumeric (const std::string& haystack, double& value);
private:
	StringDeserializer(){};
};

}

#endif /* UTILITY_STRINGDESERIALIZER_H */
