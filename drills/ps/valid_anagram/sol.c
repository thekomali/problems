// problem - https://leetcode.com/problems/valid-anagram/

// time complexity  - O(M * N)
// space compelxity - O(1)
bool isAnagram(char* s, char* t) {
   // array to act a hashtable to calculate frequency of chars
   int freq[26];
   memset(freq, 0, sizeof(freq));

   while (*s && *t) {
    freq[*s - 'a']++;
    freq[*t - 'a']--;

    s++; t++;
   }

  // if length of string are not equal, then the conditon will be true
   if (*s || *t) return false;

   // check if freq of all are zero
   for (int i = 0; i < 26; i++) {
    if (freq[i] != 0) return false;
   }

   return true;
}