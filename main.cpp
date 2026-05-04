#include <iostream>
#include <istream>
#include <vector>
#include <algorithm>

#include "input.h"
#include "analysis.h"

std::vector<double> get_prices(std::istream& input_stream) {
    std::cout << "Please enter some numbers. \n>";
    std::vector<double> numbers{};
    auto number {stock_prices::get_number(input_stream)};
    while(number.has_value()) {
        numbers.push_back(number.value());
        std::cout << ">";
        number = stock_prices::get_number(input_stream);
    }
    return numbers;
}

int main() {
    stock_prices::test_analysis();
    auto prices = get_prices(std::cin);
    if (!prices.empty()) {
        auto result {std::ranges::minmax(prices)};
        std::cout << "min " << result.min << '\n';
        std::cout << "max " << result.max << '\n';
    }
    // auto invalid {std::ranges::count_if(prices, stock_prices::negative)};
    const auto erased {std::erase_if(prices, stock_prices::negative)};
    std::cout << erased << " prices below zero \n";

    std::cout << "Average " << stock_prices::average(prices) << '\n';

    std::ranges::sort(prices, std::ranges::greater{});
    for (const auto price : prices) {
        std::cout << price << '\n';
    }
}