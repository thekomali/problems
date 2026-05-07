// problem: https://leetcode.com/problems/set-matrix-zeroes/description/

// time complexity: O(M * N)
// space complexity: O(M + N)
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
  bool *row = calloc(matrixSize, sizeof(bool));
  bool *col = calloc((*matrixColSize), sizeof(bool));

  // loop through the array and mark zero
  for (int r = 0; r < matrixSize; r++) {
    for (int c = 0; c < (*matrixColSize); c++) {
      if (matrix[r][c] == 0) {
        col[c] = true;
        row[r] = true;
      }
    }
  }

  // based on the updated zero marks, mark correspoinding row/col values to zeros
  for (int r = 0; r < matrixSize; r++) {
    for (int c = 0; c < (*matrixColSize); c++) {
      if (row[r] || col[c])
        matrix[r][c] = 0;
    } 
  }  
}



// time complexity: O(M * N)
// space compleixty: O(1)
void setZeroes(int** matrix, int matrixSize, int* matrixColSize) {
  int r0 = 0;

  // go throught the values and mark the first row/col to zero
  for (int r = 0; r < matrixSize; r++) {
    for (int c = 0; c < (*matrixColSize); c++) {
      if (matrix[r][c] == 0) {
        // update first row and col
        matrix[r][0] = 0;

        // if c = 0, then don't update matrix[0][0], rather use the variable
        if (c == 0) r0 = 1;
        else matrix[0][c] = 0;
      }
    } 
  }

  // ignore first row/col, loop through other elements and make if zero, if needed
  for (int r = 1; r < matrixSize; r++) {
    for (int c = 1; c < (*matrixColSize); c++) {
      // in case either of it's row/col is zero, then mark it zero
      if (matrix[r][0] == 0 || matrix[0][c] == 0)
        matrix[r][c] = 0;
    }
  }

  // check for value in matrix[0][0] is zero, if so then update col to zero
  if (matrix[0][0] == 0) {
    for (int c = 0; c < *(matrixColSize); c++) matrix[0][c] = 0;
  }

  // check for value r0 is zero, if so then update row to zero
  if (r0 == 1) {
    for (int r = 0; r < matrixSize; r++) matrix[r][0] = 0;
  }
}