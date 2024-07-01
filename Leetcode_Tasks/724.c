#include <stdio.h> // ****** PIVOT INDEX ********

int pivotIndex(int nums[], int numsSize) {
    int totalSum = 0;
    int leftSum = 0;

    for (int i = 0; i < numsSize; i++) {
        totalSum += nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        if (leftSum == totalSum - leftSum - nums[i]) {
            return i;
        }
        leftSum += nums[i];
    }

    return -1;
}

int main() {
    int nums[] = {1, 7, 3, 6, 5, 6};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int pivot = pivotIndex(nums, numsSize);
    if (pivot != -1) {
        printf("Индекс опорного элемента: %d\n", pivot);
    } else {
        printf("Опорный элемент не найден.\n");
    }

    return 0;
}

