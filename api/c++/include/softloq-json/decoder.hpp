#ifndef SOFTLOQ_JSON_DECODER_HPP
#define SOFTLOQ_JSON_DECODER_HPP

#include <string>
#include <softloq-json/element.hpp>

namespace softloq::json {

class SOFTLOQ_JSON_API Decoder {
public:
    const Element* Decode(const std::string);
};

} // namespace softloq::json

#endif