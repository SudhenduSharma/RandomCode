using namespace std;

#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

class MaxSumSubArrayOfSizeK {
 public:
  static int findMaxSumSubArray(int k, const vector<int>& arr) {
      int windowSum=  std::accumulate(arr.begin(),arr.begin()+k,0);
      int maxSum = windowSum;
      //cout << windowSum << endl;
      auto it = arr.begin()+k;
      for(;it!=arr.end();++it)
      {
          windowSum += *it - *(it-k);
          maxSum = max(windowSum,maxSum);
      }
      return maxSum;
  }
};

int main(int argc, char* argv[]) {
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(3, vector<int>{2, 1, 5, 1, 3, 2}) << endl;
  cout << "Maximum sum of a subarray of size K: "
       << MaxSumSubArrayOfSizeK::findMaxSumSubArray(2, vector<int>{2, 3, 4, 1, 5}) << endl;
}
