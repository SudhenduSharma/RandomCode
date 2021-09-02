// unordered_map::emplace
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;
int main ()
{
  std::unordered_map<std::string,std::string> mymap;

  //note about std::piecewise_construct  and use of std::forward to reduce move
  auto pair = mymap.emplace (std::piecewise_construct,
                 std::forward_as_tuple("id"),
                 std::forward_as_tuple("insered val"));
  if(pair.second)
  {
      //emplace succcessful
      cout<< "emplace succcessful" <<endl;
      cout << pair.first->second << " and it's addr " <<  &pair.first->second  << endl;
  }
  else
  {
      cout<< "already exists" <<endl;
  }
  mymap.emplace ("NCC-1701-D", "J.L. Picard");
  mymap.emplace ("NCC-74656", "K. Janeway");

  std::cout << "mymap contains:" << std::endl;
  for (auto& x: mymap)
    std::cout << x.first << ": " << x.second << std::endl;

  std::cout << std::endl;
  return 0;
}
