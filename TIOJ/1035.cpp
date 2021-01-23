#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int main(){
    ios::sync_with_stdio(NULL);
    cin.tie(0);

    string str1, str2;
    cin>>str1>>str2;
    const int str1len = str1.size();
    const int str2len = str1.size();

    int answer=0;
    for (int i=0;i<str1len;i++){
        int count = 0;
        for (int j=0;i+j<str2len;j++){
            count += str1[j]==str2[j+i];
        }
        if (count>answer)
            answer = count;
    }
    for (int i=0;i<str2len;i++){
        int count = 0;
        for (int j=0;i+j<str1len;j++){
            count += str2[j]==str1[j+i];
        }
        if (count>answer)
            answer = count;
    }
    cout<<answer<<endl;
    return 0;
}