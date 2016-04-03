#include "common.h"
#include "dutch_national_flag_6.1.h"
#include "test.h"

namespace Flag
{
    std::vector<int> Partition(const std::vector<int>& input_elements, unsigned int partition_index) {
        std::vector<int> result(input_elements.size());
        
        unsigned int lower_pos = 0;
        unsigned int upper_pos = static_cast<unsigned int>(input_elements.size()) - 1;
        
        const auto partition_value = input_elements.at(partition_index);
        for (int value : input_elements) {
            if (value < partition_value) {
                result[lower_pos] = value;
                lower_pos++;
            } else if (value > partition_value) {
                result[upper_pos] = value;
                upper_pos--;
            }
            // Ignore the case where value == partition. Will fill that in later
        }
        
        // Fill in remaining elements with the pivot value
        for (unsigned int i = lower_pos; i <= upper_pos; i++) {
            result[i] = partition_value;
        }
        
        return result;
    }
    
    void test() {
        const std::vector<int> input = { 1, 100, 12, 19, 2, 33, 45, 78, -1, 19 };
        const int pivot_index = 3;
        const int pivot_value = input[pivot_index];
        auto result = Partition(input, pivot_index);
        
        TEST_EQ(input.size(), result.size());
        
        int before_pivot = 0;
        int pivot = 0;
        int after_pivot = 0;
        
        auto it = result.begin();
        while (it != result.end()) {
            // Values less than pivot
            if ((*it) == pivot_value) {
                break;
            }
            it++;
            before_pivot++;
        }
        TEST_EQ(4, before_pivot);
        
        while (it != result.end()) {
            // Pivot values
            if ((*it) > pivot_value) {
                break;
            }
            it++;
            pivot++;
        }
        TEST_EQ(2, pivot);
        
        while (it != result.end()) {
            // Values greater than pivot
            it++;
            after_pivot++;
        }
        TEST_EQ(4, after_pivot);
        
        std::cout << "{ ";
        for (auto elem : result) {
            std::cout << elem << ", ";
        }
        std::cout << "}" << std::endl;
    }
}
