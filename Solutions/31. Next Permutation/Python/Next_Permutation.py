class Solution:
    def nextPermutation(self, nums: list[int]) -> None:
        nums_size = len(nums)
        for i in range(nums_size - 1, 0, -1):
            if nums[i - 1] < nums[i]:
                nums[i:] = sorted(nums[i:])
                for j in range(i, nums_size):
                    if nums[j] > nums[i - 1]:
                        nums[j], nums[i - 1] = nums[i - 1], nums[j]
                        return nums

        return nums.reverse()

S = Solution()

#inputs
nums = [3, 2, 1]

S.nextPermutation(nums)

print(nums)