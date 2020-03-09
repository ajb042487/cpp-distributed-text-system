#ifndef UTILITY_STRINGSERIALIZER_H
#define UTILITY_STRINGSERIALIZER_H

#include <string>

namespace Utility
{

class StringSerializer
{
public:
	static bool toString (const uint8_t& haystack, std::string& value);
	static bool toString (const uint16_t& haystack, std::string& value);
	static bool toString (const uint32_t& haystack, std::string& value);
	static bool toString (const uint64_t& haystack, std::string& value);
	static bool toString (const int8_t& haystack, std::string& value);
	static bool toString (const int16_t& haystack, std::string& value);
	static bool toString (const int32_t& haystack, std::string& value);
	static bool toString (const int64_t& haystack, std::string& value);
	static bool toString (const float& haystack, std::string& value);
	static bool toString (const double& haystack, std::string& value);
	static bool toString (const std::string& haystack, std::string& value);
private:
	StringSerializer(){};
};

}

#endif /* UTILITY_STRINGSERIALIZER_H */
