#ifndef INTROTOCPPBOOK_STOCK_H
#define INTROTOCPPBOOK_STOCK_H

#include <string>
#include <random>

namespace stock_prices {
    class Stock {
        // Private member variables
        std::string name{};
        double last_price{};
        double volatility{};
        std::default_random_engine gen{std::random_device{}()};
        std::normal_distribution<double> distrib{};

    public:
        // Declares constructor but does not define it
        Stock(const std::string &stock_name, double start_price, double start_volatility);

        // Defines get name function which is ok because it is a short function
        std::string get_name() const { return name; }

        // Declares next price function but does not define it
        double next_price();
    };
} // namespace stock_prices

#endif // INTROTOCPPBOOK_STOCK_H
