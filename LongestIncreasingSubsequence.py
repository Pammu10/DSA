def lengthOfLIS(nums: list[int]) -> int:
    cache = [1] * len(nums)
    for i in range(len(nums) - 1, -1, -1):
        for j in range(i + 1, len(nums)):
            if (nums[j] > nums[i]):
                cache[i] = max(cache[i], 1 + cache[j])
    return max(cache)

nums = [10,9,2,5,3,7,101,18]

print(lengthOfLIS(nums=nums))

# Output 
# 4