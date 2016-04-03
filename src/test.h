#pragma once

#define TEST_EQ(expected, actual) \
    Test::CheckEqual((expected), (actual), #actual, __FILE__, __LINE__);
    
namespace Test
{   
    void PrintFail(const std::string& expected, const std::string& actual, const std::string& check, const std::string& filename, int line);
    void PrintPass(const std::string& check, const std::string& filename, int line);
    
    template <typename T>
    void CheckEqual(const T& expected, const T& actual, const std::string& check, const std::string& filename, int line) {
        if (expected == actual) {
            PrintPass(check, filename, line);
        } else {
            std::stringstream expected_str;
            expected_str << expected;
            
            std::stringstream actual_str;
            actual_str << actual;
            
            PrintFail(expected_str.str(), actual_str.str(), check, filename, line);
        }
    }
}
