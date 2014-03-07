#include <iostream>
using namespace std;

// This function calculates every fibonacci number until it
// finds one that's greater than or equal to n.
bool isFib(long long int n) {
  	if (n == 0 || n == 1) return true;
  	
  	long long int x[3] = { 0, 1, 1 };
  	while (x[2] < n) {
      	x[0] = x[1];
      	x[1] = x[2];
      	x[2] = x[0] + x[1];
    }
  
  	return x[2] == n;
}

int main() {
    long int T; cin >> T;
  	for (long int tc = 0; tc < T; tc++) {
      	long long int N; cin >> N;
      	if (isFib(N)) cout << "IsFibo" << endl;
      	else cout << "IsNotFibo" << endl;
    }
  	
    return 0;
}
