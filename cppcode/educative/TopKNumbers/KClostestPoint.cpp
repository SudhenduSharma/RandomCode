using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Point {
 public:
  int x = 0;
  int y = 0;

  Point(int x, int y) {
    this->x = x;
    this->y = y;
  }

  int distFromOrigin() const {
    // ignoring sqrt
    return (x * x) + (y * y);
  }
  bool operator <(const Point& p) const
  { 
      return this->distFromOrigin() < p.distFromOrigin();  
  }
};



class KClosestPointsToOrigin {
 public:
  static vector<Point> findClosestPoints(const vector<Point>& points, int k) {

    vector<Point> maxHeap;
    for(int i = 0; i < k; ++i)
    {
        maxHeap.push_back(points[i]);
        push_heap(maxHeap.begin(),maxHeap.end());
    }

    for(int i =k ; i < points.size(); ++i)
    {
        if( points[i] < maxHeap.front())
        {
             pop_heap(maxHeap.begin(),maxHeap.end());
             maxHeap.pop_back();
             maxHeap.push_back(points[i]);
             push_heap(maxHeap.begin(),maxHeap.end());
        }
    }

    return maxHeap;
  }
};

int main(int argc, char* argv[]) {
  vector<Point> maxHeap = KClosestPointsToOrigin::findClosestPoints({{1, 3}, {3, 4}, {2, -1}}, 2);
  cout << "Here are the k points closest the origin: ";
  for (auto p : maxHeap) {
    cout << "[" << p.x << " , " << p.y << "] ";
  }
}
