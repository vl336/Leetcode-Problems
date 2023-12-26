#include <assert.h>

// https://leetcode.com/problems/palindrome-number/
// 26.12.23 - Vladislav Ershov

#include <stdbool.h>
#include <math.h>

#define BYTE char

bool isPalindrome(int x) {
    if(x < 0) return false;
    int n = x;
    BYTE places = 0;
    while (n > 0) {
        places++;
        n /= 10;
    }
    BYTE plc = places;
    places /= 2;
    for (int i = 0; i < places; ++i) {
        int power = (int)pow(10, plc-1);
        int a = x % 10;
        int b = x / power;
        x -= b * power;
        x -= a; x /= 10;
        plc -= 2;
        if(a != b)
            return false;
    }
    return true;
}

#define TEST(x, exp) assert(isPalindrome(x) == exp)

int main() {
    TEST(121, true);
    TEST(-121, false);
    TEST(10, false);
    TEST(1001, true);
    TEST(9999, true);
}