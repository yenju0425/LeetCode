$roman_values = "IVXLCDM" # 1, 5, 10, 50, 100, 500, 1000

def digit_to_symbol(digit, index)
    digit = digit.to_i
    return "" if digit == 0

    symbol1 = ($roman_values[index * 2]&.to_s)
    symbol5 = ($roman_values[index * 2 + 1]&.to_s)
    symbolX = ($roman_values[index * 2 + 2]&.to_s)

    case digit
    when 1..3
        symbol1 * digit
    when 4
        symbol1 + symbol5
    when 5
        symbol5
    when 6..8
        symbol5 + symbol1 * (digit - 5)
    when 9
        symbol1 + symbolX
    end
end


def int_to_roman(num)
    result = ""
    num.to_s.reverse.chars.map.with_index do |digit, index|
        result = digit_to_symbol(digit, index) + result
    end

    result
end

puts int_to_roman(1994) # MCMXCIV