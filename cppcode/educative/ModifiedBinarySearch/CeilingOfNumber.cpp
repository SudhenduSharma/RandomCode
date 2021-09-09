using namespace std;

#include <iostream>
#include <vector>

class CeilingOfANumber {
 public:
  static int searchCeilingOfANumber(const vector<int>& arr, int key) {
    if(arr.size() == 0 ||key > arr[arr.size()-1])
        return -1;
    if( key < arr[0] )
          return 0;

    int start = 0;
    int end = arr.size() -1;

    while(start <= end)
    {
        int midIndex = (start + end)/2;
        if(arr[midIndex] == key)
            return midIndex;
        else if(key < arr[midIndex])
        {
            end = midIndex - 1;
        }
        else 
        {
            start = midIndex + 1 ;
        }
    }
    return start;
  }
};

int main(int argc, char* argv[]) {
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 6}, 6) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{1, 3, 8, 10, 15}, 12) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, 17) << endl;
  cout << CeilingOfANumber::searchCeilingOfANumber(vector<int>{4, 6, 10}, -1) << endl;
}
