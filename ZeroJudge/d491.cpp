#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int a, b, sum;
    while(cin>>a>>b){
        if(a>b)
            swap(a, b);
        sum=0;
        for(int i=a;i<=b;i++){
            if(i%2 == 0)
                sum+=i;
        }
        cout<<sum;
    }
    return 0;
}