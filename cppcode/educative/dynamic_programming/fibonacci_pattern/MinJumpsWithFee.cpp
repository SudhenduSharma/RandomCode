using namespace std;

#include <iostream>
#include <vector>

class Staircase {

public:
  int findMinFee(const vector<int> &fee) { return findMinFeeRecursive(fee, fee.size()); }

private:
  int findMinFeeRecursive(const vector<int> &fee, int currentIndex) {
      if(currentIndex == 0)
          return 0;
      if(currentIndex == 1)
          return fee[0];
      if(currentIndex == 2)
          return min(fee[0],fee[1]);
      int minFee = 0;
      int feeForStep1 = findMinFeeRecursive(fee,currentIndex-1) + fee[currentIndex-1];
      int feeForStep2 = findMinFeeRecursive(fee,currentIndex-2) + fee[currentIndex-2];
      int feeForStep3 = findMinFeeRecursive(fee,currentIndex-3) + fee[currentIndex-3];
      return min(feeForStep1,min(feeForStep2,feeForStep3));

  }
};

int main(int argc, char *argv[]) {
  Staircase *sc = new Staircase();
  vector<int> fee = {1, 2, 5, 2, 1, 2};
  cout << sc->findMinFee(fee) << endl;
  fee = vector<int>{2, 3, 4, 5,6,2,1,1};
  cout << sc->findMinFee(fee) << endl;

  delete sc;
}
