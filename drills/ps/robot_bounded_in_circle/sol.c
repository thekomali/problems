// problem -> https://leetcode.com/problems/robot-bounded-in-circle/
// time complexity - O(N)
// space complexity - O(1)

bool isRobotBounded(char* instructions) {
  // Track the direction of Head of the robot
  // North: (0,1), West: (-1, 0), South: (0, -1), East: (1, 0)
  int directions[4][2] = {{0, 1}, {-1, 0}, {0, -1}, {1, 0}};

  // track current position of Robot (x, y)
  int pos[2] = {0, 0}; 

  // denote the current direction the robot is looking at
  // by refering to the index of the direction's array
  int curr_dir = 0;

  while (*instructions) {
    if (*instructions == 'L')          // if left, then rotate towards West (index -> 1)
      curr_dir = (curr_dir + 1) % 4;
    else if (*instructions == 'R')     // if left, then rotate towards West (index -> 3)
      curr_dir = (curr_dir + 3) % 4;
    else {
      // if not rotations, then move instruction
      // move the robot in the appropiate direction pointed by curr_dir
      pos[0] += directions[curr_dir][0];
      pos[1] += directions[curr_dir][1];
    }

    instructions++;
  }

  // condition for robot to move in circles
  // 1. position return to initial position (origin)
  // 2. direction should be other that starting direction (North)
  return (pos[0] == 0 && pos[1] == 0) || curr_dir != 0;    
}