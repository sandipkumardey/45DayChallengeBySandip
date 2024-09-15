# Subarray Sum - Missing edge cases
def subarray_sum(nums, k):
    count, total = 0, 0
    prefix_sum = {0: 1}

    for num in nums:
        total += num
        if total - k in prefix_sum:
            count += prefix_sum[total - k]
        prefix_sum[total] = prefix_sum.get(total, 0) + 1

    return count  # Edge cases like negative sums not tested
