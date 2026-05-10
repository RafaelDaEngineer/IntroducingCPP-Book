#include <ostream>


#include "../input.h"

int main() {
    const auto prices = stock_prices::get_prices(100.0, 10, 0.05);
    for (auto price: prices) {
        std::println("{:.2f}", price);
        std::string display_price{std::format(":.2f", price)};
    }
    std::println(" {} {} ", 1, 2);
    std::println(" {0:} {1:} ", 1, 2);
    std::println(" {1:} {0:} ", 1, 2);
    std::println(" {1:} {1:} ", 1, 2);

}
