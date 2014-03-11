#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
  	string str; cin >> str;

  	// charCount keeps the number of times each character appears in the string.
  	// a long int is used to support the maximum string size which is 1e+5.
  	map<char, int> charCount;
  	for (long int i = 0; i < str.size(); i++)
      	charCount[str[i]]++;
  	
  	// A string can only be permuted to a palindrome if the number of times each character appears
  	// in the string is even for a string which size is also even. For odd strings, exactly one of
  	// the characters appears an odd number of times.
  	bool palindrome = true;
  	bool oddNumberAllowed = str.size() % 2 != 0;
  	map<char, int>::iterator it = charCount.begin();
  	while (it != charCount.end()) {
      	if (it->second % 2 != 0) {
        	if (oddNumberAllowed) oddNumberAllowed = false;
          	else {
          		palindrome = false;
          		break;
        	}
      	}
      	it++;
    }
  	
  	if (palindrome) cout << "YES";
  	else cout << "NO";
  
    return 0;
}
