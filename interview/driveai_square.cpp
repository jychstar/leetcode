#include <iostream>
#include <vector>
#include <map>
#include <array>
#include <set>

using namespace std;
using point = array<int,2>;

// get squared distance

int distance(point & p1, point & p2){
    return (p2[0]-p1[0])*(p2[0]-p1[0]) + (p2[1]-p1[1])*(p2[1]-p1[1]);
}

bool is_square(array<point,4> points){
    sort(points.begin(),points.end()); // first x, then y
    set<int> edges = {distance(points[0],points[1]),
                      distance(points[0],points[2]),
                      distance(points[1],points[3]),
                      distance(points[2],points[3]),};
    if (edges.size()>1 || *edges.begin()==0)  // edegs should have equal size and large than 0
        return false;
    point zero_vect = {0,0};
    point diag1 = {points[3][0]-points[0][0],
                   points[3][1]-points[0][1]};
    point diag2 = {points[2][0]-points[1][0],
                   points[2][1]-points[1][1]};
    if (diag1 == zero_vect || diag2 == zero_vect) // diagonals larger than 0
        return false;

    // orthogonal?  x1^2 + y1^2 + x2^2 + y2^2 = (x1-x2)^2 + (y1-y2)^2
    return (diag1[0] *diag2[0] + diag1[1] *diag2[1] == 0);
}

int main ()
{
    point p0 = {0,0};
    point p1 = {0,1};
    point p2 = {1,0};
    point p3 = {1,1};
    array<point,4>  p = {p0,p1,p2,p3};
    cout << is_square(p) <<endl;
    return 0;
}
