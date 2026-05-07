#include <iostream>
#include <ranges>
#include <vector>


int main() {
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