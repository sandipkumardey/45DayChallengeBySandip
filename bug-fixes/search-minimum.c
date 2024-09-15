// Search Minimum in Rotated Array - No duplicate handling
int findMin(int* nums, int numsSize) {
    int left = 0, right = numsSize - 1;
    while (left < right) {
        int mid = (left + right) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else if (nums[mid] < nums[right]) {
            right = mid;
        } else { // No handling for duplicates
            right--;
        }
    }
    return nums[left];
}
