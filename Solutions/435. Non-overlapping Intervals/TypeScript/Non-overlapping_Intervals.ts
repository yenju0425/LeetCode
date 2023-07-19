function eraseOverlapIntervals(intervals: number[][]): number {
  let temp: number | null = null;
  let count = 0;
  intervals.sort((a, b) => a[1] - b[1]);
  for (const interval of intervals) {
    if (temp === null || interval[0] >= temp) {
      temp = interval[1];
    } else {
      count += 1;
    }
  }

  return count;
};

const intervals = [[1,2],[2,3],[3,4],[1,3]];

console.log(eraseOverlapIntervals(intervals));