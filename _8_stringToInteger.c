#include <assert.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>
#include <limits.h>

// https://leetcode.com/problems/string-to-integer-atoi/
// 25.12.23 - Vladislav Ershov

#define INT_MAX_DIV_10 214748364 // INT_MAX / 10
#define INT_MAX_PLACE_NUMBER_M1 100000000

int myAtoi(char* s) {
    int len = strlen(s);
    if(len > 0) {
        if (isalpha(s[0])) return 0;
    }
    int res = 0;
    bool negative = false;
    bool marked = false;
    bool started = false;

    for (int i = 0; i < len; ++i) {
        if(s[i] == ' ' && !started && !marked) continue;
        if(isdigit(s[i])) {
            started = true;
            if(s[i] =='0' && res == 0) {
                continue;
            }
            int dgt = ((int)s[i]-48);
            if (res > INT_MAX_DIV_10)
                return negative ? INT_MIN : INT_MAX;
            if(res == INT_MAX_DIV_10) {
                if (dgt > 7 || res / INT_MAX_PLACE_NUMBER_M1 > 2)
                    return negative ? INT_MIN : INT_MAX;
            }
            res *= 10;
            res += dgt;
        }
        else {
            if(s[i] == '-') {
                if(started) break;
                if(marked) break;
                negative = !negative;
                marked = true;
            }
            else if(s[i] == '+') {
                if(started) break;
                if(marked) return 0;
                marked = true;
            }
            else {
                break;
            }
        }
    }

    if(negative) res *= -1;
    return res;
}

#define TEST(s, exp) assert(myAtoi(s) == exp)

int main() {
    TEST("42", 42);
    TEST("   -42", -42);
    TEST("4193 with words", 4193);   
    TEST("words and 987", 0);   
    TEST("-91283472332", -2147483648);   
    TEST("3.14159", 3);   
    TEST("+-12", 0);   
    TEST("00000-42a1234", 0);   
    TEST("  0000000000012345678", 12345678);   
    TEST("21474836460", 2147483647);   
    TEST("  -0012a42", -12);   
    TEST("   +0 123", 0);   
    TEST(".1", 0);   
    TEST("-2147483647", -2147483647);
    TEST("2147483646", 2147483646);   
    TEST("21474836460", INT_MAX);   
    TEST("-91283472332", INT_MIN);   
    TEST("-5--", -5);   
    TEST("123-", 123);
    TEST("  +  413", 0);
}
