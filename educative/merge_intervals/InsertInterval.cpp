
#include <iostream>
#include <vector>

using namespace std;
class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class InsertInterval {
 public:
  static vector<Interval> insert(const vector<Interval> &intervals, Interval newInterval) {
    vector<Interval> mergedIntervals;
    if(intervals.size() < 1 )
    {
        mergedIntervals.push_back(newInterval);
        return mergedIntervals;
    }

    //find where to start
    int i = 0;
    while((i< intervals.size()) && (intervals[i].end < newInterval.start) ) 
    {
        mergedIntervals.push_back(intervals[i]);
        ++i;
    }

    //merge newInterval  with overlapping
    while( (i<intervals.size()) && (intervals[i].start < newInterval.end))
    {
        newInterval.start = min(intervals[i].start,newInterval.start);
        newInterval.end = max(intervals[i].end,newInterval.end);
        ++i;
    }
    mergedIntervals.push_back(newInterval);
    
    //finish remaining
    while(i <intervals.size() )
    {
        mergedIntervals.push_back(intervals[i]);
        ++i;
    }

    return mergedIntervals;
  }
};
int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {5, 7}, {8, 12}};
  cout << "Intervals before inserting the new interval: ";
  for (auto interval : input){
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
  cout << "Intervals after inserting the new interval {4,6}: ";
  for (auto interval : InsertInterval::insert(input, {4, 6})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  cout << "Intervals before inserting the new interval: ";
  for (auto interval : input){
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
  cout << "Intervals after inserting the new interval: {4,10} ";
  for (auto interval : InsertInterval::insert(input, {4, 10})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{2, 3}, {5, 7}};
  cout << "Intervals before inserting the new interval: ";
  for (auto interval : input){
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
  cout << "Intervals after inserting the new interval:  {1,4}";
  for (auto interval : InsertInterval::insert(input, {1, 4})) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
