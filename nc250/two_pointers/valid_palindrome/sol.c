// time complexity -> O(N)
// space complexity -> O(1)

bool isPalindrome(char* s) {
  int l = 0, r = strlen(s) - 1;

  while (l < r) {
    while ( (isspace(s[l]) || ispunct(s[l])) && l < r) l++;
    while ( (isspace(s[r]) || ispunct(s[r])) && l < r) r--;

    if (tolower(s[l++]) != tolower(s[r--]) ) return false;
  }

  return true;    
}