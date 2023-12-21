#include <assert.h>
#include <stdlib.h>

// https://leetcode.com/problems/median-of-two-sorted-arrays/
// 21.12 - Vladislav Ershov

#define MAX(x, y) x < y ? y : x
#define MINBYREF(x, y) *x > *y ? y : x
#define MAXBYREF(x, y) *x < *y ? y : x
#define MIN(x, y) x > y ? y : x
#define AVG(x, y) ((x+y) / 2.0)

//double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
//    int mergedSize = (nums1Size + nums2Size);
//    bool odd = mergedSize % 2 != 0;
//    int finish = mergedSize / 2 + (odd ? 0 : -1);
//
//    int* medianCells[2] = {nums1Size > 0 ? &nums1[0] : NULL,
//                           nums2Size > 0 ? &nums2[0] : NULL };
//    bool lastCell = true;
//    
//    int i = 0, j = 0;
//    while(i + j != finish ) {
//        int* res = NULL;
//        if((nums1[i] < nums2[j] || j == nums2Size - 1) && i != nums1Size - 1) {
//            i++;
//            res = &nums1[i];
//        }
//        else {
//            j++;
//            res = &nums2[j];
//        }
//        lastCell = !lastCell;
//        medianCells[lastCell] = res;
//    }
//    if(i == 0 && j == 0) {
//        if (medianCells[0] == NULL && nums2Size > 1)
//            medianCells[0] = &nums2[1];
//        if (medianCells[1] == NULL && nums1Size > 1)
//            medianCells[1] = &nums1[1];
//    }
//    if(odd) { //odd number of elements
//        if (medianCells[0] == NULL)
//            return *(medianCells[1]);
//        else if(medianCells[1] == NULL)
//            return *(medianCells[0]);
//        return MIN(*(medianCells[0]), *(medianCells[1])); //medianCells[lastCell];
//    }
//    else // even number of elements
//        return AVG(*(medianCells[0]), *(medianCells[1]));
//}

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