#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string str;
    int counti[2] = {0};

    cin>>str;
    for(int i=0;i<str.size();i++){
        counti[i%2] += str[i]-'0';
    }
    cout<<abs(counti[0] - counti[1])<<"\n";
	return 0;
}
