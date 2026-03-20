// time complexity  - O(N log N)
// space complexity - O(1)

int compare(const void *a, const void *b) {
  return (*(int *)a - *(int *)b);
}

int numRescueBoats(int* people, int peopleSize, int limit) {
  // sort the array
  qsort(people, peopleSize, sizeof(int), compare);

  int boats_cnt = 0;
  int l = 0, r = peopleSize - 1;

  while (l <= r) {
    if (people[l] + people[r] <= limit) l++;

    boats_cnt++;
    r--;    
  }

  return boats_cnt;    
}