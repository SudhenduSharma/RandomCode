using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

class KLargestNumbers {
 public:
  static vector<int> findKLargestNumbers(const vector<int>& nums, int k) {
    //check if  nums.size() > k else return nums
    vector<int> minHeap(nums.begin(),nums.begin()+k);
    make_heap(minHeap.begin(),minHeap.end(),std::greater<>{});
    for(int i = k; i < nums.size();++i)
    {
        if(nums[i] > minHeap.front())
        {
            pop_heap(minHeap.begin(),minHeap.end(),std::greater<>{});
            minHeap.pop_back();
            minHeap.push_back(nums[i]);
            push_heap(minHeap.begin(),minHeap.end(),std::greater<>{});
        }
    }
    return minHeap;
  }
};

int main(int argc, char* argv[]) {
  vector<int> result = KLargestNumbers::findKLargestNumbers(vector<int>{3, 1, 5, 12, 2, 11}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  result = KLargestNumbers::findKLargestNumbers(vector<int>{5, 12, 11, -1, 12}, 3);
  cout << "Here are the top K numbers: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;
}
