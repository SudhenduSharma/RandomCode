#include <iostream>
#include <vector>
 
int main() {
    std::vector<int> v = {0, 1, 2, 3, 4, 5};
 
    for (int index = 0; const int& i : v) // access by const reference
    {
     std::cout << i << ' ' << index << ' ';
     index++;
    }
    std::cout << '\n';
 

   return 0;
}
