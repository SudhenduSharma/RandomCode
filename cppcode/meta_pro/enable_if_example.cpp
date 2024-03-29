// SFINAE, enable_if example
// based on http://stackoverflow.com/questions/257288/is-it-possible-to-write-a-c-template-to-check-for-a-functions-existence


#include <iostream>
#include <type_traits>

class ClassWithToString
{
public:
    std::string ToString() { return "description of ClassWithToString object"; }
};

class ClassNoToString
{
public:
    void fptr();
    int a;
};

void fptr(int)
{

}

typedef void (*fun_ptr)(int);




// SFINAE test
template <typename T>
struct HasToString
{
    typedef char YesType[1];
    typedef char NoType[2];

    template <typename C> static YesType& test( decltype(&C::ToString) ) {static YesType obj; obj[0] = 'a'; return obj;}
    template <typename C> static NoType& test(...){static NoType obj; obj[0] = 'b'; return obj;}
    void test(fun_ptr f);
    void g();

public:
    enum { value = sizeof(test<T>(0)) == sizeof(YesType) };
};


template<typename T> 
struct MembFun
{
    typedef void (T::*function)();
};

typedef MembFun


template<typename T> 
typename std::enable_if<HasToString<T>::value, std::string>::type
CallToString(T * t) {
   /* something when T has toString ... */
   return t->ToString();
}

/*
template<typename T> 
typename std::enable_if<std::is_class<T>::value, std::string>::type
CallToString(T * t) {
   return "a class without ToString() method!";
}
*/

std::string CallToString(...)
{
    return "undefined object, cannot call ToString() method here";
}


int main(int argc, char *argv[])
{
    /*std::cout << HasToString<ClassWithToString>::value << std::endl;
    std::cout << HasToString<ClassNoToString>::value << std::endl;
    std::cout << HasToString<int>::value << std::endl;
    */
    std::cout << "*******" << std::endl;
    std::cout << HasToString<ClassWithToString>::test<int>(0) << std::endl;
    std::cout << HasToString<ClassWithToString>::test<ClassWithToString>(0) << std::endl;
    std::cout << HasToString<ClassWithToString>::test<ClassNoToString>(0) << std::endl;
    std::cout << "*******" << std::endl;
    
    ClassWithToString c1;
    std::cout << CallToString(&c1) << std::endl;
    
    ClassNoToString c2;
    std::cout << CallToString(&c2) << std::endl;
    
    int c3 = 0;
    std::cout << CallToString(&c3) << std::endl;

    fun_ptr obj = fptr;
    
    return 0;
}
