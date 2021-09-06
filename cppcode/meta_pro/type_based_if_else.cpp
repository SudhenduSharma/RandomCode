#include <type_traits> 
#include <map> 
#include <iostream>
using namespace std;
struct A
{
    int val1;
    int val2;
};
struct B
{
    int val1;
    int val2;
};

struct C
{
    int val1;
    int val2;
};
// class template:
class MessageHandler
{

public:
    template <typename ...Args>
    void process ( Args&& ...args) 
    {
        doProcess(std::forward<Args&&>(args)...);
    }
    void doProcess ( const A& arg) 
    {
        std::cout << "Type A" << std::endl;
    }
    /*
    void doProcess ( const A& arg,int) 
    {
        std::cout << "Type A int" << std::endl;
    }*/
    void doProcess ( const B& arg) 
    {
        std::cout << "Type B" << std::endl;
    }
    void doProcess (...) 
    {
        std::cout << "any other" << std::endl;
    }
};

int main()
{
    MessageHandler handler;
    A aObj;
    handler.doProcess(aObj,int());
    B bObj;
    handler.doProcess(bObj);
    handler.doProcess(int());

}
