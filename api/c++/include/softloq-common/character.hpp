#ifndef SOFTLOQ_COMMON_CHARACTER_HPP
#define SOFTLOQ_COMMON_CHARACTER_HPP

#include <string>
#include <softloq-json/definitions.hpp>

#define SOFTLOQ_UTF8_LAST_CODEPOINT 0x10FFFF

namespace softloq::character {

SOFTLOQ_JSON_API const bool convertUTF8ToCode(const std::string_view& utf8, char32_t& code, size_t& byte_count);
SOFTLOQ_JSON_API const bool convertCodeToUTF8(const char32_t code, std::string& utf8);

} // softloq::character

#endif