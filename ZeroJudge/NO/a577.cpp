#include<iostream>
#include<sstream>
#include<algorithm>
using namespace std;


string RE(string a,int len){
    string Ans="";
    for(int i=1;i<=len;i++){
        Ans+=a[len + i*-1];
    }
    return Ans;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string re="343433";
    re[3]='s';
    cout<<re;
    string a,b;
    char Ans[max(a.size(),b.size())+1];
    int r;
    while(cin>>a>>b){
        a = RE(a,a.size());
        b = RE(b,b.size());
        for(int i=0;i<b.size();i++){
            for(int j=0;j<a.size();j++){
                r = (a[j]-48)*(b[i]-48);
                Ans[i+j]=char((r%10)+48);
                Ans[i+j+1]=char((r/10)+48);
            }
        }
        for(int i=1;i<=max(a.size(),b.size())+1;i++){
            cout<<Ans[max(a.size(),b.size())+1+i*-1];
        }
    }
    return 0;
}
