using namespace std;

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

template<typename T,class Container = vector<T>,class compare = less<typename Container::value_type> >
class priority_queue_with_remove : public priority_queue<T,Container,compare>
{
    public :
        bool remove(const T& value)
        {
            auto itr = std::find(this->c.begin(),this->c.end(),value);
            //why doesn't it work ?? since c is protected so access it via this pointer --> auto itr = std::find(c.begin(),c.end(),value); 
            if(itr == this->c.end())
            {
                return false;
            }
            this->c.erase(itr);
            std::make_heap(this->c.begin(),this->c.end(),this->comp);
            return true;
        }
        void print()
        {
            for(auto c : this->c){
                cout << " " << c << " ";
            } 
            cout << endl;

        }
};

class SlidingWindowMedian {
 public:

     void addElementTwoHeap(int val)
     {
         if(maxHeap.empty()||val<= maxHeap.top())
         {
             maxHeap.push(val);
         }
         else
         {
             minHeap.push(val);
         }
         rebalanceHeaps();
     }
     double getMedianTwoHeap()
     {
         /*cout << " maxHeap " << endl;
         maxHeap.print();
         cout << " minHeap " << endl;
         minHeap.print();
         */
         //TODO assert
         if (maxHeap.size() == minHeap.size()) {
             return maxHeap.top() / 2.0 + minHeap.top() / 2.0;
         }
         else
         {
             return maxHeap.top();
         }
     }
     void rebalanceHeaps() {
         // either both the heaps will have equal number of elements or max-heap will have
         // one more element than the min-heap
         if (maxHeap.size() > minHeap.size() + 1) {
             minHeap.push(maxHeap.top());
             maxHeap.pop();
         } else if (maxHeap.size() < minHeap.size()) {
             maxHeap.push(minHeap.top());
             minHeap.pop();
         }
     }
     void removeElementTwoHeap(int elementToBeRemoved)
     {
         if (elementToBeRemoved <= maxHeap.top()) {
          maxHeap.remove(elementToBeRemoved);
        } else {
          minHeap.remove(elementToBeRemoved);
        }
     }

  virtual vector<double> findSlidingWindowMedian(const vector<int> &nums, int k) {
    vector<double> result;
    int windowStart = 0;
    int windowEnd = 0;
    for(; windowEnd < nums.size();++windowEnd)
    {
        //keep building minHeap and MaxHeap until window size k
        addElementTwoHeap(nums[windowEnd]);
        if(windowEnd-windowStart+1 == k)
        {
            break;
        }
    }
    while(windowEnd < nums.size())
    {
            cout << windowEnd << "-" << windowStart << "+1 = " << k << endl;
            //calculate median and pushback to result
            result.push_back(getMedianTwoHeap());
            //remove element at window start
            removeElementTwoHeap(nums[windowStart]);
            ++windowStart;
            ++windowEnd;
            if(windowEnd == nums.size())
                break;
            addElementTwoHeap(nums[windowEnd]);
    }
    return result;
  }
  priority_queue_with_remove<int> maxHeap;
  priority_queue_with_remove<int,vector<int> , greater<int>> minHeap;
};

int main(int argc, char *argv[]) {
  SlidingWindowMedian slidingWindowMedian;
  vector<double> result =
      slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 2);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
  cout << endl;

  slidingWindowMedian = SlidingWindowMedian();
  result = slidingWindowMedian.findSlidingWindowMedian(vector<int>{1, 2, -1, 3, 5}, 3);
  cout << "Sliding window medians are: ";
  for (auto num : result) {
    cout << num << " ";
  }
}
