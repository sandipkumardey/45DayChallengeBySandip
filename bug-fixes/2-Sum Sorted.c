int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int left = 0, right = numsSize - 1;

    while (left < right) {
        int sum = nums[left] + nums[right];

        // Check if sum matches target
        if (sum == target) {
            int* result = (int*)malloc(2 * sizeof(int));

            // Correct indexing - assuming problem requires 1-based indexing
            result[0] = left + 1; // convert 0-based index to 1-based
            result[1] = right + 1; // convert 0-based index to 1-based

            *returnSize = 2;
            return result;

        } else if (sum < target) {
            left++;  // Move left pointer to the right
        } else {
            right--; // Move right pointer to the left
        }
    }

    // No solution found
    *returnSize = 0;
    return NULL;
}
