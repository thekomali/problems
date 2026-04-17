// problem -> https://leetcode.com/problems/robot-return-to-origin/

// time complexity - O(N)
// space complexity - O(1)
bool judgeCircle(char* moves) {
  int y = 0, x = 0;  // y - Up +, Down -; x - Right +, Left -

  for (char *move = moves; *move; move++) {
    switch (*move) {
      case 'U': y++; break;
      case 'D': y--; break;
      case 'R': x++; break;
      case 'L': x--; break;
    }
  }

  return (y == 0 && x == 0);   // if both are zero, then robot returned to origin
}