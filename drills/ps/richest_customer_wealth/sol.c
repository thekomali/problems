// problem - https://leetcode.com/problems/richest-customer-wealth/

// time complexity - O(N)
// space complexity - O(1)
int maximumWealth(int** accounts, int accountsSize, int* accountsColSize) {
  int rich_customer = 0;

  for (int c = 0; c < accountsSize; c++) {
    int balance = 0;
  
    for (int a = 0; a < *accountsColSize; a++) {
      balance += accounts[c][a];      
    }

    rich_customer = balance > rich_customer ? balance : rich_customer;
  }

  return rich_customer;    
}