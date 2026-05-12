#include <memory>
#include <iostream>

#include "stock.h"

int main(int argc, char *argv[]) {
    using namespace stock_prices;

    auto asset {std::make_unique<Stock>("Apple", 100.0, 0.05)};
    std::cout << asset->get_name() << ":" << asset->next_price() << '\n';
}
