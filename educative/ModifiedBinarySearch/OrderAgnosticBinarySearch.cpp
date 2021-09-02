using namespace std;

#include <iostream>
#include <vector>

class BinarySearch {
 public:
     static int searchAsc(const vector<int>& arr, int key,int start,int end)
     {
         while(start <= end)
         {
             int midIndex = (start+end+1)/2;
             if( key < arr[midIndex] )
             {
                 end = midIndex;
             }
             else if(key > arr[midIndex] )
             {
                 start = midIndex;
             }
             else if (key == arr[midIndex])
             {
                 return midIndex;
             }
             else
                 return -1;
         }
         return -1;
     }

     static int searchDsc(const vector<int>& arr, int key,int start,int end)
     {
         while(start <= end)
         {
             int midIndex = (start)+(end-start)/2;
             if (key == arr[midIndex])
             {
                 return midIndex;
             }
             if(key > arr[midIndex] )
             {
                 end = midIndex -1;
             }
             else 
             {
                 start = midIndex+1;
             }
         }
         return -1;
     }

       static int search(const vector<int>& arr, int key) {
    // TODO: Write your code here
    int start = 0;
    int end = arr.size()-1;

    int isAscending = false;
    if(arr[end] > arr[start])
        return searchAsc(arr,key,start ,end);
    else
        return searchDsc(arr,key,start ,end);
  }
};

int main(int argc, char* argv[]) {
  cout << BinarySearch::search(vector<int>{4, 6, 10}, 10) << endl;
  cout << BinarySearch::search(vector<int>{1, 2, 3, 4, 5, 6, 7}, 5) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 10) << endl;
  cout << BinarySearch::search(vector<int>{10, 6, 4}, 4) << endl;
}
