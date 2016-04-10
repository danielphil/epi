#include "common.h"
#include "stock_price_6.7.h"
#include "test.h"

namespace Stock
{
    double maximum_price(const std::vector<double>& prices) {
        double maximum_price = 0.0; 
        for (size_t start = 0; start < prices.size() - 1; start++) {
            for (size_t end = start + 1; end < prices.size(); end++) {
                maximum_price = std::max(prices[end] - prices[start], maximum_price);
            }
        }
        return maximum_price;
    }
    
    void test() {
        auto prices = std::vector<double> { 310, 315, 275, 295, 260, 270, 290, 230, 255, 250 };
        TEST_EQ(30.0, maximum_price(prices));
    }
}
