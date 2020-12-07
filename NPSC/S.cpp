#include<iostream>
#include<vector>
using namespace std;


struct E{
    int num=1; //init
    char c;
};
vector<E > restring(string& S){
    vector<E >sarr;
    for(int i=0;i<S.size();i++){
        E temp;
        if(isdigit(S[i])){
            temp.num = S[i] - '0';
            temp.c = S[i+1];
            i++;
        }
        else{
            temp.c = S[i];
        }
        sarr.push_back(temp);
    }
    return sarr;
}
int main(){
    string S("");
    cin>>S;
    vector<E >arr;
    arr = restring(S);
    for(int i=0;i<arr.size();i++){
        cout<<arr[i].num<<" -> "<<arr[i].c<<endl;
    }
    for(auto i:arr){
        for(int j=0;j<i.num;j++){
            cout<<i.c;
        }
    }
    cout<<endl;
    return 0;
}
