from typing import List 
import bisect

class Solution:
    def fullBloomFlowers(self, flowers: List[List[int]], people: List[int]) -> List[int]:
        start = sorted([s for s, e in flowers])
        end = sorted([e for s, e in flowers])
        return [bisect.bisect_right(start, t) - bisect.bisect_left(end, t) for t in people]

S = Solution()

#input
flowers = [[1,6],[3,7],[9,12],[4,13]]
people = [2,3,7,11]

print(S.fullBloomFlowers(flowers, people))