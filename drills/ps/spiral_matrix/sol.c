// problem - https://leetcode.com/problems/spiral-matrix/
// time complexity - O(M * N)
// space complexity - O(1)

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
  int total = matrixSize * (*matrixColSize);
  int *res = malloc(sizeof(int) * total);

  int rid = 0;

  int rbs = 0, rbe = matrixSize - 1;        // row boundary start/end
  int cbs = 0, cbe = *matrixColSize - 1;    // column boundary start/end

  // on each iteration complete one circular starting from outer layer
  // moving forward to inner layer
  while (rid < total) {
    // top row (row fixed, column vary)
    for (int c = cbs; c <= cbe && rid < total; c++)
      res[rid++] = matrix[rbs][c];

    // right column (row vary, column fixed)
    for (int r = rbs + 1; r <= rbe && rid < total; r++)
      res[rid++] = matrix[r][cbe];

    // bottom row (row fixed, column vary)
    for (int c = cbe - 1; c >= cbs && rid < total; c--)
      res[rid++] = matrix[rbe][c];

    // left column (row vary, column fixed)
    for (int r = rbe - 1; r >= rbs + 1 && rid < total; r--)
      res[rid++] = matrix[r][cbs];

    // update the boundary
    rbs++; rbe--;
    cbs++; cbe--;
  }

  *returnSize = total;
  return res;
}