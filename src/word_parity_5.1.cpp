#include "common.h"
#include "word_parity_5.1.h"
#include "test.h"
#include <random>
#include <chrono>

template <typename T>
static bool has_odd_parity(T val) {
    bool odd = false;
    constexpr int size = sizeof(T) * 8;
    for (int i = 0; i < size; i++) {
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
        // Build lookup table
        std::vector<bool> lut;
        constexpr int chunk_size_bits = 16;
        unsigned int lut_range = (1 << chunk_size_bits) - 1;
        for (unsigned int i = 0; i <= lut_range; i++) {
            lut.push_back(has_odd_parity(i));
        }   
        
        bool odd_parity = false;
        // Count the bits in each word
        for (auto& word : words) {
            for (auto offset = 0; offset < 64; offset+= chunk_size_bits) {
                if (lut.at((word >> offset) & lut_range)) {
                    odd_parity = !odd_parity;
                }
            }
        }
        
        return odd_parity ? 1 : 0;
    }

    void test_parity() {
        TEST_EQ(1, compute_parity({0b1011}));
        TEST_EQ(0, compute_parity({0b10001000}));
        
        // Deterministic random numbers please- just need some test data
#ifdef PERFTEST
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
#endif
    }
}
