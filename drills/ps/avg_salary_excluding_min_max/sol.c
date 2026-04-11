// problem - 

// time complexity - O(N)
// space complexity - O(1)
double average(int* salary, int salarySize) {
  double sum = salary[0];
  int max = salary[0]; 
  int min = salary[0];

  for (int i = 1; i < salarySize; i++) {
    sum += salary[i];

    if (salary[i] < min) min = salary[i];
    if (salary[i] > max) max = salary[i];
  }

  sum -= (min + max);
  return sum / (salarySize - 2);
}