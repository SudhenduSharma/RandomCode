#include<iostream>
using namespace std;

int LongestCommonSubstring(const string&  s1, const string& s2, size_t s1i, size_t s2i,int count)
{
	if(s1i >= s1.length() || s2i >= s2.length())
	{
			return count;
	}
    int len = 0;
	if(s1[s1i] == s2[s2i])
	{
        //TODO this case is broken that needs to be fixed
        //e.g. abacd adacd will return 4 instead 3 matchig first char a and then acd
		len = LongestCommonSubstring(s1,s2,s1i+1,s2i+1,count+1);
	}
	int len1 = LongestCommonSubstring(s1,s2,s1i,s2i+1,count);
    
	int len2 = LongestCommonSubstring(s1,s2,s1i+1,s2i,count);
    //cout << " s1i " << s1i << " len1 " << len1 << " len2 " << len2 << " s2i " << s2i << endl;
	return max(len,max(len1,len2));
}

int main()
{
    cout << LongestCommonSubstring("a","c",0,0,0) << " a c Expected 0"  << endl;
    cout << LongestCommonSubstring("a","a",0,0,0)  << " a a Expected 1" << endl;
    cout << LongestCommonSubstring("aa","aa",0,0,0) << "  aa  aa Expected 2" << endl;
    cout << LongestCommonSubstring("aaa","abaa",0,0,0) << "  aa abaa Expected 3"  << endl;
    cout << LongestCommonSubstring("abaa","aa",0,0,0) << "  abaa aa Expected 2"  << endl;

    cout << LongestCommonSubstring("abdca","cbda",0,0,0)<< "  abdca cdba Expected 3"  << endl;
    return 0;
}
