// problem - https://leetcode.com/problems/matrix-diagonal-sum/

// time complexity - O(N)
// space complexity - O(1)

int diagonalSum(int** mat, int matSize, int* matColSize) {
  int sum = 0;

  for (int r = 0; r < matSize; r++) {
    // primary diagonal elements
    sum += mat[r][r];

    // secondary diagonal elements
    sum += mat[r][matSize - 1 - r];
  }

  return (matSize % 2 == 0 ? sum : sum - mat[matSize / 2][matSize / 2]);    
}