def length_of_longest_substring(s)
    max_length = start = 0

    hash = {}
    s.each_char.with_index do |char, index|
        if hash[char] && hash[char] >= start
            start = hash[char] + 1
        end

        hash[char] = index
        max_length = [max_length, index - start + 1].max
    end

    max_length
end

puts length_of_longest_substring("abcabcbb") # 3