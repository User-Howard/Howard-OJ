#include <iostream>
#include <cctype>
#include <string>
#include <map>
using namespace std;


int N;
int kase=0;
int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    while(cin >> N) {
        if(kase++>0) {
            cout << '\n';
        }
        map<string, int> mp;
        string S;
        while(cin >> S and S != "EndOfText") {
            int pt=-1;
            string tmp="";
            for(int i=0;i<S.size();++i) {
                if(not isalpha(S[i])) {
                    if(tmp!="") {
                        mp[tmp] += 1;
                        tmp = "";
                    }
                } else {
                    tmp += tolower(S[i]);
                }
            }
            if(tmp!="")
                mp[tmp] += 1;
        }
        int flag = 0;
        for(auto i: mp) {
            if(i.second==N) {
                cout << i.first << '\n';
                flag = true;
            }
        }
        if(not flag) {
            cout << "There is no such word.\n";
        }
    }



    return 0;
}
