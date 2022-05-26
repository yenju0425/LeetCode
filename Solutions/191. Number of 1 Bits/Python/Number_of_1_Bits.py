class Solution:
    def hammingWeight(self, n: int) -> int:
        counter = 0
        while bool(n):
            counter = counter + (n & 1)
            n = n >> 1

        return counter

S = Solution()

print(S.hammingWeight(26))