#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

long long int pieces(int);

int main() {
    int total_test_cases;
    cin >> total_test_cases;
    for (int tc = 0; tc < total_test_cases; tc++) {
        int cuts;
        cin >> cuts;
        cout << pieces(cuts) << endl;
    }
    
    return 0;
}


// To calculate the number of pieces obtained after cutting the chocolate bar, we just multiply
// the number of horizontal lines by the number of vertical lines, which is just the area of a
// square whose sides are LH and LV, number of horizontal and vertical lines respectively. In
// order to maximize the area of a square, its side should be equal, but since we need to work
// with integers, they won't be equal for odd values of K.
// One of the sides of the square will be K/2 and the other side will be K/2 plus K%2, so the
// are is calculated by K/2 * (K/2 + K%2).
// In the worst case scenario K = 1e+7 and the value returned would be 2.5e+13, therefore, to
// avoid an overflow, a long long int must be returned.
long long int pieces(int K) {
    long long int half_K = K / 2;
    return half_K * (half_K + (K % 2));
}
