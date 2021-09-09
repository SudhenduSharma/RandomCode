using namespace std;

#include <iostream>
#include <vector>

class MaxInBitonicArray {
 public:
  static int findMax(const vector<int>& arr) {
      int start = 0;
      int end = arr.size() -1;
      int midIndex = start + (end-start)/2;
      while (start <= end)
      {
          midIndex = start + (end-start)/2;
          if(arr[midIndex] < arr[midIndex+1])
          {
              start = midIndex + 1;
          }
          else if( arr[midIndex] > arr[midIndex+1] )
          {
              end = midIndex - 1;
          }
          else 
              break;
      }
      if(end < 0)
          return arr[0];
      if(start >= arr.size())
          return arr[arr.size()-1];
      return max(arr[start],arr[end]);
  }

};

int main(int argc, char* argv[]) {
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12, 4, 2}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{3, 8, 3, 1}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{1, 3, 8, 12}) << endl;
  cout << MaxInBitonicArray::findMax(vector<int>{10, 9, 8}) << endl;
}
