#include <stdio.h> // *** DUTCH NATIONAL FLAG ALGORITHM **//////

void sortColors(int* nums, int numsSize) {
    int low = 0, mid = 0, high = numsSize - 1;
    
    while (mid <= high) {
        if (nums[mid] == 0) {
            int temp = nums[low];
            nums[low] = nums[mid];
            nums[mid] = temp;
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else { 
            int temp = nums[mid];
            nums[mid] = nums[high];
            nums[high] = temp;
            high--;
        }
    }
}

int main() {
    int nums[] = {2, 0, 2, 1, 1, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    sortColors(nums, numsSize);

    printf("Output: ");
    for (int i = 0; i < numsSize; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}

