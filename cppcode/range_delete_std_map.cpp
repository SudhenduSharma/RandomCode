// map::lower_bound/upper_bound
#include <iostream>
#include <map>

int main ()
{
  std::map<int,int> mymap;
  std::map<int,int>::iterator itlow,itup;

  mymap[1]=10;
  mymap[3]=30;
  mymap[5]=50;
  mymap[7]=70;
  mymap[9]=90;
  mymap[11]=110;


  std::cout << "----" << std::endl;
  //auto it = mymap.find(9);
  mymap.erase(mymap.begin(),mymap.begin());

  for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';
return 0;
  int lower_bound = 6;
  int upper_bound = 8;
  itlow=mymap.lower_bound(lower_bound);  // itlow points to 7
  std::cout << "--lower of 6 -->" << itlow->first << std::endl;
  itup=mymap.upper_bound (upper_bound);   // itup points to 7
  std::cout << "--upper  of 8 -->" << itup->first << std::endl;
  std::cout << "map.erase(itlow,itup) i.e [itlow,itup)--> [" << itlow->first << "," << itup->first << ")"  << std::endl;


  mymap.erase(itlow,itup);        // erases [itlow,itup)

  // print content:
  for (std::map<int,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it)
    std::cout << it->first << " => " << it->second << '\n';

  return 0;
}
