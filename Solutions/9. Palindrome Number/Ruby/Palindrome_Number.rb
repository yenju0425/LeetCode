def is_palindrome(x)
    return x.to_s.reverse.to_i == x
end

puts is_palindrome(123213)