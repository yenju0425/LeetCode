class Solution:
    def myAtoi(self, s: str) -> int:
        """
            state = 0: terminate
            state = 1: wait
            state = 2: read
        """
        state = 1
        stringLength = len(s)
        reader = 0
        signBit = 1
        number = 0

        while state and reader < stringLength: #do while not in terminate state (state = 0)
            character = s[reader]

            if state == 1:
                if character == ' ':
                    state = 1

                elif character == '+' or character == '-':
                    state = 2
                    if character == '-':
                        signBit = -1

                elif character >= '0' and character <= '9':
                    state = 2
                    number = int(character)
                
                else:
                    state = 0

            elif state == 2:
                if character >= '0' and character <= '9':
                    state = 2
                    number = number * 10 + int(character)
                
                else:
                    state = 0

            else:
                print("error")

            reader = reader + 1


        #int in python will never overflow, thus we can calculate the final resault afterwards
        number = signBit * number

        if number > 2147483647:
            number = 2147483647
        elif number < -2147483648:
            number = -2147483648

        return number

S = Solution()
print(S.myAtoi("-91"))