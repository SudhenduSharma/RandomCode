#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
#include<utility>
#include <numeric>
using namespace std;
class MaxSumSubArrayOfSizeK
{
    public :
        static int findMaxSumSubArray(int k,vector<int> arr)
        {
            //TODO assert array size >k
           int windowStart = 0;
           int windowEnd = k-1;
           int maxSum = std::accumulate(arr.begin(),arr.begin()+k,0);
           int windowSum = maxSum;
           for(int i = k; i < arr.size(); ++i)
           {
               ++windowEnd;
               ++windowStart;
               windowSum = windowSum + arr[windowEnd] - arr[windowStart-1];
               if(windowSum > maxSum)
               {
                   maxSum = windowSum;
               }
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
