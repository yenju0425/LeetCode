function minSubArrayLen(target: number, nums: number[]): number {
  let sum = 0;
  let min_length = 0;

  let i = 0, j = 0;
  while (j < nums.length || sum > target) {
    if (sum < target) {
      sum += nums[j];
      j++;
    } else if (sum >= target) {
      sum -= nums[i];
      i++;
    }

    if (sum >= target) {
      min_length = (min_length == 0) ? j - i : Math.min(min_length, j - i);
    }
  }

  return min_length;
};

const target = 7;
const nums = [2, 3, 1, 2, 4, 3];

console.log(minSubArrayLen(target, nums));