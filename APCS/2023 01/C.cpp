#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;


vector<string> giv;
int64_t f(int l, int r) { // [)
    vector<int64_t> result;
    int64_t num = 0, add = 0, tot = 1;
    for(int i=l;i<=r;++i) {
        if(i == r or giv[i] == ",") {
            tot *= (add+num);
            result.push_back(tot);
            tot = 1;
            add = 0;
        } else if(giv[i] == "*") {
            tot *= (add+num);
            add = 0;
        } else if(giv[i] == "+") {
            add += num;
        } else if(giv[i] == "f") { 
            int cnt = 0;
            for(int j=i+1;j<r;++j) {
                if(giv[j] == "(") cnt ++;
                if(giv[j] == ")") cnt --;
                if(cnt == 0) {
                    num = f(i+2, j);
                    i = j;
                    break;
                }
            }
        } else {
            num = atoi(giv[i].c_str());
        }
    }
    /*for(int i=l;i<r;++i)
        cout << giv[i];
    cout << "= " << *max_element(result.begin(), result.end()) - *min_element(result.begin(), result.end()) << '\n';*/
    return *max_element(result.begin(), result.end()) - *min_element(result.begin(), result.end());
}
int main() {
    string S;
    cin >> S;
    S += ",0";
    for(int i=0;i<S.size();++i) {
        if(isdigit(S[i])) {
            int r = i;
            while(isdigit(S[++r]));
            giv.push_back(S.substr(i, r-i));
            i = r - 1;
        } else {
            giv.push_back(string(1, S[i]));
        }
    }
    cout << f(0, giv.size()) << '\n';
    return 0;
}