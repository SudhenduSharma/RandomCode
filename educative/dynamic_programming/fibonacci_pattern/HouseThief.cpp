using namespace std;

#include <iostream>
#include <vector>

class HouseThief {
public:
  int findMaxSteal(const vector<int> &wealth) { return findMaxStealRecursive(wealth, 0); }

private:
  int findMaxStealRecursive(const vector<int> &wealth, int currentIndex) {
      if(currentIndex >= wealth.size())
          return 0;
      //steal from i-th house and skip i+1-th house
      int profitFromWay1 = wealth[currentIndex] + findMaxStealRecursive(wealth,currentIndex+2);
      //steal from i+1-th house and skip i-th house
      int profitFromWay2 =  findMaxStealRecursive(wealth,currentIndex+1);
      return max(profitFromWay1,profitFromWay2);
  }
};

int main(int argc, char *argv[]) {
  HouseThief *ht = new HouseThief();
  vector<int> wealth = {2, 5, 1, 3, 6, 2, 4};
  cout << ht->findMaxSteal(wealth) << endl;
  wealth = vector<int>{2, 10, 14, 8, 1};
  cout << ht->findMaxSteal(wealth) << endl;

  delete ht;
}
