#include<iostream>
//Sequence Container e.g. vector/deque/list
#include <vector>
#include <list>
#include <deque>
using namespace std;
int main()
{
    //pair
    {
        #include<utility>
        auto p = std::make_pair(1,"stringval");
        cout << p.first << " --> " << p.second << endl;
    }
    //Common for Sequence Container e.g. vector/deque/list
    list<int> sl;    deque<int> dq;      vector<int> v1;
    auto it = v1.insert(v1.end(),1);  //insert before iterator v1.end() return iterator
    v1.push_back(2);
    v1.pop_back();
    auto& front = v1.front();
    auto& back  = v1.back();
    for (const auto& i: v1)
      std::cout << i << ' ';
    //Vector Specific
    v1.capacity();
    v1.reserve(100);    //just reserve memory, no construtor
    v1.resize(100);     // reserve + initialize 
    v1.assign(sl.begin(), sl.end());    // copies the list sl into // the vector

}
