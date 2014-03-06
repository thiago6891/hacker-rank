#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

class Point {
    int _x;
    int _y;
    
public:
    Point(int x, int y) : _x(x), _y(y) {}
    
    int getX() { return _x; }
    int getY() { return _y; }
    
    Point operator- (Point other) {
        int x, y;
        x = _x - other.getX();
        y = _y - other.getY();
        Point p(x, y);
        return p;
    }
};

Point operator* (int a, Point point) {
    int x, y;
    x = point.getX() * a;
    y = point.getY() * a;
    Point p(x, y);
    return p;
}

int main() {
    int T; cin >> T;
    for (int tc = 0; tc < T; tc++) {
        int x, y;
        
        cin >> x; cin >> y;
        Point P(x, y);
        cin >> x; cin >> y;
        Point Q(x, y);
        
        // To find the symmetric point of P about Q we just
        // have to calculate Q + (Q - P), which is 2*Q - P.
        Point R = 2 * Q - P;
        cout << R.getX() << " " << R.getY() << endl;
    }
    
    return 0;
}
