def longest_common_prefix(strs)
    length = strs.map{ |str| str.length}.min

    prefix = ""
    0.upto(length - 1) do |i|
        char = strs[0][i] # use strs[0] as the template
        strs.each do |str|
            if str[i] != char
                return prefix
            end
        end

        prefix += char
    end

    prefix
end

strs = ["a", "abc", "apple"]

puts longest_common_prefix(strs)