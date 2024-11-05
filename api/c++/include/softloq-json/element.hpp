#ifndef SOFTLOQ_JSON_ELEMENT_HPP
#define SOFTLOQ_JSON_ELEMENT_HPP

#include <softloq-json/definitions.hpp>

namespace softloq::json {
    
// JSON Elements are based on https://www.json.org

enum class ElementType { Object, Array, String, Number, Bool, Null };

class SOFTLOQ_JSON_API Element {};

class SOFTLOQ_JSON_API Object: public Element {};
class SOFTLOQ_JSON_API Array: public Element {};
class SOFTLOQ_JSON_API String: public Element {};
class SOFTLOQ_JSON_API Number: public Element {};
class SOFTLOQ_JSON_API Bool: public Element {};
class SOFTLOQ_JSON_API Null: public Element{};

} // namespace softloq::json

#endif