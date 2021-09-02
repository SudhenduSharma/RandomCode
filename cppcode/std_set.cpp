#include<iostream>
#include<set>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    std::set<int> setOfNumbers;

    setOfNumbers.insert(1);
    setOfNumbers.insert(2);
    setOfNumbers.insert(3);
    setOfNumbers.insert(4);
    setOfNumbers.insert(6);
    setOfNumbers.insert(8);
    std::cout << "Size " << setOfNumbers.size() << std::endl;
    std::cout << "Reverse Print " << std::endl;
    for(auto it = setOfNumbers.rbegin(); it != setOfNumbers.rend(); ++it)
    {
        std::cout << ' ' << *it;
        //*it = 10; //can not modify a const
    }

    std::cout << endl << "finding Nemo" << endl;
    auto it_find = setOfNumbers.find(4);
    if(it_find!= setOfNumbers.end())
    {
        std::cout << "found " << *it_find << " in set"<<endl;
    }

    int lower_bound = 5;
    int upper_bound = 7;
    auto itlow=setOfNumbers.lower_bound (lower_bound);  // itlow points to 
    std::cout << "--lower of 5 -->" << *itlow << std::endl;
    auto itup=setOfNumbers.upper_bound (upper_bound);   // itup points to 
    std::cout << "--upper  of 7 -->" << *itup << std::endl;
    setOfNumbers.erase(itlow,itup);        // erases [itlow,itup)
    std::cout << endl;

    auto newSet = std::move(setOfNumbers); //empty setOfNumbers
    //auto newSet = setOfNumbers; //Deep Copy
    for(auto it = setOfNumbers.begin(); it != setOfNumbers.end(); ++it)
    {
        std::cout << ' ' << *it;
        //*it = 10; //can not modify a const
    }

}
