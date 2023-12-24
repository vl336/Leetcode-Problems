#include <assert.h>
#include <limits.h>
#include <stdbool.h>

// https://leetcode.com/problems/reverse-integer/
// 24.12.23 - Vladislav Ershov

int reverse(int x) {
    int res = 0;
    bool negative = x < 0;
    if (negative) {
        if(x == INT_MIN) return 0;
        x *= -1;  
    } 
    while(x > 0) {
        if(res >= INT_MAX / 10 + 1)
            return 0;
        res *= 10;
        res += x % 10;
        x /= 10;
    }
    if(negative) res *= -1;
    return res;
}

#define TEST(n, exp) assert(exp == reverse(n))

int main() {
    TEST(123, 321);
    TEST(-123, -321);
    TEST(120, 21);
    TEST(1534236469, 0);
    TEST(-2147483648, 0);
    TEST(1463847412, 2147483641);
}