#include "common.h"
#include "string_int_7.1.h"
#include "test.h"
#include <math.h>

namespace StringInt
{
    static char digitToChar(int value);
    static int charToDigit(char character);
    
    char digitToChar(int value) {
        switch (value) {
            case 0: return '0';
            case 1: return '1';
            case 2: return '2';
            case 3: return '3';
            case 4: return '4';
            case 5: return '5';
            case 6: return '6';
            case 7: return '7';
            case 8: return '8';
            case 9: return '9';
            default: return 'x';
        }
    }
    
    int charToDigit(char character) {
        switch (character) {
            case '0': return 0;
            case '1': return 1;
            case '2': return 2;
            case '3': return 3;
            case '4': return 4;
            case '5': return 5;
            case '6': return 6;
            case '7': return 7;
            case '8': return 8;
            case '9': return 9;
            default: return 0;
        }
    }
    
    int stringToInt(const std::string& string) {
        int result = 0;
        int scaling = 1;
        for (int i = static_cast<int>(string.length()) - 1; i >= 0; i--) {
            char current_char = string[static_cast<size_t>(i)];
            if (current_char == '-') {
                result = result * -1;
            } else {
                result += charToDigit(current_char) * scaling;
                scaling *= 10;
            }
        }
        return result;
    }
    
    std::string intToString(int value) {
        std::string result;
        
        if (value == 0) {
            return "0";
        } else if (value < 0) {
            result += "-";
            value *= -1;
        }
        
        int digits = static_cast<int>(log10(value));
        for (int i = 0; i <= digits; i++) {
            int scaling = static_cast<int>(pow(10, (digits - i)));
            int most_significant_digit = value / scaling;
            
            result += digitToChar(most_significant_digit);
            value -= most_significant_digit * scaling;
        }
        
        return result;
    }
      
    void test() {
        TEST_EQ(342, stringToInt("342"));
        TEST_EQ(-1025000, stringToInt("-1025000"));
        TEST_EQ(-1, stringToInt("-1"));
        TEST_EQ(std::string("-987"), intToString(-987));
        TEST_EQ(std::string("0"), intToString(0));
        TEST_EQ(std::string("3"), intToString(3));
        TEST_EQ(std::string("1000000000"), intToString(1000000000));
    }
}
