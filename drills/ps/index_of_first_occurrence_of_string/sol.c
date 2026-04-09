// problem - https://leetcode.com/problems/find-the-index-of-the-first-occurrence-in-a-string/


// time complexity  - O(N * M)
// space complexity - O(1)
int strStr(char* haystack, char* needle) {
  int hlen = strlen(haystack), nlen = strlen(needle);
  int h = 0, n = 0;

  while (h <= hlen - nlen) {
    while ((n < nlen) && (haystack[h] == needle[n])) {
      h++; n++;
    }

    // scanned completly though the needle, means we got a match
    if (n == nlen) return h - n;

    // if not, then reset the pointers, h to be incremented by 1
    h = h - n + 1;
    n = 0;
  }

  return -1;  
}