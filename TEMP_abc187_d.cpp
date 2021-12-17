#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;


const int MAX_N = 2e5;
int main(){
    int N;
    int A[MAX_N], B[MAX_N];
    pair<int, int> S[100/*MAX_N*/];
    int sum_=0;
    cin >> N;

    for(int i=0;i<N;++i){
        cin >> A[i] >> B[i];
        sum_ += A[i] + B[i];
        S[i].first = 2*A[i] + B[i];
        S[i].second = i;
    }
    sort(S, S+N, greater<pair<int, int> >());
    int ssum = 0;
    for(int i=0;i<N;++i){
        ssum += 2*A[i] + B[i];
        if(ssum > sum_ / 2){
            cout << i+1 << '\n';
            break;
        }
    }
    return 0;
}
