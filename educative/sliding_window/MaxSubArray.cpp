
#include <iostream>
#include <vector>

using namespace std;
class MaxSumSubArrayOfSizeK {
    public:
        static int findMaxSumSubArray(int k, const vector<int>& arr) {
            int maxSum = 0;
            for(int i = 0; i < k ;++i)
            {
                maxSum += arr[i];
            }
            //cout<< "k = " << k << " maxSum" << maxSum << endl;


            int winsowStart = 1;
            int windowEnd = arr.size() - k;
            int windowSum = maxSum;
            cout << arr.size() << " " << k << winsowStart  << "  " << windowEnd <<endl;
            for(int window = winsowStart; window <= windowEnd;++window)
            {

                windowSum += arr[window+k-1] - arr[window-1];
                cout << "window " << window << "windowSum " << windowSum << endl;
                if(maxSum< windowSum)
                {
                    maxSum = windowSum;
                }
            }

            // TODO: Write your code here
            return maxSum;
        }
        static int findMaxSumSubArrayClean(int k, const vector<int>& arr) {
            int windowSum = 0, maxSum = 0;
            int windowStart = 0;
            for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
                windowSum += arr[windowEnd];  // add the next element
                // slide the window, we don't need to slide if we've not hit the required window size of 'k'
                if (windowEnd >= k - 1) {
                    maxSum = max(maxSum, windowSum);
                    windowSum -= arr[windowStart];  // subtract the element going out
                    windowStart++;                  // slide the window ahead
                }
            }
        };

        int main()
        {
            vector<int> arr = {2,1,5,1,3,2};
            cout << arr.size() << " " << endl;
            int max = MaxSumSubArrayOfSizeK::findMaxSumSubArray(3,arr);
            cout<< max;
            return 0;
        }
