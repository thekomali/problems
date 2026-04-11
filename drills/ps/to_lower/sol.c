// problem - https://leetcode.com/problems/to-lower-case/

// time complexity - O(N)
// space complexity - O(1)
char* toLowerCase(char* s) {
  char *lower = s;

  while (*s) {
    // if the word is upper, then add the value 32 to get to lower case
    if (*s >= 'A' && *s <= 'Z') 
      *s += 32;

    s++;
  }

  return lower;    
}