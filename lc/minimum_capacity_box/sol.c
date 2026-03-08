// time complexity  - O(N)
// space complexty  - O(1)

int minimumIndex(int* capacity, int capacitySize, int itemSize) {
  int box_id = -1;
  int min_cap = INT_MAX;

  for (int box = 0; box < capacitySize; box++) {
    if ((capacity[box] >= itemSize) && (capacity[box] < min_cap)) {
      box_id = box;
      min_cap = capacity[box];
    }  
  }

  return box_id;    
}