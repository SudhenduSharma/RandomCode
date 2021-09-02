using namespace std;

#include <iostream>
#include <vector>

class FindRange {
 public:
  static pair<int, int> findRange(const vector<int> &arr, int key) {
    pair<int, int> result(-1, -1);
    int start = 0;
    int end = arr.size()-1;
    bool keyFound = false;
    int midIndex = start + (end-start)/2;
    while(start <= end)
    {
        midIndex = start + (end-start)/2;
        if(key < arr[midIndex])
        {
            end = midIndex - 1;
        }
        else if(key > arr[midIndex])
        {
            start = midIndex + 1;
        }
        else
        {
            keyFound = true;
            break;
        }
    }   
    if(keyFound)
    {
        int startIndex = midIndex;
        while(startIndex > -1 && key ==  arr[startIndex])
            --startIndex;
        int endIndex = midIndex;
        while(endIndex < arr.size() && arr[endIndex] == key)
            ++endIndex;
        result.first = startIndex+1;
        result.second = endIndex-1;
    }
    return result;
  }
};

int main(int argc, char *argv[]) {
  pair<int, int> result = FindRange::findRange(vector<int>{4, 6, 6, 6, 9}, 6);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 10);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
  result = FindRange::findRange(vector<int>{1, 3, 8, 10, 15}, 12);
  cout << "Range: [" << result.first << ", " << result.second << "]" << endl;
}
