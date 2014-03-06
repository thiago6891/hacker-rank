#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#define INITIAL_SIZE 1

int growth(int);

int main() {
    int total_test_cases;
    cin >> total_test_cases;
    for (int tc = 0; tc < total_test_cases; tc++) {
        int cycles;
        cin >> cycles;
        cout << growth(cycles) << endl;
    }
    
    return 0;
}

// this function return the growth of the tree in meters after a given number of cycles.
int growth(int cycles) {
    if (cycles == 0) return INITIAL_SIZE;
    
    // when the cycle is even it's summer, otherwise it's monsoon season.
    if (cycles % 2 == 0) return growth(cycles - 1) + 1;
    else return growth(cycles - 1) * 2;
}
