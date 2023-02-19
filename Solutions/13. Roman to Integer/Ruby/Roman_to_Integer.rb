def roman_to_int(s)
    # create a hash table to store the values of each Roman numeral
    roman_values = {
        "I" => 1,
        "V" => 5,
        "X" => 10,
        "L" => 50,
        "C" => 100,
        "D" => 500,
        "M" => 1000
    }

    result = 0
    length = s.length
    0.upto(length - 2) { |i|
        val = roman_values[s[i]]
        if val < roman_values[s[i + 1]]
            result -= val
        else
            result += val
        end
    }

    result + roman_values[s[-1]]
end

puts roman_to_int("III") # 3