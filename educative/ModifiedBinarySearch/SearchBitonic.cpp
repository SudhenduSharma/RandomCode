using namespace std;

#include <iostream>
#include <vector>

class SearchBitonicArray {
 public:
     static int indexOfMaxElement(const vector<int> &arr){
         int start = 0;
         int end = arr.size()-1;
         int midIndex = (start+end)/2;
         while(start < end)
         {
             midIndex = (start+end)/2;
             if((arr[midIndex] > arr[midIndex+1]) &&
                     (arr[midIndex-1] < arr[midIndex])
                     )
                return midIndex;
             else if (arr[midIndex] < arr[midIndex+1])
             {
                start = midIndex + 1  ;
             }
             else if(arr[midIndex+1] < arr[midIndex])
             {
                 end = midIndex - 1 ;
             }
         }
         return start;
     }

     static int binarySearch(const vector<int> &arr,int key,int start, int end, bool asc)
     {
         int midIndex = (start+end)/2;
         while(start <= end)
         {
             midIndex = (start+end)/2;
             if( key == arr[midIndex] )
                 return midIndex;
             if(asc)
             {
                 if ( arr[midIndex] < key  )
                     start = midIndex + 1;
                 else
                     end = midIndex - 1;
             }
             else
             {
                 if ( arr[midIndex] > key  )
                     start = midIndex + 1;
                 else
                     end = midIndex - 1;
             }
         }
         return -1;
     }
  static int search(const vector<int> &arr, int key) {
      int midIndex = indexOfMaxElement(arr);
      int res = binarySearch(arr,key,0,midIndex,true);
      if(-1 != res)
          return res;
      res = binarySearch(arr,key,midIndex,arr.size()-1,false);
    return res;
  }
};

int main(int argc, char *argv[]) {
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 4, 3}, 4) << endl;
  cout << SearchBitonicArray::search(vector<int>{3, 8, 3, 1}, 8) << endl;
  cout << SearchBitonicArray::search(vector<int>{1, 3, 8, 12}, 12) << endl;
  cout << SearchBitonicArray::search(vector<int>{10, 9, 8}, 10) << endl;
}
