using namespace std;

   #include <algorithm>
   #include <iostream>
   #include <queue>
   #include <vector>

   template<typename T,class Container = vector<T>,class compare = less<typename Container::value_type> >
   class priority_queue_with_remove : priority_queue<T,Container,greater<T>>
   {
       public :
           bool remove(const T& value)
           {
               auto itr = std::find(this->c.begin(),this->c.end(),value);
               //why doesn't it work ?? since c is protected so access it via this pointer --> auto itr =     std::find(c.begin(),c.end(),value);
               if(itr == this->c.end())
               {
                   return false;
               }
               this->c.erase(itr);
               std::make_heap(this->c.begin(),this->c.end(),this->comp);
               return true;
           }
   };

int main()
{
    priority_queue_with_remove<int> x;
    x.remove(0);
    return 0;
}
