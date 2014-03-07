#include <iostream>
using namespace std;

// The formula which gives the average is C/N, where C is the total number of candies in all jars
// after the M operations. In the worst case scenario C = N*M*k, when N = 10e+7, M = 10e+5 and
// k = 10e+6, which gives C = 10e+18, so we need to use a long long int to avoid an overflow, and
// long int for the other variables for the same reason.

int main() {
  	long int N, M;
  	cin >> N; cin >> M;
  
  	long long int C = 0;
  	for (long int op = 0; op < M; op++) {
      	long int a, b, k;
      	cin >> a; cin >> b; cin >> k;
      	// (b - a + 1) is the total number of jars filled by the current operation.
      	C += (b - a + 1) * k;
    }
  
  	cout << C / N;
  
    return 0;
}
