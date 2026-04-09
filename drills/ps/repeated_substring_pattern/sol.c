// problem - 

// time complexity  - inner loop runs only if i is the divisor of slen
//                     d(N) is divisor of slen, then
//                     runtime = d(N) * N
//                     in worst case it can be N^2 => O(N^2)
// space complexity - O(1)

bool repeatedSubstringPattern(char* s) {
  int slen = strlen(s);

  for (int i = 1; i <= slen/2; i++) {
    // consider only the possible divisors that can be strlen of pattern
    if (slen % i == 0) {
      // setup a loop to compare the patten through out the string
      bool match = true;

      for (int p = i; p < slen; p++) {
        // start comparing from starting index to a with width of i
        // where i is considered len of pattern
        if (s[p - i] != s[p]) {
          match = false;
          break;
        }
      }

      if (match) return true;
    }
  }

  return false;
}