class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        s_length = len(s)

        #init length upperbound, starting from each char
        visit = {}
        len_ub = [float('inf')] * s_length
        for i in range(1, s_length + 1):
            if s[-i] in visit: #c is visited
                len_ub[-i] = i - visit[s[-i]]

            visit[s[-i]] = i

        #calculate maxLen
        maxLen = 0
        for i in range(s_length):
            if s_length - i < maxLen:
                break

            stepCount  = 0
            remainStep = float('inf')
            for j in range(i, s_length):
                if remainStep == 0:
                    break
                
                #update remainStep
                remainStep = min(remainStep - 1, len_ub[j] - 1)
                stepCount  = stepCount  + 1

            maxLen = max(maxLen, stepCount)
    
        return maxLen

S = Solution()

#input
s = "abcabcbb"

print(S.lengthOfLongestSubstring(s))