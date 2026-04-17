// problem - 

// time complexity - O(N)
// space complexity - O(1)

int get_value(char ch) {
  // use C's designated initializer syntax to set specific indices
  static const int map[256] = {
    ['I'] = 1,
    ['V'] = 5,
    ['X'] = 10,
    ['L'] = 50,
    ['C'] = 100,
    ['D'] = 500,
    ['M'] = 1000
  };

  return map[ch];
}


int romanToInt(char* s) {
  int len = strlen(s);
  int value = 0, curr = 0, next = 0;

  for (int i = 0; i < len; i++) {
    curr = get_value(s[i]);
    next = s[i + 1] ? get_value(s[i + 1]) : 0;

    if (next > curr) {
      // value should decrease from right to left (exception: IV)
      value += (next - curr);
      i++;      // skip the next value as it's consumed
    }
    else
      value += curr;
  }

  return value;    
}