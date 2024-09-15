// 2-Sum Sorted - Off-by-one error
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            int* result = (int*)malloc(2 * sizeof(int));
            result[0] = left + 1; // Error: Off-by-one issue
            result[1] = right + 1;
            *returnSize = 2;
            return result;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    *returnSize = 0;
    return NULL;
}
