#include <assert.h>
#include <stdlib.h>

// https://leetcode.com/problems/median-of-two-sorted-arrays/
// 21.12 - Vladislav Ershov

#define AVG(x, y) ((x+y) / 2.0)

int cmp(const void *a,const void *b) {
    return *((int*) a) - *((int*) b);
}

double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
    int size = nums2Size+nums1Size;
    int* merged = malloc(sizeof(int)*size);
    for (int i = 0; i < nums1Size; ++i) {
        merged[i] = nums1[i];
    }
    for (int i = 0; i < nums2Size; ++i) {
        merged[i+nums1Size] = nums2[i];
    }
    qsort(merged, size, sizeof(int), cmp);
    
    if(size % 2 != 0) {
        return merged[size/2];
    }
    else 
        return AVG(merged[size/2], merged[size/2-1]);
}


void TEST(int n1[], int n1s, int n2[], int n2s, double exp) {
    double act = findMedianSortedArrays(n1, n1s, n2, n2s);
    assert(exp == act);
} 

int main() {
    TEST((int[]){1, 3 }, 2, (int[]) { 2 }, 1, 2.0);
    TEST((int[]){1, 2 }, 2, (int[]) { 3, 4 }, 2, 2.5);
    TEST((int[]){ }, 0, (int[]) { 1 }, 1, 1);
    TEST((int[]){ 2, 3 }, 2, (int[]) { }, 0, 2.5);
    TEST((int[]){ }, 0, (int[]) { 2, 3 }, 2, 2.5);
    TEST((int[]){ 3 }, 1, (int[]) { -2, -1 }, 2, -1.0);
}