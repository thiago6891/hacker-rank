#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Lane {
    vector<int> _lane;
    
public:
    Lane(int);
    int getVehicle(int, int);
};

int main() {
    int lane_length;
    int total_test_cases;
    cin >> lane_length;
    cin >> total_test_cases;
    
    Lane lane(lane_length);
    
    for (int tc = 0; tc < total_test_cases; tc++) {
        int entry, exit;
        cin >> entry;
        cin >> exit;
        
        cout << lane.getVehicle(entry, exit) << endl;
    }
    
    return 0;
}

Lane::Lane(int length) {
    for (int i = 0; i < length; i++) {
        int x;
        cin >> x;
        _lane.push_back(x);
    }
}

int Lane::getVehicle(int i, int j) {
	// the biggest vehicle is the truck (= 3), so we iterate through the
	// _lane vector from i to j looking for the smallest segment.
    int vehicle = 3;
    for (int x = i; x <= j; x++) {
        if (_lane[x] < vehicle) vehicle = _lane[x];
		
		// if we find a segment that's 1 we can stop the loop since
		// that's the smallest possible value for a segment.
        if (vehicle == 1) break;
    }
    return vehicle;
}
