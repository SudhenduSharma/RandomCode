
#include <algorithm>
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

class MergeIntervals {
 public:
  static vector<Interval> merge(vector<Interval> &intervals) {
    vector<Interval> mergedIntervals;

    std::sort(intervals.begin(), intervals.end(),[](const Interval& interval1, const Interval& interval2) -> bool
            {
                return interval1.start < interval2.start;
            });
    //make sure intervals.size() > 1 other wise iterating over it will fail
    if(intervals.size()<2)
        return intervals;

    vector<Interval>::iterator intervalIter = intervals.begin();
    Interval first = *intervalIter;
    std::advance(intervalIter, 1);
    bool ifLastIntervalWasMerged = false;
    for(;intervalIter != intervals.end(); intervalIter++)
    {
        ifLastIntervalWasMerged = false;
        auto& second = *intervalIter;
        if(first.end >= second.start)
        {
            // over lapping adjust end
            first.end = max(first.end,second.end);
            ifLastIntervalWasMerged = true;
        }
        else
        {
            mergedIntervals.push_back(first);
            first = second;
        }
    }
    mergedIntervals.push_back(first);

    
    //mergedIntervals = intervals;
    return mergedIntervals;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> input = {{1, 3}, {2, 5}, {7, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{6, 7}, {2, 4}, {5, 9}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;

  input = {{1, 4}, {2, 6}, {3, 5}};
  cout << "Merged intervals: ";
  for (auto interval : MergeIntervals::merge(input)) {
    cout << "[" << interval.start << "," << interval.end << "] ";
  }
  cout << endl;
}
