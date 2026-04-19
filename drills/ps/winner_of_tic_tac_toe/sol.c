// problem - https://leetcode.com/problems/find-winner-on-a-tic-tac-toe-game/

// time complexity - O(N)
// space complexity - O(1)
char* tictactoe(int** moves, int movesSize, int* movesColSize) {
  // No need to create a board -> populate with moves -> then find who won.

  int row[3] = {0, 0, 0};  // array to track the moves placed in each rows
  int col[3] = {0, 0, 0};  // array to track the moves placed in each col
  int dia = 0;             // track moves placed in main diagonal (left to right)
  int dia_cross = 0;       // track moves placed in cross diagonal (right to left)

  int player;  // +1 means player 'A' and -1 means player 'B'

  int r = 0, c = 0;

  for (int move = 0; move < movesSize; move++) {
    // current moves - row and column
    r = moves[move][0];
    c = moves[move][1];

    // identify player
    player = move % 2 == 0 ? +1 : -1;

    // update row/col/diag/cross_diag
    row[r] += player;
    col[c] += player;
    if (r == c) dia += player;              // (0,0), (1,1), (2,2)
    if (r + c == 2) dia_cross += player;    // (0,2), (1,1), (2,0)

    // finally check for match across col/row
    if (row[r] == 3 || col[c] == 3 || dia == 3 || dia_cross == 3) return "A";
    if (row[r] == -3 || col[c] == -3 || dia == -3 || dia_cross == -3) return "B";
  }

  // moves finished/partially filled
  return movesSize == 9 ? "Draw" : "Pending";
}