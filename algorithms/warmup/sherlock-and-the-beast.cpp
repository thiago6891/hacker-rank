#include <string>
#include <iostream>
#include <queue>
using namespace std;

const string FIVE_SEGMENT = "555";
const string THREE_SEGMENT = "33333";

int main() {
    int total_test_cases; cin >> total_test_cases;
  	for (int tc = 0; tc < total_test_cases; tc++) {
      	int k; cin >> k;
		
      	queue<string> result;
      	int total_size = 0;
      	
      	// first we put as many five segments as possible in the result.
      	while (total_size + FIVE_SEGMENT.size() <= k) {
          	result.push(FIVE_SEGMENT);
          	total_size += FIVE_SEGMENT.size();
        }
      
      	// Second we start putting the three segments, popping out the five segments as needed to
      	// make room for the three segments, hence the use of a queue. If we ever run out of five
      	// segments in the queue and start popping out three segments, we stop the loop, since it's
      	// pointless to pop out a segment and replace it by the same segment.
      	string last_pop;
      	while (last_pop != THREE_SEGMENT && total_size != k) {
          	result.push(THREE_SEGMENT);
          	total_size += THREE_SEGMENT.size();
          	while (total_size > k) {
              	last_pop = result.front();
              	result.pop();
              	total_size -= last_pop.size();
            }
        }
      
      	if (total_size != k) cout << "-1" << endl;
      	else {
          	while (!result.empty()) {
              	cout << result.front();
              	result.pop();
            }
          	cout << endl;
        }
    }
  
    return 0;
}
