#include <iostream>
#include <vector>
using namespace std;
int* performOps(int *A, int len, int *blen) {
    int i;
    *blen = len * 2;
    int *B = (int *)malloc((*blen) * sizeof(int));
    for (i = 0; i < len; i++) {
        B[i] = A[i];
        B[i + len] = A[(len - i) % len];
    }
    return B;
}

vector<int> rotateArray(vector<int> &A, int B) {
    vector<int> ret;
    if(B > A.size())
    {
        B = B%A.size();
    }
    for (int i = B; i < A.size() ; i++) {
        ret.push_back(A[i]);
    }

    for (int i = 0; i < B ; i++) {
        ret.push_back(A[i]);
    }
    return ret;
}
 
int main() {
    std::vector<int> v = {1,2,6};
 
    auto v1 = rotateArray(v,5);

    for (int index = 0; const int& i : v1) // access by const reference
    {
     std::cout << v1[index] << ' ';
     index++;
    }
    std::cout << '\n';
 
int blen; 
int len =4 ;
int A[4] = { 5,10,2,1 };
int *B = performOps(A, len, &blen);
int i;
for (i = 0; i < blen; i++) {
    std::cout << B[i];
}
   return 0;
}
