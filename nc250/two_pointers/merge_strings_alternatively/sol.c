// time complexity  - O(N)
// space compelxity - O(1)



char * mergeAlternately(char * word1, char * word2){
  // allocate memory for merged string
  char *merged = malloc(sizeof(char) * (strlen(word1) + strlen(word2) + 1));
  if (!merged) return NULL;

  // make a copy of start of the word
  char *start = merged;

  while (*word1 && *word2) {
    *merged++ = *word1++;
    *merged++ = *word2++;
  }

  // if any left over words present, then append it to the last
  while (*word1) *merged++ = *word1++;
  while (*word2) *merged++ = *word2++;

  *merged = '\0';
  return start;
}