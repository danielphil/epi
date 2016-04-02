#include "common.h"
#include "test.h"

namespace Test
{
    void PrintFail(const std::string& expected, const std::string& actual, const std::string& check, const std::string& filename, int line) {
        std::stringstream location;
        location << filename << ":" << line << " " << check;
        std::cout << "\033[1;31mFailed:\033[0m " << location.str() << std::endl;
        std::cout << '\t' << "Expected: " << expected << std::endl;
        std::cout << '\t' << "Actual: " << actual << std::endl;
    }
    
    void PrintPass(const std::string& check, const std::string& filename, int line) {
        std::stringstream location;
        location << filename << ":" << line << " " << check;
        std::cout << "\033[1;32mPassed:\033[0m " << location.str() << std::endl;
    }
}
