#include "analysis.h"
#include <algorithm>
#include <cassert>
#include <stdexcept>
#include <vector>
#include <numeric>

namespace stock_prices {
    std::vector<double> remove_invalid(std::vector<double> prices) {
        auto new_end = std::ranges::remove_if(prices, negative).begin();
        prices.erase(new_end, prices.end());
        return prices;
    }

    double average(const std::vector<double>& prices) {
        if (prices.empty())
            throw std::invalid_argument("Prices cannot be empty");

        return std::accumulate(prices.begin(), prices.end(), double{}) / prices.size();
    }

    void test_analysis() {
        auto got = remove_invalid({-1.2, 3.5});
        assert(got.size() == 1);
        assert(got[0] == 3.5);

        try {
            average({});
            assert(false);
        }
        catch (const std::exception& e) {
        }

        assert(average({1.0}) == 1.0);
    }
}