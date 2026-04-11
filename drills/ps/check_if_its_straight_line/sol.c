// problem - https://leetcode.com/problems/check-if-it-is-a-straight-line/

// time complexity - O(N)
// space complexity - O(1)
bool checkStraightLine(int** coordinates, int coordinatesSize, int* coordinatesColSize) {
  // two points are always collinear
  if (coordinatesSize <= 2) return true;

  int cross = 0;

  // find reference vector, v = (x0 - x1, y0 - y1)
  int v[2] = {coordinates[0][0] - coordinates[1][0], coordinates[0][1] - coordinates[1][1]};

  for (int p = 2; p < coordinatesSize; p++) {
    // find curr vector, w = (x0 - xi, y0 - yi)
    int w[2] = {coordinates[0][0] - coordinates[p][0], coordinates[0][1] - coordinates[p][1]};

    // calculate the cross product, v x w = (vx * wy) - (vy * wx)
    cross = (v[0] * w[1]) - (v[1] * w[0]);
    
    // if cross is not zero, then curr point is not collinear
    if (cross != 0) return false;
  }

  return true;    
}