#include<iostream>
#include<vector>
using namespace std;


const int MAX_STRING_SIZE = 5e2 +2;
vector<vector<bool> >dp(MAX_STRING_SIZE, vector<bool>(MAX_STRING_SIZE));
int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);

    string str1, str2;
    cin>>str1>>str2;
    const int strlen = str1.size();
    // init
    for(int i=0;i<strlen;i++){
        dp[0][i] = str1[0]==str2[i];
        dp[i][0] = str1[i]==str2[0];
    }
    for(int i=1;i<strlen;i++){
        for(int j=1;j<strlen;j++){
            dp[i][j] = (dp[i-1][j-1] && str1[i]==str2[j]);
        }
    }
    for(int i=1;i<=strlen;i++){
        if(dp[strlen-1][strlen-i] || dp[strlen-i][strlen-1]){
            cout<<strlen-i+1<<endl;
            break;
        }
    }
    return 0;
}