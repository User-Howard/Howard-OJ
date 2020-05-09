#include<iostream>
using namespace std;


int main(void){
    string a;
    getline(cin,a);
    for(int i=a.size()-1;i >= 0;i--){
        printf("%c",a[i]);
    }
    return 0;
}