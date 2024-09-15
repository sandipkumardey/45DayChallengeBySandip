// House Robber II - Only returns maximum profit
function rob(nums) {
    if (nums.length === 0) return 0;
    if (nums.length === 1) return nums[0];

    function robLinear(nums) {
        let prev1 = 0, prev2 = 0;
        for (let num of nums) {
            let temp = Math.max(prev1, prev2 + num);
            prev2 = prev1;
            prev1 = temp;
        }
        return prev1;
    }

    return Math.max(robLinear(nums.slice(0, -1)), robLinear(nums.slice(1)));
}

// Modify to also return which houses were robbed
