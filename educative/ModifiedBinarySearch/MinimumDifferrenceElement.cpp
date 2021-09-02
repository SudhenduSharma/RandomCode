using namespace std;

#include <iostream>
#include <vector>

class MinimumDifference {
 public:
  static int searchMinDiffElement(const vector<int>& arr, int key) {
      int start = 0;
      int end = arr.size();
      int midIndex = start + (end -start)/2;
      while(start <= end)
      {
          midIndex = start + (end -start)/2;
          if(key < arr[midIndex])
          {
              end = midIndex - 1;
          }
          else if( key > arr[midIndex] )
          {
              start = midIndex + 1 ;
          }
          else
          {
              return arr[midIndex];
          }
      }
      if(end < 0)
          return arr[0];
      if(start >= arr.size())
          return arr[arr.size()-1];
      if((arr[start] - key ) < (key-arr[end]))
          return arr[start];
      else
          return arr[end];
    return -1;
  }
};

int main(int argc, char* argv[]) {
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 7) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 4) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << MinimumDifference::searchMinDiffElement(vector<int>{4, 6, 10}, 17) << endl;
}
