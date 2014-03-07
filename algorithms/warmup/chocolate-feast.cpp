#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int total_test_cases; cin >> total_test_cases;
  	for (int tc = 0; tc < total_test_cases; tc++) {
      	int money, price, wrappers_needed;
      	cin >> money; cin >> price; cin >> wrappers_needed;
      	
      	// first we calculate how many chocolates our money can buy
      	int chocolates = money / price;
      	
      	// then we keep changing our wrappers until we can't do it anymore
      	int total_wrappers = chocolates;
      	while (total_wrappers >= wrappers_needed) {
          	int more_chocolate = total_wrappers / wrappers_needed;
          	chocolates += more_chocolate;
          	total_wrappers %= wrappers_needed;
          	total_wrappers += more_chocolate;
        }
      
      	cout << chocolates << endl;
    }	
  
    return 0;
}
