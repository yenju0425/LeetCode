class Solution:
    def findUnsortedSubarray(self, nums: list[int]) -> int:
        sizeof_nums = len(nums)

        find_min    = False
        minBaseLine = float('inf')
        for i in range(sizeof_nums):
            if i == sizeof_nums - 1 or nums[i + 1] < nums[i]:
                find_min = True

            if find_min:
                minBaseLine = min(minBaseLine, nums[i])

        find_max    = False
        maxBaseLine = float('-inf')
        for i in range(sizeof_nums - 1, -1, -1):
            if i == 0 or nums[i - 1] > nums[i]:
                find_max = True

            if find_max:
                maxBaseLine = max(maxBaseLine, nums[i])

        left  = -1
        for i in range(sizeof_nums):
            if (nums[i] > minBaseLine) and left == -1:
                left = i
                break

        right = -1
        for i in range(sizeof_nums - 1, -1, -1):
            if (nums[i] < maxBaseLine) and right == -1:
                right = i
                break

        return (right - left + 1) if (right - left + 1) != 1 else 0

S = Solution()

print(S.findUnsortedSubarray([1,2,3,2,3,3]))


        