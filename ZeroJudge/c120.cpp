#include <cstdint>
#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

struct BigInt {
    vector<u_int64_t> nu;
    BigInt(int n) {
        while (n) {
            nu.push_back(n%1000000000);
            n /= 1000000000;
        }
    }
    BigInt(string n) {
        while(n!="") {
            nu.push_back(stoll(n.substr(max(0, int(n.size()-9)), min(int(n.size()), 9))));
            n = n.substr(0, max(int(n.size()-9), 0));
        }
    }
    BigInt(vector<u_int64_t> n) {
        nu = n;
    }
    BigInt operator*(const BigInt A) { // 9 per int
        vector<uint64_t> result((nu.size()*9 + A.nu.size()*9)/9+1);
        for(int i=0;i<nu.size();++i) {
            for(int j=0;j<A.nu.size();++j) {
                result[i+j] += (nu[i]) * (A.nu[j]);
            }
            for(int j=0;j<result.size()-1;++j) {
                result[j+1] += result[j]/1000000000;
                result[j] %= 1000000000;
            }
        }
        int last_int = result.size()-1;
        for(int i=result.size()-1;i>=0;--i) {
            if(result[i] != 0) {
                last_int = i;
                break;
            }
        }
        while(not result.empty() and result[result.size()-1]==0)
            result.pop_back();
        return result;
    }
};
int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    vector<string> Rec(1001, "");
    Rec[0] = "1";
    BigInt answer(1);
    for(int i=1;i<=1000;++i) {
        answer = answer*BigInt(i);
        for(int j=0;j<answer.nu.size();++j) {
            string tmp = to_string(answer.nu[answer.nu.size()-1-j]);
            while ((j!=0) and tmp.size()<9) {
                tmp = '0'+tmp;
            }
            Rec[i] += tmp;
        }
    }

    int N;
    while(cin >> N) {
        cout << N << "!\n";
        cout << Rec[N] << '\n';
    }

    return 0;
}
