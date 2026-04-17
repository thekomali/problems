// problem -> https://leetcode.com/problems/baseball-game/

// time complexity - O(N)
// space complexity - O(1)

int calPoints(char** operations, int operationsSize) {
  int *records = malloc(sizeof(int) * operationsSize);

  int sum = 0;
  int r_id = 0;

  for (int oper = 0; oper < operationsSize; oper++) {
    char *str = operations[oper];

    switch (str[0]) {
      case '+':    // record a new score, that is sum of previous two scores
        records[r_id] = records[r_id - 1] + records[r_id - 2];
        sum += records[r_id++];
        break;
      case 'D':    // record a new score that is double of previous score
        records[r_id] = 2 * records[r_id - 1];
        sum += records[r_id++];
        break;
      case 'C':    // invalidate the previous score, remove it from record
        sum -= records[--r_id];
        break;
      default:     // this is a record value, parse the number
        char *p = str;
        int val = 0;

        // identify the sign of the number
        int sign = *p == '-' ? -1 : 1;
        if (sign == -1) p++;     // negative sign already consumed

        while (isdigit(*p)) {
          val = (val * 10) + (*p - '0');
          p++;
        }

        val *= sign;   // update the sign

        records[r_id++] = val;
        sum += val;
    }
  }
  return sum;   
}