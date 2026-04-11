// problem - https://leetcode.com/problems/lemonade-change

// time complexity  - O(N)
// space complexity - O(1)
bool lemonadeChange(int* bills, int billsSize) {
  int b5 = 0, b10 = 0, bill = 0;

  for (int i = 0; i < billsSize; i++) {
    bill = bills[i];

    switch (bill) {
      case 5:
        b5++; break;
      case 10:
        if (b5 <= 0) return false;
        b5--; b10++;
        break;
      case 20:
        if (b10 > 0 && b5 > 0) { b5--; b10--; }
        else if (b5 >= 3) b5 -= 3;
        else return false;
    }
  }

  return true;
}