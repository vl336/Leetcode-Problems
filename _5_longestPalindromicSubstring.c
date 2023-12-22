#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

#define MAX(x,y) x > y ? x : y

bool isPalindrome(char* s, int len) {
    for (int i = 0; i < len / 2; ++i) {
        if(s[i] != s[len-i-1]) return false;
    }
    return true;
}

//char* longestPalindrome(char *s) {
//    int len = strlen(s);
//    char *retStart = NULL;
//    int retLen = -1;
//    for (int i = 0; i < len; ++i) {
//        for (int j = 1; j <= len - i; ++j) {
//            if (isPalindrome(&(s[i]), j)) {
//                if (j > retLen) {
//                    retLen = j;
//                    retStart = &(s[i]);
//                }
//            }
//        }
//    }
//    char *res = malloc(sizeof(char) * (retLen + 1));
//    res[retLen] = '\0';
//    for (int i = 0; i < retLen; ++i) {
//        res[i] = retStart[i];
//    }
//    return res;
//}


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
//    TEST("babad", "bab");
//    TEST("cbbd", "bb");
//    TEST("a", "a");
//    TEST("bb", "bb");
    TEST("ac", "a");
}