#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int* result = (int*)malloc(2 * sizeof(int));

    for (int i = numsSize - 1; i >= 0; --i) {
        for (int j = i + 1; j < numsSize; ++j) {
            if (nums[i] + nums[j] == target) {
                result[0] = i;
                result[1] = j;
                return result;
            }
        }
    }

    result[0] = -1;
    result[1] = -1;

    return result;
}

int main() {
    int target = 13;
    int nums[] = {2, 7, 11, 15};

    int returnSize = 0;
    int* result    = twoSum(nums, 4, target, &returnSize);

    for (int i = 0; i < returnSize; ++i) {
        printf("%d ", result[i]);
    }

    free(result);

    return 0;
}
