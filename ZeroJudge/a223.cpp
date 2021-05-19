#include<iostream>
using namespace std;


string cut(string a, int r){
    string ANS;
    for(int i=0;i<r;i++){
        ANS+=a[i];
    }
    return ANS;
}
string ex(string a, int r){
    string ANS;
    for(int i=0;i<r;i++){
        ANS+=a;
    }
    return ANS;
}

int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string L;
    string r;

    while(cin>>L && L != "."){
        for(int i=L.size();i>=0;i--){
            if(L.size()%i == 0){
                if(ex(cut(L, L.size()/i), i) == L){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}
