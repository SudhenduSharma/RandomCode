#include<iostream>
#include<queue>
using namespace std;
class MedianOfAges{
    public:
        priority_queue<int> maxHeap_;//first half of numbers
        priority_queue<int,std::vector<int>,greater<int>> minHeap_;//second half of numbers
        auto insertNum(int age)
        {
            maxHeap_.push(age); //add to heap containing small numbers
            //balance
            minHeap_.push(maxHeap_.top());
            maxHeap_.pop();
            //ideally maxHeap must contain at most +1 element or equal
            if(maxHeap_.size() < minHeap_.size())
            {
                maxHeap_.push(minHeap_.top());
                minHeap_.pop();
            }
        }
};

int main() {
    MedianOfAges medianOfAges;
    medianOfAges.insertNum(22);
    medianOfAges.insertNum(35);
    std::cout << "The recommended content will be for ages under: " << std::to_string(medianOfAges.findMedian()) << std::endl;
    medianOfAges.insertNum(30);
    std::cout << "The recommended content will be for ages under: " << std::to_string(medianOfAges.findMedian()) << std::endl;
    medianOfAges.insertNum(25);
    std::cout << "The recommended content will be for ages under:  " <<  std::to_string(medianOfAges.findMedian()) << std::endl;
    return 0;
}
