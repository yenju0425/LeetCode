#Reference: https://docs.python.org/3/tutorial/classes.html

class Solution:
    def isPalindrome(self, x: int) -> bool: #"->" is an annotation to indicate the data type of the return value
        s = str(x)
        stringLength = len(s)

        for i in range(int(stringLength/2)):
            if s[i] != s[-1 - i]:
                return False

        return True

S = Solution()
print(S.isPalindrome(123))