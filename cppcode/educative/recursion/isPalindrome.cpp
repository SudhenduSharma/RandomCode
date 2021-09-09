#include<iostream>
#include<vector>

using namespace std;

bool isPalindrom(vector<char>& str, int i1, int i2)
{
    if(i2 < i1)
        return true;
    if(str[i1] == str[i2])
    {
        //reduce
        return isPalindrom(str, i1+1,i2 -1);
    }
    else
        return false;
    
}

int main()
{

    vector<char> str = {'a'};
    cout << isPalindrom(str,0,str.size()-1) << " expecting " << 1 << endl;
    str = {'a','a'};
    cout << isPalindrom(str,0,str.size()-1) << " expecting " << 1 << endl;
    str = {'a','b'};
    cout << isPalindrom(str,0,str.size()-1) << " expecting " << 0 << endl;

    str = {'a','b','b','c','b','b','a'};
    cout << isPalindrom(str,0,str.size()-1) << " expecting " << 1 << endl;
    return 0;

}
