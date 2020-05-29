#include<iostream>
#include<cmath>
#include <sstream>
#include<vector>
using namespace std;

bool R(long long int a){
    stringstream s1;
    string str;

    s1<<a;
    s1>>str;


    for(long long int i=0;i<str.size()-1;i++){
        if(abs(str[i]-str[i+1]) > 1)
            return 0;
    }
    return 1;
}
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);



    long long int N;
    cin>>N;
    vector<long long int >arr;
    for(long long int i=1;arr.size()<N;i++)
        if(R(i)){
            arr.push_back(i);
        }

    cout<<arr[N-1]<<endl;

    return 0;
}
