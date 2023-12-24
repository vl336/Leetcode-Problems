#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

// https://leetcode.com/problems/longest-palindromic-substring/
// 22.12.23 - Vladislav Ershov


char* longestPalindrome(char *s) {
    int len = strlen(s);
    if(len == 1) return s;
    int retId = 0;
    int retLen = 1;
    for (int i = 0; i < len; ++i) {
        for (int j = 1; j <= i && j <= len-i; ++j) {
            if(s[i+j] != s[i-j]) break;
            if(j*2+1 > retLen)
            {
                retId = i-j;
                retLen = j*2+1;
            }
        }
        for (int j = 0; j < i+1 && j < len-i-1; ++j) {
            if(s[i-j] != s[i+j+1]) break;
            if((j+1)*2 > retLen)
            {
                retId = i-j;
                retLen = (j+1)*2 ;
            }
        }
    }
    char* res = malloc(sizeof(char) * (retLen + 1));
    memcpy(res, &(s[retId]), sizeof(char) * retLen);
    res[retLen] = '\0';
    return res;
}

#define TEST(s, exp) assert(strcmp(longestPalindrome(s), exp) == 0)

int main(){
    TEST("babad", "bab");
    TEST("cbbd", "bb");
    TEST("a", "a");
    TEST("bb", "bb");
    TEST("ac", "a");
}