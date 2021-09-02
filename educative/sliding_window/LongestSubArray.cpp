//https://www.careercup.com/question?id=5657171669286912
//
#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class ReplacingOnes {
 public:
  static int findLength(const vector<int>& arr, int k) {
    int  maxLength = 0;
    int windowStart = 0 , windowEnd = 0;
    unordered_map<int,int> numberFreqMap;
    for( ; windowEnd < arr.size(); ++windowEnd )
    {
         numberFreqMap[arr[windowEnd]]++;
         int zeroCountInWindow = numberFreqMap[0];
         if(zeroCountInWindow > k)
         {
             --numberFreqMap[arr[windowStart]];
             ++windowStart;
         }
         maxLength = max(maxLength,windowEnd - windowStart + 1);
    }
    return maxLength;
  }
};

int main(int argc, char* argv[]) {
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 1, 0, 0, 0, 1, 1, 0, 1, 1}, 2) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0, 1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
  cout << ReplacingOnes::findLength(vector<int>{0 ,1, 0, 0, 1, 1, 0, 1, 1, 0, 0, 1, 1}, 3) << endl;
}
