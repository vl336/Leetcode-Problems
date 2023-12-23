#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

// https://leetcode.com/problems/zigzag-conversion/
// 23.12.23 - Vladislav Ershov

char* convert(char* s, int numRows) {
    int len = strlen(s);
    if(len == 1 || numRows == 1) return s;
    printf("%i", len);
    char* ret = malloc((len+1) * sizeof (char));
    char** rows = malloc(sizeof (char*) * numRows);

    int n = (len/numRows)+1;
    int rowLen = (n+(n-1)*(numRows-1))*20;
    
    for (int i = 0; i < numRows; ++i) {
        rows[i] = malloc(sizeof (char) * rowLen);
        memset(rows[i], '0', rowLen*sizeof (char));
    }

    int cr = 0; int cc = 0; bool goingBack = false;
    for (int i = 0; i < len; ++i) {
        printf("[%i,%i] %c\n", cr, cc, s[i]);
        rows[cr][cc] = s[i];
        if(goingBack) {
            cr--; cc++;
            if(cr == 0) goingBack = false;
        }
        else {
            cr++;
            if(cr == numRows-1) {
                goingBack = true;
            }
        }
    }

    int c = 0;
    for (int j = 0; j < numRows; ++j) {
        for (int i = 0; i < rowLen; ++i) {
            if(rows[j][i] == '0') continue;
            ret[c] = rows[j][i];
            c++;
        }
    }
    ret[len] = '\0';
    return ret;
}


#define TEST(s, n, exp) assert(strcmp(convert(s, n), exp) == 0)

int main() {
//   TEST("PAYPALISHIRING", 3, "PAHNAPLSIIGYIR");
//   TEST("PAYPALISHIRING", 7, "PNAIGYRPIAHLSI");
//   TEST("A", 3, "A");
//   TEST("AB", 1, "AB");
   TEST("AB", 3, "AB");
}