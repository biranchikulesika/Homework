#include <stdio.h>
#include <stdlib.h>

void sortArray(int* nums, int numsSize) {
    for(int i = 0; i < numsSize - 1; i++) {
        for(int j = 0; j < numsSize - 1 - i; j++) {
            if(nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int* sortedSquares(int* nums, int numsSize, int* returnSize) {
    *returnSize = numsSize;
    int *result = (int *)malloc(numsSize * sizeof(int));

    if (!result) {
        return NULL;
    }

    for(int i = 0; i < numsSize; i++) {
        result[i] = nums[i] * nums[i];
    }

    sortArray(result, numsSize);
    return result;
}

int main() {
    int nums[] = {-4, -1, 0, 3, 10};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* squaredSortedArray = sortedSquares(nums, numsSize, &returnSize);

    if (squaredSortedArray) {
        printf("Sorted Squared Array: ");
        for (int i = 0; i < returnSize; i++) {
            printf("%d ", squaredSortedArray[i]);
        }
        printf("\n");

        free(squaredSortedArray);
    } else {
        printf("Memory allocation failed.\n");
    }

    return 0;
}
