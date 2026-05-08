#include "input.h"
#include <cassert>
#include <limits>
#include <sstream>

#include <algorithm>
#include <random>


namespace stock_prices {
    std::expected<double, std::string> get_number(std::istream &input_stream) {
        double number{};
        input_stream >> number;
        if (input_stream) {
            return number;
        }
        input_stream.clear();
        input_stream.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        return std::unexpected{"That's not a number"};
    }

    std::vector<double> get_prices(std::istream &input_stream, std::function<void()> prompt) {
        std::vector<double> numbers{};
        prompt();
        auto number{stock_prices::get_number(input_stream)};
        while (number.has_value()) {
            numbers.push_back(number.value());
            prompt();
            number = stock_prices::get_number(input_stream);
        }
        return numbers;
    }

    std::vector<double> get_prices(double price, size_t count) {
        std::vector<double> prices(count);
        const double step{price / 100.0};

        std::random_device rd{};
        std::default_random_engine generator(rd());
        std::uniform_int_distribution distribution{-1, 1};

        auto next_price{[step, &price, &generator, &distribution]() {
            price += step * distribution(generator);
            return price;
        }};
        std::ranges::generate(prices.begin(), prices.end(), next_price);
        return prices;
    }

    std::vector<double> get_prices(double price, size_t count, double volatility, unsigned int seed) {
        std::vector<double> prices(count); // Generates a vector of size count type double

        std::default_random_engine gen{seed}; // Creates an engine to generate random numbers
        std::normal_distribution distrib; // Creates a standard random distribution

        auto next_price{[volatility, &price, &gen, &distrib]() {
            double percent{volatility * distrib(gen)}; // Picks an increment by which to change the price
            price += price * percent; // Add the increment times the price to the previous price
            return price;
        }};
        std::ranges::generate(prices.begin(), prices.end(), next_price); // Uses the lambda to generate prices
        return prices;
    }

    std::vector<double> get_prices(double price, const size_t count, const std::function<double()> &next_price) {
        std::vector<double> prices(count);
        prices.reserve(count);
        std::ranges::generate_n(std::back_inserter(prices), count, next_price);
        return prices;
    }

    void test_input() {
        std::stringstream no_input{" "};
        auto no_op{[]() {}};
        assert(get_prices(no_input, no_op).empty());

        std::stringstream some_input{"1"};
        assert(get_prices(some_input, no_op).size() == 1);
    }
} // namespace stock_prices
