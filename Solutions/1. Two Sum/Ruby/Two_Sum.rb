# @param {Integer[]} nums
# @param {Integer} target
# @return {Integer[]}
def two_sum(nums, target)
    hash = {}
    nums.each_with_index do |number, index|
        if hash[target - number]
            return [hash[target - number], index]
        else
            hash[number] = index
        end
    end
end

#inputs
target = 9
nums = [15, 7, 11, 2]

p two_sum(nums, target)