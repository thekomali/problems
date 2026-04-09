// problem - https://leetcode.com/problems/find-the-difference/
// time complexity  - O(M + N)
// space complexity - O(1)

// WAY 01 //
char findTheDifference(char* s, char* t) {
  // array to track the occurance count & initialize to zero
  int freq[26];
  memset(freq, 0, sizeof(freq));

  while (*s) {
    freq[*t - 'a']++;  // increment count for t chars
    freq[*s - 'a']--;  // decrement count for s chars

    s++; t++;
  }

  // as t is one larger than s, updating the final character
  freq[*t - 'a']++;

  for (int i = 0; i < 26; i++) {
    // if freq is 1, then it's newly added character
    if (freq[i] == 1) return 'a' + i;
  }

  return ' ';   // if we reach here, then there is no single character added
}


// WAY 02 //
char findTheDifference(char* s, char* t) {
  char diff = 0;

  while (*s) {
    diff ^= *s;
    diff ^= *t;

    s++; t++;
  }

  diff ^= *t;

  return diff;
}