// time complexity  - O(N * M)  ; N - no of strings, M - avg string length
// space complexity - O(N)

char* longestCommonPrefix(char** strs, int strsSize) {
  // precompute the length of all the string
  int *strs_len = malloc(sizeof(int) * strsSize);
  for (int i = 0; i < strsSize; i++)
    strs_len[i] = strlen(strs[i]);

  char curr_char;

  // do vertical scanning,
  // for a index, check it across all the string for match
  for (int p = 0; strs[0][p] != '\0'; p++) {
    curr_char = strs[0][p];

    // loop through all the string and see if it matches with curr_char
    for (int str = 1; str < strsSize; str++) {
      if (strs_len[str] < p || strs[str][p] != curr_char) {
        // either string is out of limit or not have a match
        // so size of str till p is the common prefix
        char *common = malloc(sizeof(char) * (p + 1));
        memcpy(common, strs[0], p);
        common[p] = '\0';

        return common;
      }
    }
  }

  // if we reach here, then entire strs[0] is common with all strings
  return strs[0]; 
}