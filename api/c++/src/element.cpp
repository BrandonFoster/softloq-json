#include <softloq-json/precompile.hpp>
#include <softloq-json/element.hpp>

namespace softloq::json {

String::String(): value() {}
String::String(const std::string& value): value(value) {}

Number::Number(): value(0.0f) {}
Number::Number(const float value): value(value) {}

Bool::Bool(): value(false) {}
Bool::Bool(const bool value): value(value) {}

} // namespace softloq::json