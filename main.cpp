#include <ranges>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <ios>
#include <random>

#include "analysis.h"
#include "input.h"

void views_experiment() {
    const std::vector prices {3.76, 1.5, -1.0, 3.0, 4.0, -2.0, 99.4};
    const double required_price {4.75};
    auto non_negative {[](double price) {return price >= 0.0;}};
    auto too_cheap {[required_price](double price) {return price < required_price;}};
    auto no_good {prices | std::ranges::views::filter(non_negative) | std::views::take_while(too_cheap)};
    std::cout << "Too cheap: \n";
    for (const double price : no_good) {
        std::cout << price << '\n';
    }
}

void random_experiment() {
    // CTAD class template argument deduction
    std::random_device rd {};
    std::default_random_engine generator{rd()};         // seed
    std::uniform_int_distribution distribution{1, 6}; // engine
    const int roll = distribution(generator);          // distribution
    std::cout << "You rolled a " << roll << '\n';
}

void literal_experiment() {
    auto as_float {0.1f + 0.2f};
    auto as_double {0.1 + 0.2};
    auto as_long_double {0.1L + 0.2L};
    auto as_int {1 + 2};
    auto as_long {1L + 2L};
    auto as_long_long {1LL + 2LL};

}

void trading_game() {
    const double start_price {100.0};
    std::cout << "Stock bought for: " << start_price << '\n';
    auto prices {stock_prices::get_prices(start_price, 10)};
    for (auto price : prices) {
        std::cout << "Current price: " << price << '\n';
        std::cout << "Press (s) to sell \n";
        char choice{};
        std::cin >> choice;
        if (choice == 's') {
            const double profit {price - start_price};
            std::cout << "Profit: " << profit << '\n';
            break;
        }
    }
    std::cout << "Game over \n";
}

int main() {

    // random_experiment();

    // stock_prices::test_analysis();

    stock_prices::test_input();

    // trading_game();




    std::random_device rd{};
    std::default_random_engine gen{rd()};
    std::normal_distribution distrib;

    double price{100.0};
    const double volatility{0.05};

    auto next_price{[volatility, &price, &gen, &distrib]() {
        double percent{volatility * distrib(gen)};
        price += price * percent;
        return price;
    }};

    const auto more_prices {stock_prices::get_prices(100.0, 10, next_price)};





    const auto prices {stock_prices::get_prices(100.0, 10, 0.05)};
    std::cout << "Got prices: \n";
    for (double price : prices) {
        std::cout << price << '\n';
    }

    // std::cout << "Please enter some numbers.\n";
    // auto prompt = [] (){std::cout << '>';};
    // auto prices = stock_prices::get_prices(std::cin, prompt);
    // std::cout << "Got " << prices.size() << " price(s).\n";

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