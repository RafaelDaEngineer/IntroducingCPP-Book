

#ifndef INTROTOCPPBOOK_INPUT_H
#define INTROTOCPPBOOK_INPUT_H
#include <expected>
#include <functional>
#include <istream>
#include <random>
#include <string>
#include <vector>

namespace stock_prices {
    std::expected<double, std::string> get_number(std::istream &input_stream);

    std::vector<double> get_prices(std::istream &input_stream, std::function<void()> prompt);

    std::vector<double> get_prices(double price, size_t count);

    std::vector<double> get_prices(double price, size_t count, double volatility,
                                   unsigned int seed = std::random_device{}());

    std::vector<double> get_prices(double price, size_t count, const std::function<double()> &next_price);

    std::vector<double> read_from_file(const std::string &filename);

    void test_input();
} // namespace stock_prices
#endif // INTROTOCPPBOOK_INPUT_H
