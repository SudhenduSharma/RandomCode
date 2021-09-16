#include<iostream>

using namespace std;

struct WithMemberFunFoo
{
    void foo(){
        cout << "WithMemberFunFoo :: foo " << endl;
    }
};
class WithoutMemberFunFoo
{
};
template<typename T>
struct HasFunction
{
    typedef char YesType[1];
    typedef char NoType[1];
    template<typename C>
    static YesType& test(decltype(&T::foo));

    template<typename C>
    static NoType& test(...);

    enum {val = sizeof(test<T>(0)) == sizeof(YesType) };
};
template<typename T>
typename std::enable_if<HasFunction<T>::val>
callFoo()
{
    T obj;
    obj.foo();
    //return string("CallFoo with");
}
void callFoo()
{

}
int main()
{
    cout <<  HasFunction<WithMemberFunFoo>::val << endl;
    callFoo<WithMemberFunFoo>();
    return 0;
}

