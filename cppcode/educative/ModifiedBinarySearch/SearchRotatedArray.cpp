using namespace std;

#include <iostream>
#include <vector>

class SearchRotatedArray {
 public:
  static int search(const vector<int>& arr, int key) {
      int start = 0;
      int end = arr.size()-1;
      while(start <= end)
      {
          int midIndex = start+(end-start)/2;
          if( key == arr[midIndex] )
            return midIndex;
          if(arr[start] < arr[midIndex])
          {
              if(key >= arr[start] && key < arr[midIndex])
              {
                  end = midIndex - 1;
              }
              else
              {
                  start = midIndex + 1;
              }

          }
          else
          {
              if(key > arr[midIndex] && key <= arr[end])
              {
                  start = midIndex + 1;
              }
              else
              {
                  end = midIndex - 1;
              }

          }
      }
    return start;
  }
};

int main(int argc, char* argv[]) {
  cout << SearchRotatedArray::search(vector<int>{10, 15, 1, 3, 8}, 15) << endl;
  cout << SearchRotatedArray::search(vector<int>{4, 5, 7, 9, 10, -1, 2}, 10) << endl;
}
