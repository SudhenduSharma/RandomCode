//https://www.cppstories.com/2016/02/notes-on-c-sfinae/
#include <iostream>
#include <type_traits>
using namespace std;

class ClassWithCharT
{
public:
    typedef char char_t;
};

class ClassNoCharT
{
public:
    int a;
};


// SFINAE test
template <typename T>
class HasNoCharT
{
private:
    typedef char YesType[1];
    typedef char NoType[2];

    template <typename C> static YesType& test( decltype(C::char_t) ) ;
    template <typename C> static NoType& test(...);


public:
    enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
};

template<typename T>
typename std::enable_if<HasNoCharT<T>::value>::type
foo(T t) {
    typedef typename T::char_t mytype;
    std::cout <<" typedef typename T::char_t mytype;" << std::endl;
}


template<typename T>
typename std::enable_if<!HasNoCharT<T>::value>::type
foo(T t) {
    std::cout <<" NOT ---- typedef typename T::char_t mytype;" << std::endl;
}
/*template<typename T>
void foo(T t)
{
    std::cout <<" no typedef typename T::char_t mytype;" << std::endl;
}*/


int main(int argc, char *argv[])
{
    std::cout << HasNoCharT<ClassWithCharT>::value << std::endl;
    std::cout << HasNoCharT<ClassNoCharT>::value << std::endl;
    std::cout << HasNoCharT<int>::value << std::endl;
    
    ClassWithCharT c1;
    foo<ClassWithCharT>(c1) ;
    
    ClassNoCharT c2;
    foo(c2);
    
    int c3 = 0;
    foo(c3);
    
    return 0;
}
