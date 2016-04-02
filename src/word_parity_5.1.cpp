#include "common.h"
#include "word_parity_5.1.h"
#include "test.h"
#include <random>
#include <chrono>

static bool has_odd_parity(uint64_t val);

bool has_odd_parity(uint64_t val) {
    bool odd = false;
    for (int i = 0; i < 64; i++) {
        if ((val & 1) == 1) {
            odd = !odd;
        }
        val >>= 1;
    }
    return odd;
}

namespace Parity
{
    int compute_parity(const std::vector<uint64_t>& words) {
        bool odd_parity = false;
        // Count the bits in each word
        for (auto& word : words) {
            if (has_odd_parity(word)) {
                odd_parity = !odd_parity;
            } 
        }
        
        return odd_parity ? 1 : 0;
    }

    void test_parity() {
        TEST_EQ(1, compute_parity({0b1011}));
        TEST_EQ(0, compute_parity({0b10001000}));
        
        // Deterministic random numbers please- just need some test data
        std::mt19937 gen(0);
        std::uniform_int_distribution<uint64_t> dis;
        
        std::vector<uint64_t> test_data;
        for (int i = 0; i < 1024 * 1024 * 30; i++) {
            test_data.push_back(dis(gen));
        }
        auto start = std::chrono::steady_clock::now();
        TEST_EQ(0, compute_parity(test_data));
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::steady_clock::now() - start);
        std::cout << "Time taken: " << duration.count() << "ms" << std::endl;
    }
}
