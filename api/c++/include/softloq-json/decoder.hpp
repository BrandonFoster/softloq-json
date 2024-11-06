#ifndef SOFTLOQ_JSON_DECODER_HPP
#define SOFTLOQ_JSON_DECODER_HPP

#include <softloq-json/element.hpp>

namespace softloq::json {

class SOFTLOQ_JSON_API Decoder {
public:
    const Element* decodeJSON(const std::string& json_string);
    const Object*  decodeObject(const std::string& json_string);
    const Array*   decodeArray(const std::string& json_string);
    const String*  decodeString(const std::string& json_string);
    const Number*  decodeNumber(const std::string& json_string);
    const Bool*    decodeBool(const std::string& json_string);
    const Null*    decodeNull(const std::string& json_string);

private:
    const bool parseValue(std::string_view& json_segment, std::unique_ptr<Element>& json_value);
    const bool parseObject(std::string_view& json_segment, std::unique_ptr<Element>& json_object);
    const bool parseMembers(std::string_view& json_segment, std::unique_ptr<Element>& json_object);
    const bool parseMember(std::string_view& json_segment, std::unique_ptr<Element>& key, std::unique_ptr<Element>& json_value);
    const bool parseArray(std::string_view& json_segment, std::unique_ptr<Element>& json_array);
    const bool parseElements(std::string_view& json_segment, std::unique_ptr<Element>& json_array);
    const bool parseElement(std::string_view& json_segment, std::unique_ptr<Element>& json_element);
    const bool parseString(std::string_view& json_segment, std::unique_ptr<Element>& json_string);
    const bool parseCharacters(std::string_view& json_segment, std::string& json_characters);
    const bool parseNumber(std::string_view& json_segment, std::unique_ptr<Element>& json_number);
    const bool parseBool(std::string_view& json_segment, std::unique_ptr<Element>& json_bool);
    const bool parseNull(std::string_view& json_segment, std::unique_ptr<Element>& json_null);
    void       parseWS(std::string_view& json_segment);
};

} // namespace softloq::json

#endif