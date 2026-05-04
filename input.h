

#ifndef INTROTOCPPBOOK_INPUT_H
#define INTROTOCPPBOOK_INPUT_H
#include <expected>
#include <string>
#include <istream>

namespace stock_prices {
    std::expected<double, std::string> get_number(std::istream& input_stream);
}
#endif // INTROTOCPPBOOK_INPUT_H
