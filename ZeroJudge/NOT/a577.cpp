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
    
    string a, b;
    int Ans[40];
    int r, noe;
    while(cin>>a>>b){
        a = RE(a,a.size());
        b = RE(b,b.size());
        for(int i=0;i<40;i++)Ans[i]=0;
        for(int i=0;i<b.size();i++){
            for(int j=0;j<a.size();j++){
                r = (b[i]-48)*(a[j]-48);
                Ans[i+j]+=(r);
                if(Ans[i+j]>=10){
                    noe=Ans[i+j];
                    Ans[i+j]=noe%10;
                    Ans[i+j+1]=noe/10;

                }
            }
        }
        bool FirstZero=true;
        if(a=="0" || b=="0"){
            cout<<"0"<<endl;
            continue;
        }
        for(int i=1;i<=40;i++){
            if(Ans[40+i*-1] != 0) FirstZero=false;
            if(!FirstZero) cout<<Ans[40+i*-1];
        }
        cout<<endl;
    }
    return 0;
}
