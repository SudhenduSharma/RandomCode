
#include <iostream>
#include <limits>
#include <vector>
using namespace std;

class MinSizeSubArraySum {
 public:
  static int findMinSubArray(int S, const vector<int>& arr) {
    int minLength = numeric_limits<int>::max();
    int windowSum = 0;
	int windowStart = 0;
	for( int windowEnd = windowStart ; windowEnd < arr.size(); ++windowEnd)
    {
		windowSum += arr[windowEnd];
		// shrink the window as small as possible until the 'windowSum' is smaller than 'S'
		while(windowSum >= S)
		{
			minLength = min(minLength, windowEnd - windowStart +1);
 			windowSum -= arr[windowStart];
			windowStart++;
		}
	  
    }
    return minLength == numeric_limits<int>::max() ? 0 : minLength;;
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
