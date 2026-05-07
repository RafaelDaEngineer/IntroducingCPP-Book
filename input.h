

#ifndef INTROTOCPPBOOK_INPUT_H
#define INTROTOCPPBOOK_INPUT_H
#include <expected>
#include <functional>
#include <vector>
#include <string>
#include <istream>

namespace stock_prices {
    std::expected<double, std::string> get_number(std::istream& input_stream);
    std::vector<double> get_prices(std::istream& input_stream, std::function<void ()> prompt);

    void test_input();
}
#endif // INTROTOCPPBOOK_INPUT_H
