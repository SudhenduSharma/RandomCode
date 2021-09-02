using namespace std;

#include <iostream>
#include <limits>
#include <vector>

class ArrayJump {
public:
  int countMinJumps(const vector<int> &jumps) {
    return this->countMinJumpsRecursive(jumps, 0);
  }

private:
  int countMinJumpsRecursive(const vector<int> &jumps, int currentIndex) {
      if(currentIndex == jumps.size()-1)
          return 0;
      if(jumps[currentIndex] == 0)
          return INT_MAX;
    
      int minCount = INT_MAX;
      for ( int i = 1 + currentIndex; (i <= jumps[currentIndex] + currentIndex) && i < jumps.size() ;i++)
      {
          int count = countMinJumpsRecursive(jumps,i);
          if(count != INT_MAX)
            minCount = min(minCount,count +1 );
      }
      return minCount;
  }

      /*
    {
    // if we have reached the last index, we don't need any more jumps
    if (currentIndex == jumps.size() - 1) {
      return 0;
    }

    if (jumps[currentIndex] == 0) {
      return numeric_limits<int>::max();
    }

    int totalJumps = numeric_limits<int>::max();
    int start = currentIndex + 1;
    int end = currentIndex + jumps[currentIndex];
    while (start < jumps.size() && start <= end) {
      // jump one step and recurse for the remaining array
      int minJumps = countMinJumpsRecursive(jumps, start++);
      if (minJumps != numeric_limits<int>::max()) {
        totalJumps = min(totalJumps, minJumps + 1);
      }
    }
    return totalJumps;
  }
  */
};

int main(int argc, char *argv[]) {
  ArrayJump *aj = new ArrayJump();
  vector<int> jumps = {2, 1, 1, 1, 4};
  cout << aj->countMinJumps(jumps) << endl;
  jumps = vector<int>{1, 1, 3, 6, 9, 3, 0, 1, 3};
  cout << aj->countMinJumps(jumps) << endl;

  delete aj;
}
