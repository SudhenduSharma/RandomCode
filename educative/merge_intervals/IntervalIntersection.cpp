
using namespace std;

#include <iostream>
#include <vector>
#include <algorithm>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class IntervalsIntersection {
 public:
  static vector<Interval> merge(const vector<Interval> &arr1, const vector<Interval> &arr2) {
    vector<Interval> result;

    int i = 0, j = 0;
    
    while(i < arr1.size() && j < arr2.size())
    {

        //when to intersect? henever end of either of the array falls within another
        if(((arr2[j].start >= arr1[i].start) && (arr2[j].start <= arr1[i].end))|| ((arr1[i].start >= arr2[j].start) && (arr1[i].start <= arr2[j].end)))
        {
        //intersection of interval
            int start =   max(arr1[i].start , arr2[j].start);
            int end   =   min(arr1[i].end,arr2[j].end);
            result.push_back(Interval(start,end));
        }
        
        if(arr1[i].end < arr2[j].end)
            i++;
        else if(arr1[i].end > arr2[j].end)
            j++;
        else
            i++;

    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input1 = {{1, 3}, {5, 6}, {7, 9}};
  vector<Interval> input2 = {{2, 3}, {5, 7}};
  vector<Interval> result = IntervalsIntersection::merge(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input1 = {{1, 3}, {5, 7}, {9, 12}};
  input2 = {{5, 10}};
  result = IntervalsIntersection::merge(input1, input2);
  cout << "Intervals Intersection: ";
  for (auto interval : result) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
}
