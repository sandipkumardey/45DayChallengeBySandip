// Longest Increasing Subsequence - Only returns one subsequence
#include <vector>
using namespace std;

vector<int> lengthOfLIS(vector<int>& nums) {
    if (nums.empty()) return {};
    vector<int> lis(nums.size(), 1);
    vector<int> prev(nums.size(), -1);

    int maxLen = 1, maxIndex = 0;
    for (int i = 1; i < nums.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (nums[i] > nums[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j;
            }
        }
        if (lis[i] > maxLen) {
            maxLen = lis[i];
            maxIndex = i;
        }
    }

    vector<int> result;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        result.push_back(nums[i]);
        if (prev[i] == -1) break;
    }
    reverse(result.begin(), result.end());

    return result;  // Only returns one longest subsequence
}
