#include <iostream>
#include <utility>
#include <vector>

#include "stock.h"
int main(int argc, char *argv[]) {
    using namespace stock_prices;

    std::vector<Stock> stocks;
    stocks.push_back(Stock{"Coffee", 4.8, 0.0113});

    // Stock original_stock{"Apple", 100.0, 0.01};
    // Stock copy {original_stock};

    // Stock tea{"Tea", 1.0, 0.01};
    // Stock moved_tea{"Tea", 4.8, 0.1234};
    // moved_tea = std::move(tea);

    for (auto &stock: stocks) {
        std::cout << stock.get_name() << ": " << stock.next_price() << '\n';
    }
}
