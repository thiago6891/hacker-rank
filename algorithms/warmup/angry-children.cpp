#include <iostream>
#include <list>
#include <climits>
using namespace std;

int main() {
  	// N is the number of packets to distribute and K the number of children.
    long int N, K;
  	cin >> N; cin >> K;
  	
  	// variable packets holds the number of candies in each packet.
  	list<long int> packets;
  	for (long int p = 0; p < N; p++) {
      	long int c; cin >> c;
      	packets.push_back(c);
    }
  	packets.sort();
  
  	// After sorting the packets, the unfairness will be minimized by picking a sequence of K
  	// consecutive packets. fit and bit points to first and last element of this sequence
  	// respectively.
  	list<long int>::iterator fit = packets.begin();
  	list<long int>::iterator bit = fit;
  	for (long int c = 1; c < K; c++) fit++;
  
  	// The unfairness of a sequence is the difference between its first and last elements, given
  	// it's been sorted. We iterate through all possible sequences and store the minimum unfairness
  	// found.
  	long int unfairness = LONG_MAX;
  	while (unfairness != 0 && fit != packets.end()) {
      	if (*fit - *bit < unfairness) unfairness = *fit - *bit;
      	fit++; bit++;
    }
  
  	cout << unfairness;
  
    return 0;
}
