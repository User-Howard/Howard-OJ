#include<iostream>
#define FOR(i, x) for(int i=0;i<x;i++)
using namespace std;


string sarr[7]={
    "Sunday",
    "Monday",
    "Tuesday",
    "Wednesday",
    "Thursday",
    "Friday",
    "Saturday"
};
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    int N;
    cin>>str>>N;
    FOR (i, 7) {
        if (sarr[i]==str) {
            cout<<sarr[(i+N)%7]<<endl;
        }
    }
    return 0;
}
