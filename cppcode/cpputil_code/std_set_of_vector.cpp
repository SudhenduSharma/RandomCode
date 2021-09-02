 #include <iostream>
 #include <string>
 #include <unordered_map>

#include <set>
#include <vector>
using namespace std;
  
set<vector<int> > set_of_vectors;
  
// Print elements of Vector
void Print_Vector(vector<int> Vec)
{
    for (int i = 0; i < Vec.size(); i++) {
        cout << Vec[i] << " ";
    }
    cout << endl;
    return;
}
  
// Driver code
int main()
{
    // Initializing some vectors
    vector<int> data_1{ 10, 20, 30, 40 };
    vector<int> data_2{ 5, 10, 15 };
    vector<int> data_3{ 1, 3, 5, 7, 9, 11, 13 };
    vector<int> data_4{ 5, 10, 15 };
    vector<int> data_5{ 10, 20, 30, 40 };
  
    // Inserting vectors into set
    set_of_vectors.insert(data_1);
    set_of_vectors.insert(data_2);
    set_of_vectors.insert(data_3);
    set_of_vectors.insert(data_4);
    set_of_vectors.insert(data_5);

    auto it = set_of_vectors.find(data_3);
    if(it != set_of_vectors.end())
    {
        std::cout << "found" << std::endl;
        *it->push_back(100);
    }
  
    // printing all the unique vectors in set
    cout << "Set of Vectors: \n";
    for (auto it = set_of_vectors.begin();
         it != set_of_vectors.end();
         it++) {
  
        Print_Vector(*it);
    }
  
    return 0;
}
