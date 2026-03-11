// time complexity -> O(N)
// space complexity -> O(1)

#define SWAP(a, b) do {     \
  __typeof__(a) tmp = (a);  \
  (a) = (b);                \
  (b) = tmp;                \
} while(0)


void reverseString(char* s, int sSize) {
  for (int l = 0, r = sSize-1; l < r; r--, l++) {
    SWAP(s[l], s[r]);
  }    
}