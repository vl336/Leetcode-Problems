#include <assert.h>
#include <stdlib.h>
#include <math.h>

// https://leetcode.com/problems/the-kth-factor-of-n/description/?envType=study-plan-v2&envId=amazon-spring-23-high-frequency
// 23.12.23 - Vladislav Ershov

int cmp (const void * a, const void * b) {
    return ( *(int*)a - *(int*)b );
}

void insert(int* arr, int val, int* filled, int* size) {
    if(*filled >= *size) {
        *size *= 2;
        arr = realloc(arr, (*size)*sizeof (int));
    }
    arr[*filled] = val;
    *filled += 1;
}

int kthFactor(int n, int k) {
    int size = 5;
    int* arr = malloc(size*sizeof (int));
    arr[0] = 1; arr[1] = n;
    int filled = 2;
    for (int i = 2; i <= pow(n, 0.5); ++i) {
        if(n % i == 0) {
            insert(arr, i,  &filled, &size);
            if((float)n/i != i) {
                insert(arr, n/i,  &filled, &size);
            }
        }
    }
    if(k > filled) return -1;
    qsort(arr, filled, sizeof (int), cmp);
    return arr[k-1];
}


#define TEST(n, k, exp) assert(exp == kthFactor(n,k))

int main() {
    TEST(12, 3, 3);
    TEST(7, 2, 7);
    TEST(4, 4, -1);
}