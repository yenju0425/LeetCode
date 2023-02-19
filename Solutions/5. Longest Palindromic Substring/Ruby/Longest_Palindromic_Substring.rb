def longest_palindrome(s)
    longest_palindrome = ""

    length = s.length
    (0).upto(2 * length - 2) do |i|
        l = (i / 2.0).floor
        r = (i / 2.0).ceil
        while l >= 0 && r < length && s[l] == s[r]
            l -= 1
            r += 1
        end

        longest_palindrome = s[l + 1...r] if r - l - 1 > longest_palindrome.length
    end

    longest_palindrome
end

puts longest_palindrome("babad") # bab