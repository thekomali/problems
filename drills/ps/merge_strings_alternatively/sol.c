// time complexity  - O(N + M)
// space complexity - O(N + M)


char * mergeAlternately(char * word1, char * word2){
  // allocate space for the merged string (+1 for null character)
  char *merged = malloc(strlen(word1) + strlen(word2) + 1);
  if (!merged) return NULL;

  int id = 0;
  while (*word1 && *word2) {
    merged[id++] = *word1++;
    merged[id++] = *word2++;
  }

  // if there are any lefover chars, then append it to the end
  while (*word1) merged[id++] = *word1++;
  while (*word2) merged[id++] = *word2++;

  // finally add the null character
  merged[id] = '\0';

  return merged;
}