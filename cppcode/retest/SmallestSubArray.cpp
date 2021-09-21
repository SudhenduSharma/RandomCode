#include <iostream>
#include <limits>
#include <vector>

using namespace std;
class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
      int windowStart = 0;
      int windowEnd = 0;
      int windowSum = arr[0];
      int windowSize = arr.size();
      for(int i = 1 ; i < arr.size() ; ++i)
      {
          //grow
          windowSum += arr[i];
          if(windowSum > S)
          {
              windowSize = windowEnd -windowEnd;
          }
          else
          {
            ++windowEnd;
          }
          

      }

  }
};

int main(int argc, char* argv[]) {
  int result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 3, 2});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(7, vector<int>{2, 1, 5, 2, 8});
  cout << "Smallest subarray length: " << result << endl;
  result = MinSizeSubArraySum::findMinSubArray(8, vector<int>{3, 4, 1, 1, 6});
  cout << "Smallest subarray length: " << result << endl;
}

