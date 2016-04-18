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
    
    double maximum_price2(const std::vector<double>& prices) {
        double maximum_price = 0.0;
        double min_price = std::numeric_limits<double>::max();
        for (double price : prices) {
            min_price = std::min(min_price, price);
            maximum_price = std::max(maximum_price, price - min_price);
        }
        
        return maximum_price;
    }
    
    int longest_subarray(const std::vector<int>& array) {
        if (array.empty()) {
            return 0;
        }
        
        auto current_value = array.at(0);
        int maximum_subarray_size = 0;
        int current_subarray_size = 0;
        for (auto element : array) {
            if (element != current_value) {
                current_subarray_size = 0;
                current_value = element;
            }
            maximum_subarray_size = std::max(maximum_subarray_size, ++current_subarray_size);
        }
        
        return maximum_subarray_size;
    }
    
    void test() {
        auto prices = std::vector<double> { 310, 315, 275, 295, 260, 270, 290, 230, 255, 250 };
        TEST_EQ(30.0, maximum_price(prices));
        TEST_EQ(30.0, maximum_price2(prices));
        
        auto elements = std::vector<int> { 0, 1, 1, 2, 3, 4, 4, 4, 3, 4 };
        TEST_EQ(3, longest_subarray(elements));
    }
}
