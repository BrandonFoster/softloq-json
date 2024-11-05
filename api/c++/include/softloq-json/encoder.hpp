#ifndef SOFTLOQ_JSON_ENCODER_HPP
#define SOFTLOQ_JSON_ENCODER_HPP

#include <softloq-json/element.hpp>

namespace softloq::json {

class SOFTLOQ_JSON_API Encoder {
public:
    const std::string Encode(Element* element);
};

} // namespace softloq::json

#endif