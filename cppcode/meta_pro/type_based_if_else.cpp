#include <type_traits> 
#include <map> 
#include <iostream>
using namespace std;
struct A
{
    int val1;
};
struct B
{
    int val;
};

struct C
{
    int val;
};
// class template:
class MessageHandler
{
    typedef std::pair<int,int> key_t;
    std::map<key_t, A> mapA;
    std::map<key_t, B> mapB;
    std::map<key_t, C> mapC;

public:
    template <class T>
    void process (T& arg) 
    {
        if (std::is_same<T, A>::value)   // <== Decision based on type A
        {
            std::cout << "handle for type A" << endl;
            key_t key;
            key.first = arg.val;
        }

        if (std::is_same<T, B>::value)  // <== Decision based on type B
        {
            std::cout << "handle for type B" << endl;
        }

        if (std::is_same<T, C>::value)  // <== Decision based on type C
        {
            std::cout << "handle for type C" << endl;
        }
    }
};

int main()
{
    MessageHandler handler;
    A aObj;
    B bObj;
    handler.process(aObj);
    handler.process(bObj);

}
