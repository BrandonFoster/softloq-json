#ifndef SOFTLOQ_JSON_ELEMENT_HPP
#define SOFTLOQ_JSON_ELEMENT_HPP

#include <string>
#include <softloq-json/definitions.hpp>

namespace softloq::json {

// JSON Elements are based on https://www.json.org

enum class ElementType { Object, Array, String, Number, Bool, Null };

class SOFTLOQ_JSON_API Element {
public:
    virtual const ElementType getElementType() const = 0;
    virtual const std::string toString() const = 0;
    template <class ELEMENT_TYPE> ELEMENT_TYPE* const as() { return dynamic_cast<ELEMENT_TYPE*>(this); }
};

class SOFTLOQ_JSON_API Object: public Element {
public:
    inline const ElementType getElementType() const override { return ElementType::Object; }
};

class SOFTLOQ_JSON_API Array: public Element {
public:
    inline const ElementType getElementType() const override { return ElementType::Array; }
};

class SOFTLOQ_JSON_API String: public Element {
public:
    inline const ElementType getElementType() const override { return ElementType::String; }
};

class SOFTLOQ_JSON_API Number: public Element {
public:
    inline const ElementType getElementType() const override { return ElementType::Number; }
};

class SOFTLOQ_JSON_API Bool: public Element {
public:
    inline const ElementType getElementType() const override { return ElementType::Bool; }
};

class SOFTLOQ_JSON_API Null: public Element{
public:
    inline const ElementType getElementType() const override { return ElementType::Null; }
};

} // namespace softloq::json

#endif