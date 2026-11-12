#include <iostream>
#include <algorithm>
#include<vector>
using namespace std;

struct Point {
    double x, y;
} ;

// Checks if point q lies on segment pr
bool onSegment(Point p, Point q, Point r) {
    return q.x <= std::max(p.x, r.x) && q.x >= std::min(p.x, r.x) &&
           q.y <= std::max(p.y, r.y) && q.y >= std::min(p.y, r.y);
}

// Finds orientation of ordered triplet (p, q, r)
// Returns: 0 -> collinear, 1 -> clockwise, 2 -> counterclockwise
int orientation(Point p, Point q, Point r) {
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
    if (val == 0) return 0;
    return (val > 0) ? 1 : 2;
}

// Returns true if segment 'ab' and segment 'cd' intersect
bool doIntersect(Point a, Point b, Point c, Point d) {
    int o1 = orientation(a, b, c);
    int o2 = orientation(a, b, d);
    int o3 = orientation(c, d, a);
    int o4 = orientation(c, d, b);

    // General case: segments straddle each other
    if (o1 != o2 && o3 != o4)
        return true;

    // Special collinear cases
    if (o1 == 0 && onSegment(a, c, b)) return true;
    if (o2 == 0 && onSegment(a, d, b)) return true;
    if (o3 == 0 && onSegment(c, a, d)) return true;
    if (o4 == 0 && onSegment(c, b, d)) return true;

    return false;
}

int main(){
    vector<Point> p(4);
    for (int  i = 0; i < 4 ; i++)
    {
        double a,b;
        cin>>a>>b;
        p[i].x = a;
        p[i].y = b;
    }
    if(doIntersect(p[0],p[1],p[2],p[3])){
        cout<<"yes";
    }
    else{
        cout<<"No\n";
    }
    
    return 0;
}