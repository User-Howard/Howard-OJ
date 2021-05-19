#include<iostream>
#include<set>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    set<string >arr;
    string R;
    while(getline(cin, R)){
        if(arr.count(R)){
            cout<<"YES"<<endl;
        }
        else{
            cout<<"NO"<<endl;
            arr.insert(R);
        }
        
    }
    
    return 0;
}