#include <iostream>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(0); cin.tie(0);
    string S;
    vector<int> V(26);
    vector<char> a;
    cin >> S;
    for(char i: S)
        V[i-'A']++;
    int t=0;
    for(int i=0;i<26;++i) {
        if(V[i]%2) t++;
        for(int j=0;j<V[i]/2;++j)
            a.emplace_back(i+'A');
    }
    if(t>1) {
        cout << "NO SOLUTION\n";
        goto END;
    } else {
        for(int i=0;i<a.size();++i)
            cout << a[i];
        for(int i=0;i<26;++i)
            if(V[i]%2) cout << (char)(i+'A');
        for(int i=0;i<a.size();++i)
            cout << a[a.size()-1-i];
    }
    
END:;
    return 0;
}