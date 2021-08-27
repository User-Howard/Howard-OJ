#include <iostream>
#include <map>
using namespace std;


int main(){
    int N;
    string s[(int)1e5];
    map<string, string> m;
    m ["Power"] = "Speed";
    m ["Speed"] = "Technical";
    m ["Technical"] = "Power";
    cin >> N;
    for(int i=0;i<N;++i)
        cin >> s[i];
    for(int i=0;i<N;++i){
        cout << m[s[i]] << ' ';
    }
    cout << '\n';
    return 0;
}