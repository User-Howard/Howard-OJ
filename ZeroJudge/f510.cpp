#include<iostream>
#include<cmath>
#include<string.h>
using namespace std;


int dp[2][102];
int main(){
    int A, B, X, Y;
    cin>>A>>B>>X>>Y;
    memset(dp, -1, sizeof(dp[0]));
    int F = abs(A-B);
    dp[0][0] = 0;
    for(int i=0;i<=F;i++){
        for(int j=0;j<2;j++){

        }
    }
}