#include <string.h>
#include <assert.h>

//https://leetcode.com/problems/longest-substring-without-repeating-characters/
// 20.12 - Vladislav Ershov

#define MAX(a, b) a >= b ? a : b 

// return -1 if there was no match and index of symbol if match occurred 
int notIn(const char* s, int len, char sym) {
    for (int i = 0; i < len; ++i) {
        if (s[i] == sym) return i;
    }
    return -1;
}

int lengthOfLongestSubstring(char* s) {
    unsigned long len = strlen(s);
    int max = len == 0 ? 0 : 1;
    int startId = -1;
    int currentLen = 0;
    for (int i = 0; i < len; ++i) {
        if(startId == -1) {
            startId = i;
            currentLen = 1;
        }
        else {
            int match = notIn(&(s[startId]), currentLen, s[i]);
            if (match == -1) {
                currentLen++;
                max = MAX(max, currentLen);
            } else {
                i = match + startId + 1;
                startId += match + 1;
                currentLen = 1;
            }
        }
    }
    return max;
}

#define TEST(s, res) assert(lengthOfLongestSubstring(s) == res);

int main() {
    TEST("abcabcbb", 3);
    TEST("bbbbb", 1);
    TEST("pwwkew", 3);
    TEST("", 0);
    TEST("aab", 2);
    TEST("dvdf", 3);
}