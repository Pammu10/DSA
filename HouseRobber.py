# Recursive memoized solution

# def rob(self, nums: List[int]) -> int:
#         memo = [-1 for i in range(len(nums))]
#         def dfs(i):
#             if i < 0:
#                 return 0
#             if memo[i] >= 0:
#                 return memo[i]
            
# Iterative memoizations solution

# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         memo = [-1] * (len(nums) + 1)
#         memo[0] = 0
#         memo[1] = nums[0]

#         for i in range(1, len(nums)):
#             val = nums[i]

# Iterative two variable memoization

# class Solution:
#     def rob(self, nums: List[int]) -> int:
#         if len(nums) == 0:
#             return 0
#         prev1 = 0
#         prev2 = 0
#         for num in nums:
#             tmp = prev1