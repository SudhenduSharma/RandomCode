#include<iostream>
using namespace std;

int LongestCommonSubsequence(const string&  s1, const string& s2, size_t s1i, size_t s2i)
{
	if(s1i >= s1.length() || s2i >= s2.length())
	{
			return 0;
	}
    int len = 0;
	if(s1[s1i] == s2[s2i])
	{
		len = 1 + LongestCommonSubsequence(s1,s2,s1i+1,s2i+1);
	}
	int len1 = LongestCommonSubsequence(s1,s2,s1i,s2i+1);
    
	int len2 = LongestCommonSubsequence(s1,s2,s1i+1,s2i);
    //cout << " s1i " << s1i << " len1 " << len1 << " len2 " << len2 << " s2i " << s2i << endl;
	return max(len,max(len1,len2));
}

int main()
{
    cout << LongestCommonSubsequence("a","c",0,0) << " a c Expected 0"  << endl;
    cout << LongestCommonSubsequence("a","a",0,0)  << " a a Expected 1" << endl;
    cout << LongestCommonSubsequence("aa","aa",0,0) << "  aa  aa Expected 2" << endl;
    cout << LongestCommonSubsequence("aaa","abaa",0,0) << "  aa abaa Expected 3"  << endl;
    cout << LongestCommonSubsequence("abaa","aa",0,0) << "  abaa aa Expected 2"  << endl;

    cout << LongestCommonSubsequence("abdca","cbda",0,0)<< "  abdca cdba Expected 3"  << endl;
    return 0;
}
