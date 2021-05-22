#include<iostream>
#include<string>
using namespace std;


string S, message;
int main() {
    getline(cin, S);
    getline(cin, message);
    for (int i=0;i<message.size();i++) {
        char c;
        if ('A' <= message[i] && message[i] <= 'Z') {
            c = S [message[i] - 'A']+'A'-'a';
        }
        else if ('a' <= message[i] && message[i] <= 'z') {
            c = S [message[i] - 'a'];
        }
        else {
            c = message[i];
        }
        cout << c;
    }
    cout << endl;
    return 0;
}
/*

*/
// finish time: 334	sec
