class Solution:
    def twoSum(self, nums: list[int], target: int) -> list[int]:
        nums_len    = len(nums)

        sorted_nums = sorted(nums)

        l = 0
        r = nums_len - 1
        while l < r:
            if sorted_nums[l] + sorted_nums[r] > target:
                r = r - 1

            elif sorted_nums[l] + sorted_nums[r] < target:
                l = l + 1

            else: #solution found, get index
                result = []
                for i in range(nums_len):
                    if nums[i] == sorted_nums[l]:
                        result.append(i)
                        break

                for i in range(nums_len - 1, -1, -1):
                    if nums[i] == sorted_nums[r]:
                        result.append(i)
                        break

                return result
        
        return []

S = Solution()

nums = [15, 7, 11, 2]
target = 9

print(S.twoSum(nums, target))