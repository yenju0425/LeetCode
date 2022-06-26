class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        profitAfter_b1 = float('-inf')
        profitAfter_s1 = 0
        profitAfter_b2 = float('-inf')
        profitAfter_s2 = 0

        for p in prices:
            profitAfter_b1 = max(profitAfter_b1,                - p)
            profitAfter_s1 = max(profitAfter_s1, profitAfter_b1 + p)
            profitAfter_b2 = max(profitAfter_b2, profitAfter_s1 - p)
            profitAfter_s2 = max(profitAfter_s2, profitAfter_b2 + p)

        return profitAfter_s2

S = Solution()

#input
prices = [3, 3, 5, 0, 0, 3, 1, 4]

print(S.maxProfit(prices))