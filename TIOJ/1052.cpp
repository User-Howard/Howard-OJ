#include<iostream>
#include<sstream>
using namespace std;


int N, i_line, i_word, i_char;
string str, rest;
int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    cin.get();
    while(N--){
        i_line=0, i_word=0, i_char=0;
        while(getline(cin, str) and str!="====="){
            i_line++;
            i_char+=str.size();
            stringstream ss(str);
            while(ss>>rest)i_word++;
        }
        printf("%d %d %d\n", i_line, i_word, i_char);
    }
    return 0;
}