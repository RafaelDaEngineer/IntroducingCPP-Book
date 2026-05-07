#include <ranges>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <ios>

#include "analysis.h"
#include "input.h"



int main() {
    stock_prices::test_analysis();

    stock_prices::test_input();

    std::cout << "Please enter some numbers.\n";
    auto prompt = [] (){std::cout << '>';};
    auto prices = stock_prices::get_prices(std::cin, prompt);
    std::cout << "Got " << prices.size() << " price(s).\n";

    std::cout << "The following are valid: \n";
    auto valid_prices {std::ranges::views::filter(prices, [](double p){return p >= 0.0;})};

    for (const double price: valid_prices) {
        std::cout << price << "\n";
    }

    const auto valid_prices_as_vector = std::ranges::to<std::vector>(valid_prices);
    const double mean = stock_prices::average(valid_prices_as_vector);
    std::cout << "With average " << mean << "\n";

    double potential_profit = stock_prices::profit_on_first_uptick(valid_prices_as_vector);
    std::cout << "Potential profit " << potential_profit << "\n";

    const double required_profit = 2.0;
    bool possible {stock_prices::required_profit_possible(valid_prices_as_vector, required_profit)};
    std::cout << "Required profit possible " << std::boolalpha << possible << "\n";

    // if (!prices.empty()) {
    //     auto result {std::ranges::minmax(prices)};
    //     std::cout << "min " << result.min << '\n';
    //     std::cout << "max " << result.max << '\n';
    // }

    // auto invalid {std::ranges::count_if(prices, stock_prices::negative)};


    // every lambda has unique type

    // auto lambda{[](const double value){return value < 0.0;}};
    // const auto erased {std::erase_if(prices, lambda)};
    // std::cout << erased << " prices below zero \n";
    //
    // std::cout << "Average " << stock_prices::average(prices) << '\n';
    //
    // std::ranges::sort(prices, std::ranges::greater{});
    // for (const auto price : prices) {
    //     std::cout << price << '\n';
    // }
}