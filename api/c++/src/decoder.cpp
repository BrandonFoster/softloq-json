#include <softloq-json/precompile.hpp>
#include <softloq-json/decoder.hpp>
#include <softloq-common/character.hpp>

namespace softloq::json {

const bool parseMatch(std::string_view& json_segment, const std::string& match) {
    if(json_segment.substr(0, match.length()) == match) {
        json_segment = json_segment.substr(match.length());
        return true;
    }
    return false;
}

SOFTLOQ_JSON_API const Element* Decoder::decodeJSON(const std::string& json_string) {
    std::string_view json_segment = json_string;
    return nullptr;
}
SOFTLOQ_JSON_API const Object* Decoder::decodeObject(const std::string& json_string) {
    std::string_view json_segment = json_string;
    return nullptr;
}
SOFTLOQ_JSON_API const Array* Decoder::decodeArray(const std::string& json_string) {
    std::string_view json_segment = json_string;
    return nullptr;
}
SOFTLOQ_JSON_API const String* Decoder::decodeString(const std::string& json_string) {
    std::string_view json_segment = json_string;
    return nullptr;
}
SOFTLOQ_JSON_API const Number* Decoder::decodeNumber(const std::string& json_string) {
    std::string_view json_segment = json_string;
    std::unique_ptr<Element> json_number;
    parseWS(json_segment);
    if(!parseNumber(json_segment, json_number)) return nullptr;
    parseWS(json_segment);
    return json_segment.empty() ? nullptr : dynamic_cast<Number*>(json_number.release());
}
SOFTLOQ_JSON_API const Bool* Decoder::decodeBool(const std::string& json_string) {
    std::string_view json_segment = json_string;
    std::unique_ptr<Element> json_bool;
    parseWS(json_segment);
    if(!parseBool(json_segment, json_bool)) return nullptr;
    parseWS(json_segment);
    return json_segment.empty() ? nullptr : dynamic_cast<Bool*>(json_bool.release());
}
SOFTLOQ_JSON_API const Null* Decoder::decodeNull(const std::string& json_string) {
    std::string_view json_segment = json_string;
    std::unique_ptr<Element> json_null;
    parseWS(json_segment);
    if(!parseNull(json_segment, json_null)) return nullptr;
    parseWS(json_segment);
    return json_segment.empty() ? nullptr : dynamic_cast<Null*>(json_null.release());
}

SOFTLOQ_JSON_API const bool Decoder::parseValue(std::string_view& json_segment, std::unique_ptr<Element>& json_value) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseObject(std::string_view& json_segment, std::unique_ptr<Element>& json_object) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseMembers(std::string_view& json_segment, std::unique_ptr<Element>& json_object) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseMember(std::string_view& json_segment, std::unique_ptr<Element>& key, std::unique_ptr<Element>& json_value) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseArray(std::string_view& json_segment, std::unique_ptr<Element>& json_array) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseElements(std::string_view& json_segment, std::unique_ptr<Element>& json_array) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseElement(std::string_view& json_segment, std::unique_ptr<Element>& json_element) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseString(std::string_view& json_segment, std::unique_ptr<Element>& json_string) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseCharacters(std::string_view& json_segment, std::string& json_characters) {
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseNumber(std::string_view& json_segment, std::unique_ptr<Element>& json_number) {
    static const std::regex number_pattern("^([-])?(0|[1-9][0-9]*)(?:[.](0|[1-9][0-9]*))?(?:[Ee]([-+]?(?:0|[1-9][0-9]*)))?");
    std::cmatch matches;
    if(std::regex_search(json_segment.data(), matches, number_pattern)) {
        const float sign = (matches[1].matched ? -1.0f : 1.0f);
        const float integer = (matches[2].matched ? std::stof(matches[2].str()) : 0.0f);
        const float fractional = (matches[3].matched ? std::stof(std::string("0.") + matches[3].str()) : 0.0f);
        const float exponent = (matches[4].matched ? std::pow(10.0f, std::stof(matches[4].str())) : 1);
        json_segment = json_segment.substr(matches.length());
        json_number = std::unique_ptr<Element>(new Number(sign * (integer + fractional) * exponent));
        return true;
    }
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseBool(std::string_view& json_segment, std::unique_ptr<Element>& json_bool) {
    if(parseMatch(json_segment, "true")) {
        json_bool = std::unique_ptr<Element>(new Bool(true));
        return true;
    }
    else if(parseMatch(json_segment, "false")) {
        json_bool = std::unique_ptr<Element>(new Bool(false));
        return true;
    }
    return false;
}
SOFTLOQ_JSON_API const bool Decoder::parseNull(std::string_view& json_segment, std::unique_ptr<Element>& json_null) {
    if(parseMatch(json_segment, "null")) {
        json_null = std::unique_ptr<Element>(new Null);
        return true;
    }
    return false;
}
SOFTLOQ_JSON_API void Decoder::parseWS(std::string_view& json_segment) {
    while(!json_segment.empty()) switch(json_segment[0]) {
    case 0x20:
    case 0xA:
    case 0xD:
    case 0x9:
        json_segment = json_segment.substr(1);
        break;
    default: return;
    }
}

} // namespace softloq::json