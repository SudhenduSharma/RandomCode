using namespace std;

#include <iostream>
#include <queue>
#include <unordered_map>
#include <vector>

class TopKFrequentNumbers {
  struct valueCompare {
    char operator()(const pair<int, int> &x, const pair<int, int> &y) {
      return x.second > y.second;
    }
  };

 public:
  static vector<int> findTopKFrequentNumbers(const vector<int> &nums, int k) {
    vector<int> topNumbers;
    // TODO: Write your code here
    unordered_map<int,int> frequecyMap;
    for(auto i :nums)
    {
        frequecyMap[i]++;
    }
    priority_queue<pair<int,int>,vector<pair<int,int>>,valueCompare> minHeapHoldinTopKNumbers;
    for(auto numberFreq:frequecyMap)
    {
        minHeapHoldinTopKNumbers.push(numberFreq);
        if(minHeapHoldinTopKNumbers.size() > k)
        {
            minHeapHoldinTopKNumbers.pop();
        }
    }
    while(!minHeapHoldinTopKNumbers.empty())
    {
        topNumbers.push_back(minHeapHoldinTopKNumbers.top().first);
        minHeapHoldinTopKNumbers.pop();
    }
    return topNumbers;
  }
};

int main(int argc, char *argv[]) {
  vector<int> result =
      TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{1, 3, 5, 12, 11, 12, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = TopKFrequentNumbers::findTopKFrequentNumbers(vector<int>{5, 12, 11, 3, 11}, 2);
  cout << "Here are the K frequent numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
