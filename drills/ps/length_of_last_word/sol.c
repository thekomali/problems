// problem - https://leetcode.com/problems/length-of-last-word/

// time complexity  - O(N)
// space complexity - O(1)
int lengthOfLastWord(char* s) {
  // split the string based on the space
  char *word = strtok(s, " ");

  char *last = NULL;
  while (word) {
    last = word;
    word = strtok(NULL, " ");
  }

  return strlen(last);    
}