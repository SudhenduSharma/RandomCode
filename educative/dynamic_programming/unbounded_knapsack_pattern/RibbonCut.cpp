
#include <iostream>
#include <limits>
#include <vector>

using namespace std;

class CutRibbon {

public:
  int countRibbonPieces(const vector<int> &ribbonLengths, int total) {
    int maxPieces = this->countRibbonPiecesRecursive(ribbonLengths, total, 0);
    return maxPieces == numeric_limits<int>::min() ? -1 : maxPieces;
  }

private:
  int countRibbonPiecesRecursive(const vector<int> &ribbonLengths, int total, int currentIndex) {
      if(total  == 0)
          return 0;
      if(currentIndex >= ribbonLengths.size())
          return INT_MIN;
      int count1 = INT_MIN;
      if(ribbonLengths[currentIndex] <= total)
      {
          int res = countRibbonPiecesRecursive(ribbonLengths, total-ribbonLengths[currentIndex], currentIndex);
          if(res != INT_MIN)
              count1 = res + 1;

      }
      int count2 = countRibbonPiecesRecursive(ribbonLengths, total, currentIndex+1);

      return max(count1,count2);

  }

  };

int main(int argc, char *argv[]) {
  CutRibbon *cr = new CutRibbon();
  vector<int> ribbonLengths = {2, 3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 5) << endl;
  ribbonLengths = vector<int>{2, 3};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;
  ribbonLengths = vector<int>{3, 5, 7};
  cout << cr->countRibbonPieces(ribbonLengths, 13) << endl;
  ribbonLengths = vector<int>{3, 5};
  cout << cr->countRibbonPieces(ribbonLengths, 7) << endl;

  delete cr;
}
