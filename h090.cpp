// https://zerojudge.tw/ShowProblem?problemid=h090
#include <iostream>
using namespace std;


const int MAX_N = 2e5;
string S;
int pre[MAX_N] = {0};
int pow10[MAX_N] = ;
int pow2[MAX_N];
int main()
{
    cin >> S;
    pre[0] = S[0] - '0';
    for(int i=1;i<S.size();++i)
        pre[i] = pre[i-1] + S[i] - '0';
    for(int i=0;i<S.size();++i){
        
    }
    return 0;
}
