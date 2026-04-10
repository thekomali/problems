// problem - https://leetcode.com/problems/count-odd-numbers-in-an-interval-range

// time complexity  - O(1)
// space complexity - O(1)
int countOdds(int low, int high){
  int res = (high - low) / 2;

  // if either of high/low is odd, then add +1
  return (high % 2 || low % 2) ? res + 1 : res;
}