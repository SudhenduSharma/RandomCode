using namespace std;

#include <iostream>
#include <queue>
#include <algorithm>
#include <functional>
#include <vector>

class MedianOfAStream {
 public:
  virtual void insertNum(int num) {
    // TODO: Write your code here
    if(mMaxHeap.empty() )
    {
        mMaxHeap.push(num);
    }
    else
    {
        if(num > mMaxHeap.top())
            mMinHeap.push(num);
        else
            mMaxHeap.push(num);
    }
    adjustPartition();
  }
  void adjustPartition()
  {
      if( mMaxHeap.size()  > (mMinHeap.size() + 1))
      {
          mMinHeap.push(mMaxHeap.top());
          mMaxHeap.pop();
      }
      else if( mMaxHeap.size() < mMinHeap.size() )
      {
          mMaxHeap.push(mMinHeap.top());
          mMinHeap.pop();
      }
  }

  virtual double findMedian() {
      if( mMaxHeap.size() == mMinHeap.size() )
      {
          return (mMaxHeap.top() + mMinHeap.top() )/2.0;
      }
      return mMaxHeap.top();
  }
  private :
    priority_queue<int,vector<int>,greater<int>> mMaxHeap;
    priority_queue<int> mMinHeap;
};

int main(int argc, char *argv[]) {
  MedianOfAStream medianOfAStream;
  medianOfAStream.insertNum(3);
  medianOfAStream.insertNum(1);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(5);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
  medianOfAStream.insertNum(4);
  cout << "The median is: " << medianOfAStream.findMedian() << endl;
}
