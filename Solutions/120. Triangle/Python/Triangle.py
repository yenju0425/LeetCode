class Solution:
    def minimumTotal(self, triangle: list[list[int]]) -> int:
        depth = len(triangle)
        for i in range(1, depth):
            triangle[i][0] = triangle[i][0] + triangle[i - 1][0]
            for j in range(1, i):
                triangle[i][j] = triangle[i][j] + min(triangle[i - 1][j], triangle[i - 1][j - 1])
            
            triangle[i][i] = triangle[i][i] + triangle[i - 1][i - 1]

        result = triangle[depth - 1][0]
        for i in triangle[depth - 1][1:]:
            result = min(result, i)
            
        return result

S = Solution()

#input
triangle = [
    [2], 
    [3, 4],
    [6, 5, 7],
    [4, 1, 8, 3]
]

print(S.minimumTotal(triangle))