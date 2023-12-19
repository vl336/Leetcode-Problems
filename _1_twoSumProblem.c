#include <stdlib.h>

//https://leetcode.com/problems/two-sum/
//17.12.23 - Vladislav Ershov

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int* returnArr = malloc(sizeof(int)*2);
    *returnSize = 2;
    for(int i = 0; i < numsSize; i++) {
        for(int j = 0; j < numsSize; j++) {
            if (j == i) continue;
            if (nums[i] + nums[j] == target) {
                returnArr[0] = i;
                returnArr[1] = j;
            }
        }
    }
    return returnArr;
}

int main() {
    return 0;
}