// time complexity  - O(N)
// space complexity - O(1)

bool isAnagram(char* s, char* t) {
  // array to hold freq of letters in word (initialize to zero)
  int letter_freq[26] = {0};

  while (*s && *t) {
    letter_freq[*s - 'a']++;
    letter_freq[*t - 'a']--;

    s++;
    t++;
  }

  // if words are of different length, then while loop terminates early
  if (*s || *t) return false;

  // verify the value
  for (int i = 0; i < 26; i++) {
    if (letter_freq[i] != 0) return false;
  }

  return true;
}