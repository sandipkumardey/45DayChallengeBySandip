# Top K Frequent Elements - Monolithic function
from collections import Counter
import heapq

def top_k_frequent(nums, k):
    count = Counter(nums)
    return [item for item, freq in heapq.nlargest(k, count.items(), key=lambda x: x[1])]

# Refactor into smaller helper functions
