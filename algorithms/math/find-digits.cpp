#include <iostream>
#include <string>
using namespace std;

int main() { 
  	int T; cin >> T;
  	for (int tc = 0; tc < T; tc++) {
      	string str; cin >> str;
      	// a long long int has to be used in order to support the largest possible number 1e+10.
      	long long int N = stoll(str);
      	int count = 0;
      	
      	// we just have to divide the number by each one of its digits and increment
      	// a counter when the modulo of the number by the i'th digit equals zero.
      	for (int i = 0; i < str.size(); i++) {
          	int d = str[i] - '0';
          	if (d != 0 && N % d == 0) count++;
        }
      	
      	cout << count << endl;
    }
	
    return 0;
}
