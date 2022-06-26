class Solution:
    def maxProfit(self, k: int, prices: list[int]) -> int:
        profitAfter_b = [float('-inf')] * (k + 1)
        profitAfter_s = [0] * (k + 1)

        for p in prices:
            for i in range(1, k + 1):
                profitAfter_b[i] = max(profitAfter_b[i], profitAfter_s[i - 1] - p)
                profitAfter_s[i] = max(profitAfter_s[i], profitAfter_b[i]     + p)

        return profitAfter_s[k]

S = Solution()

#inputs
k = 2
prices = [3, 2, 6, 5, 0, 3]

print(S.maxProfit(k, prices))