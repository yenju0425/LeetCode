class Solution:
    def sortArrayByParity(self, nums: list[int]) -> list[int]:
        return [e for e in nums if e % 2 == 0] + [o for o in nums if o % 2 != 0]

S = Solution()

List = [4, 2, 3, 1, 0]

print(S.sortArrayByParity(List))
