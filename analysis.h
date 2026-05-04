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
}

#endif // INTROTOCPPBOOK_ANALYSIS_H
