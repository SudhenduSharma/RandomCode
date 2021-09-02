#include<iostream>
#include <type_traits>
#include <thread>
#include <utility>
using namespace std;
enum struct PT : int
{
    PT_1,
    PT_2
};  

enum struct ST : int
{
    ST_1,
    ST_2
};

struct A{
    typedef int int_t;

};

struct B{
    typedef long long_t;

};
struct C{
    typedef double double_t;

};
struct D{
    typedef char char_t;

};

template <typename T>
class HasCharT
{
private:
    typedef char YesType[1];
    typedef char NoType[2];

    template <typename C> static YesType& test( decltype(&C::char_t) ) ;
    template <typename C> static NoType& test(...);


public:
    enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
};



template<typename T,typename std::enable_if<HasCharT<T>::value,void>::type >
void foo(const T& t)
{
    //check if T has define typedef char_t
    typedef typename T::char_t mytype;
    std::cout << "I have  char_t" << std::endl;
    //typedef decltype(T::char_t) mytype;
    //typedef  decltype(has_char_t<T>::type) mytype;
    //using std::enable_if_t = typedef std::enable_if<T::char_t>;
}

template<typename T>
void foo(const T& t)
{
    std::cout << "I don't have char_t" << std::endl;
    //check if T has define typedef char_t
    //typedef decltype(T::char_t) mytype;
    //typedef  decltype(has_char_t<T>::type) mytype;
    //using std::enable_if_t = typedef std::enable_if<T::char_t>;
}

template<std::size_t, PT pt, ST st>
struct Work
{   
    void foo()
    {   
       // cout<<"std::size_t, PT pt, ST s"<<std::endl;
    }
};

template<typename ... Types>
void callable(Types ... args)
{

}

int main()
{
    typedef Work<0,PT::PT_1,ST::ST_1> WorkType1;
    WorkType1 w1;
    w1.foo();
    std::thread t1(&WorkType1::foo,w1);

    foo(C());
    foo(D());

    t1.join();
    return 0;
}
