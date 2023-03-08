var twoSum = function(nums, target) {
    let numIdx = new Map();
    for (let i = 0; i < nums.length; i++) {
        if (numIdx.has(target - nums[i])) {
            return [numIdx.get(target - nums[i]), i];
        } else {
            numIdx.set(nums[i], i);
        }
    }
};

let nums = [2, 7, 11, 15];
let target = 9;

console.log(twoSum(nums, target));