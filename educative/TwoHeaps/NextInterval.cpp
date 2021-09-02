using namespace std;

#include <iostream>
#include <queue>
#include <vector>

class Interval {
 public:
  int start = 0;
  int end = 0;

  Interval(int start, int end) {
    this->start = start;
    this->end = end;
  }
};

class NextInterval {

 public:
     class Compare
     {
         public :
             bool operator()(pair<int,int>& first, pair<int,int>& second)
             {
                 return first.first < second.first;
             }
     };
  static vector<int> findNextInterval(const vector<Interval> &intervals) {
    int n = intervals.size();
    vector<int> result(n);
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> maxHeapStart;
    priority_queue<pair<int,int>,vector<pair<int,int>>,Compare> maxHeapEnd;

    for(int i = 0; i<intervals.size();++i)
    {
        maxHeapStart.push(make_pair(intervals[i].start,i));
        maxHeapEnd.push(make_pair(intervals[i].end,i));
    }

    while(!maxHeapEnd.empty())
    {
        auto end = maxHeapEnd.top();
        maxHeapEnd.pop();
        result[end.second] = -1;
        auto start = maxHeapStart.top();
        if(end.first <= start.first)
        {
            while(!maxHeapStart.empty() &&  end.first <= maxHeapStart.top().first)
            {
                start = maxHeapStart.top();
                //cout << "pop " << start.second << endl;
                //cout <<"pop " << end.second << " --> " << start.second  << " end.first " << end.first << " start.first " << start.first << endl;
                maxHeapStart.pop();
            }
            //cout << end.second << " --> " << start.second  << " end.first " << end.first << " start.first " << start.first << endl;
            result[end.second] = start.second;
            maxHeapStart.push(start);
        }
        else
        {
            result[end.second] = -1;
            //cout << "-1 --> " << end.second << endl; 
        }   
    }

    return result;
  }
};

int main(int argc, char *argv[]) {
  vector<Interval> intervals = {{2, 3}, {3, 4}, {5, 6}};
  vector<int> result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
  cout << endl;

  intervals = {{3, 4}, {1, 5}, {4, 6}};
  result = NextInterval::findNextInterval(intervals);
  cout << "Next interval indices are: ";
  for (auto index : result) {
    cout << index << " ";
  }
}
