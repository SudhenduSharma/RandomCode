#include <iostream>
template <size_t M, size_t N>
struct PowerOf
{
    enum { res = M * PowerOf<M,N-1>::res };
};

template<size_t M>
struct PowerOf<M,0>
{
    enum { res = 1 };
};

int main()
{
    std:: cout << PowerOf<5 ,3> :: res << std::endl;
    std:: cout << PowerOf<5 ,12> :: res << std::endl;
    return 0;
}
