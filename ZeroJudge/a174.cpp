#include <iostream>
#include <cmath>
#include <vector>
#include <set>
using namespace std;

string int_to_string(int x, int len=3){
    string s = "";
    for(int i=0;i<len;++i){
        s = (char)(x%10+'0') + s;
        x /= 10;
    }
    return s;
}
void print_table(vector<set<int> >&Table){
    set<int> printed;
    cout << "===== s =====\n";
    for(int n=0;n<Table.size();++n){
        cout << "[" << int_to_string(n) << "]:";
        for(set<int>::iterator i =Table[n].begin();i!=Table[n].end();++i)
            cout << *i << " -> ";
        cout << "NULL\n";
    }
    cout << "===== e =====\n";
    return;
}
void solve(int K, int M){
    vector<set<int> > hash_table(M);
    while(K--){
        int a, b;
        cin >> a;
        if(a != 3){
            cin >> b;
            if(a == 1)
                hash_table[b%M].insert(b);
            else
                hash_table[b%M].erase(b);
        }
        else
            print_table(hash_table);
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int k, m;
    while(cin >> k >> m)
        solve(k, m);
    return 0;
}