function asteroidCollision(asteroids: number[]): number[] {
  for (let i = 0, right_asteroids: number[][] = []; i < asteroids.length; i++) {
    if (asteroids[i] > 0) {
      right_asteroids.push([asteroids[i], i]);
    } else {
      const size = Math.abs(asteroids[i]);
      for (let j = right_asteroids.length - 1; j >= 0; j--) {
        if (right_asteroids[j][0] < size) {
          asteroids[right_asteroids[j][1]] = 0;
          right_asteroids.pop();
        } else if (right_asteroids[j][0] === size) {
          asteroids[right_asteroids[j][1]] = 0;
          right_asteroids.pop();
          asteroids[i] = 0;
          break;
        } else {
          asteroids[i] = 0;
          break;
        }
      }
    }
  }

  return asteroids.filter((asteroid) => asteroid !== 0);
};

const asteroids = [8,-8];

console.log(asteroidCollision(asteroids));