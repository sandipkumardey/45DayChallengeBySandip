// Product of Array Except Self - No modulo support
public class ProductArrayExceptSelf {
    public int[] productExceptSelf(int[] nums) {
        int n = nums.length;
        int[] result = new int[n];
        int left = 1, right = 1;

        // Left products
        for (int i = 0; i < n; i++) {
            result[i] = left;
            left *= nums[i];
        }

        // Right products
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= right;
            right *= nums[i];
        }

        return result; // No modulo operation included
    }
}
