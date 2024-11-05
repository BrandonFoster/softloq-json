#include <softloq-json/precompile.hpp>
#include <softloq-json/element.hpp>

namespace softloq::json {

SOFTLOQ_JSON_API const std::string Object::toString() const {
    std::string json_string = "{";
    for(const auto& item: *this) {
        if(json_string.length() > 1) json_string += ",";
        json_string += " ";
        json_string += "\"";
        json_string += item.first; // string key
        json_string += "\"";
        json_string += " : ";
        json_string += item.second->toString();
    }
    json_string += " }";
    return json_string;
}

SOFTLOQ_JSON_API const std::string Array::toString() const {
    std::string json_string = "[";
    for(const auto& value: *this) {
        if(json_string.length() > 1) json_string += ",";
        json_string += " ";
        json_string += value->toString();
    }
    json_string += " ]";
    return json_string;
}

SOFTLOQ_JSON_API String::String(): value() {}
SOFTLOQ_JSON_API String::String(const std::string& value): value(value) {}

SOFTLOQ_JSON_API Number::Number(): value(0.0f) {}
SOFTLOQ_JSON_API Number::Number(const float value): value(value) {}

SOFTLOQ_JSON_API Bool::Bool(): value(false) {}
SOFTLOQ_JSON_API Bool::Bool(const bool value): value(value) {}

} // namespace softloq::json