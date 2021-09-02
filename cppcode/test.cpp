#include <iostream>
int main(){
    int p, q;

const char* fmt = "%s %s %i %i %s";
const char *input = "BUY GFD xyz 34 ordid";
char id[16] = {'\0'};
char side[4] = {'\0'};
char ot[4] = {'\0'};

    std::cout<<input<<std::endl;
    sscanf(input, fmt, side, ot, &p, &q, id);
    std::cout<<"id = "<<id<<std::endl;
    std::cout<<"side = "<<side<<std::endl;
    std::cout<<"ot = "<<ot<<std::endl;
    std::cout<<"p = "<<p<<std::endl;
    std::cout<<"q = "<<q<<std::endl;
}
