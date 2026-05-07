#ifndef INTROTOCPPBOOK_ANALYSIS_H
#define INTROTOCPPBOOK_ANALYSIS_H
#include <vector>

namespace stock_prices {
    inline bool negative(double value) {
        return value < 0.0;
    }
    std::vector<double> remove_invalid(std::vector<double> prices);
    void test_analysis();

    double average(const std::vector<double>& prices);

    double profit_on_first_uptick(const std::vector<double>& prices);

    bool required_profit_possible(const std::vector<double>& prices, double required_profit);
}

#endif // INTROTOCPPBOOK_ANALYSIS_H
