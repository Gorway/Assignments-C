#include <stdio.h> // Boyer-Moore Algorithm

int majorityElement(int* nums, int numsSize) {
    int candidate = nums[0]; 
    int count = 1; 

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
            if (count == 0) {
                candidate = nums[i];
                count = 1;
            }
        }
    }

    count = 0;
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] == candidate) {
            count++;
        }
    }

    if (count > numsSize / 2) {
        return candidate;
    } else {
        return -1;
    }
}

int main() {
    int nums[] = {2, 3, 3, 3, 2, 3, 3};
    int numsSize = sizeof(nums) / sizeof(nums[0]);

    int result = majorityElement(nums, numsSize);

    if (result != -1) {
        printf("Majority element: %d\n", result);
    } else {
        printf("No majority element found\n");
    }

    return 0;
}

