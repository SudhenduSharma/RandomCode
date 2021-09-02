#include <iostream>
#include <vector>
using namespace std;

class AverageOfSubarrayOfSizeK {
 public:
  //brute force O(n*k)
  static vector<double> findAverages(int K, const vector<int>& arr) {
    vector<double> result(arr.size() - K + 1);
    for (int i = 0; i <= arr.size() - K; i++) {
      // find sum of next 'K' elements
      double sum = 0;
      for (int j = i; j < i + K; j++) {
        sum += arr[j];
      }
      result[i] = sum / K;  // calculate average
    }

    return result;
  }

  //brute force O(n*k)
  static vector<double> findAveragesOptimized(int K, const vector<int>& arr) {
    //TODO assert
    vector<double> result(arr.size() - K + 1);
    double sum = 0;
    for(int i = 0; i< K; ++i)
    {
        sum += arr.at(i);
    }
    result[0] = sum/K;

    for (int i = 1; i < arr.size()-K+1; i++) {
      cout << sum << endl;
      sum = (sum -arr.at(i-1)+arr.at(i+K-1));
      result[i] = sum/K;  // calculate average
    }

    return result;
  }
  static vector<double> findAveragesOptimizedCleanCode(int K, const vector<int>& arr) {
    vector<double> result(arr.size() - K + 1);
    double windowSum = 0;
    int windowStart = 0;
    for (int windowEnd = 0; windowEnd < arr.size(); windowEnd++) {
      windowSum += arr[windowEnd];  // add the next element
      // slide the window, we don't need to slide if we've not hit the required window size of 'k'
      if (windowEnd >= K - 1) {
        result[windowStart] = windowSum / K;  // calculate the average
        windowSum -= arr[windowStart];        // subtract the element going out
        windowStart++;                        // slide the window ahead
      }
    }

    return result;
  }
};



int main(int argc, char* argv[]) {
  vector<double> result =
      AverageOfSubarrayOfSizeK::findAverages(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
  cout << "Averages of subarrays of size K: ";
  for (double d : result) {
    cout << d << " ";
  }
  cout << endl;

  vector<double> result1 =
      AverageOfSubarrayOfSizeK::findAveragesOptimized(5, vector<int>{1, 3, 2, 6, -1, 4, 1, 8, 2});
  cout << "Averagesi Opt of subarrays of size K: ";
  for (double d : result1) {
    cout << d << " ";
  }
  cout << endl;
}

