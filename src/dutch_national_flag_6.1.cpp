#include "common.h"
#include "dutch_national_flag_6.1.h"
#include "test.h"

namespace Flag
{
    std::vector<int> Partition(const std::vector<int>& input_elements, unsigned int partition_index) {
        std::vector<int> result = input_elements;
        
        unsigned int current = 0;
        unsigned int write_low = 0;
        unsigned int write_high = static_cast<unsigned int>(result.size()) - 1;
        int pivot_value = result.at(partition_index);
        
        while (current < write_high) {
            const auto current_value = result.at(current);
            if (current_value > pivot_value) {
                std::swap(result[current], result[write_high]);
                write_high--;
            } else if (current_value < pivot_value) {
                if (current != write_low) {
                    result[write_low] = result[current]; 
                }
                write_low++;
                current++;
            } else {
                current++;
            }
        }
        
        for (auto i = write_low; i < write_high; i++) {
            result[i] = pivot_value;
        }
        
        return result;
    }
    
    std::vector<int> Partition4(const std::vector<int>& input_elements) {
        std::vector<int> result = input_elements;
        unsigned int next[4] = { 0, 0, 0, static_cast<unsigned int>(result.size()) };
        unsigned int current = 0;

        while (current < next[3]) {
            std::cout << "{ ";
            for (auto elem : result) {
                std::cout << elem << ", ";
            }
            std::cout << "}" << std::endl;
            std::cout << "next[0]: " << next[0] << std::endl;
            std::cout << "next[1]: " << next[1] << std::endl;
            std::cout << "next[2]: " << next[2] << std::endl;
            std::cout << "next[3]: " << next[3] << std::endl;
            std::cout << "current: " << current << std::endl;
        
            const auto value = result.at(current);
            if (value == 0 && current == next[0]) {
                current++;
                next[0]++;
                next[1] = std::max(next[0], next[1]);
                next[2] = std::max(next[0], next[2]);
            } else if (value == 1 && current == next[1]) {
                current++;
                next[1]++;
                next[2] = std::max(next[1], next[2]);
            } else if (value == 2 && current == next[2]) {
                current++;
                next[2]++;
            } else if (value == 0 && current != next[0]) {
                std::swap(result[current], result[next[0]]);
                next[0]++;
                next[1] = std::max(next[0], next[1]);
                next[2] = std::max(next[0], next[2]);
            } else if (value == 1 && current != next[1]) {
                std::swap(result[current], result[next[1]]);
                next[1]++;
                next[2] = std::max(next[1], next[2]);
            } else if (value == 2) {
                std::swap(result[current], result[next[2]]);
                next[2]++;
            } else if (value == 3) {
                std::swap(result[current], result[--next[3]]);
            }
        }
        std::cout << "{ ";
        for (auto elem : result) {
            std::cout << elem << ", ";
        }
        std::cout << "}" << std::endl;
        std::cout << "next[0]: " << next[0] << std::endl;
        std::cout << "next[1]: " << next[1] << std::endl;
        std::cout << "next[2]: " << next[2] << std::endl;
        std::cout << "next[3]: " << next[3] << std::endl;
        std::cout << "current: " << current << std::endl;
            
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
    }
    
    void test4() {
        const std::vector<int> input = { 0, 0, 1, 1, 1, 2, 3, 1, 2, 2, 3, 0, 0, 3, 0, 1, 2, 3, 0, 3 };
        auto result = Partition4(input);
        
        TEST_EQ(input.size(), result.size());
        
        auto it = result.begin();
        int count = 0;
        for (auto val : {0, 1, 2, 3}) {
            while ((*it) == val) {
                count++;
                it++;
            }
        }
        TEST_EQ(static_cast<int>(result.size()), count);
        
        std::cout << "{ ";
        for (auto elem : result) {
            std::cout << elem << ", ";
        }
        std::cout << "}" << std::endl;
    }
}
