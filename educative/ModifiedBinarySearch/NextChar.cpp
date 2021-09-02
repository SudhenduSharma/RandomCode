using namespace std;

#include <iostream>
#include <vector>

class NextLetter {
 public:
  static char searchNextLetter(const vector<char>& letters, char key) {
      if(letters.size() == 0)
          return 0;
      if(key < letters[0] || key > letters[letters.size()-1])
        return letters[0];
      int start = 0;
      int end = letters.size()-1;
      int midIndex = -1;
      while(start <= end)
      {
          midIndex = (start+end)/2;
          if(letters[midIndex] == key)
          {
              break;
          }
          else if( key < letters[midIndex] )
          {
              end = midIndex - 1;
          }
          else
          {
              start = midIndex + 1;
          }
      }

      if(midIndex == (letters.size()-1))
          midIndex = 0;
      else
          ++midIndex;

      return letters[midIndex];

  }
};

int main(int argc, char* argv[]) {
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'f') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'b') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'm') << endl;
  cout << NextLetter::searchNextLetter(vector<char>{'a', 'c', 'f', 'h'}, 'h') << endl;
}
