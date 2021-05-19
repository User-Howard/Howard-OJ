#include<iostream>
#include<algorithm>
#define FOR(i, x) for(int i=0;i<x;i++)
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, ans=0;
    int arr[65];
    cin>>N;
    for (int i=0;i<N;i++)
        cin>>arr[i];    
    for (int i=0;i<N;i++) {
        if (arr[i]<=25)
            ans++;
    }
    cout<<min(ans, 5)<<endl;
    return 0;
}
