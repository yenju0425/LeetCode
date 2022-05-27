class Solution:
    def numberOfSteps(self, num: int) -> int:
        if num == 0:
            return 0
        else:
            return format(num, 'b').count('0') + format(num, 'b').count('1') * 2 - 1

S = Solution()

print(S.numberOfSteps(14))
