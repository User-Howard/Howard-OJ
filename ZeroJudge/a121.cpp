#include<iostream>
#include<string.h>
#define MAX_N 100000000
using namespace std;


int prime[MAX_N];
bool is_prime[MAX_N+1];

int SETX(int n){
    int r=0;

    memset(is_prime, 1, sizeof(is_prime));
    is_prime[0] = is_prime[1] = false;
    for(int i=2;i*i<=n;i++){
        if(is_prime[i]){
            prime[r++]=i;
            for(int j=i*2;j<=n;j+=i){
                is_prime[j]=false;
            }
        }
    }
    return r;
}
int main(void){
    int len=SETX(100000000);
    int N1, N2, sum;
    while(cin>>N1>>N2){
        sum=0;
        for(int i=N1;i<=N2;i++){
            if(is_prime[i])
                sum++;
        }
        cout<<sum<<endl;
    }
    // for(int i=0;i<len;i++){
    //     cout<<prime[i]<<" ";
    // }
    cout<<"\n";
    return 0;
}
