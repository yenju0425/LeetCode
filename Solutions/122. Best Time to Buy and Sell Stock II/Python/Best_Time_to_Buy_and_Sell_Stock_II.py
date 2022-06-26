class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profitAfter_b = float('-inf')
        profitAfter_s = 0

        for p in prices:
            profitAfter_b = max(profitAfter_b, profitAfter_s - p)
            profitAfter_s = max(profitAfter_s, profitAfter_b + p)

        return profitAfter_s

S = Solution()

#input
prices = [7, 1, 5, 3, 6, 4]

print(S.maxProfit(prices))