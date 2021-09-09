using namespace std;

#include <iostream>
#include <vector>

class RotationCountOfRotatedArray {
 public:
  static int countRotations(const vector<int>& arr) {
      int start = 0;
      int end = arr.size()-1;
      while(start < end)
      {
        int midIndex = (start+end )/2;
          if(arr[midIndex] > arr[midIndex+1])
              return midIndex+1;
          if(arr[midIndex] > arr[start])
          {
              start = midIndex;
          }
          else
          {
              end = midIndex;
          }
      }
          return 0;
  }
};

int main(int argc, char* argv[]) {
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{10, 15, 1, 3, 8}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{4, 5, 7, 9, 10, -1, 2}) << endl;
  cout << RotationCountOfRotatedArray::countRotations(vector<int>{1, 3, 8, 10}) << endl;
}
