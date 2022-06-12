#include <iostream>
using namespace std;


string solve(){
    string output = "";
    bool poem[2][7];
    for(int i=0;i<2;++i)
        for(int j=0;j<7;++j)
            cin >> poem[i][j];
    if(poem[0][1]==poem[0][3] or poem[0][1]!=poem[0][5] or poem[1][1]==poem[1][3] or poem[1][1]!=poem[1][5])
        output += 'A';
    if(!poem[0][6] or poem[1][6])
        output += 'B';
    if(poem[0][1]==poem[1][1] or poem[0][3]==poem[1][3] or poem[0][5]==poem[1][5])
        output += 'C';
    return output == "" ? "None" : output;
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N;
    cin >> N;
    while(N--) cout << solve() << '\n';

    return 0;
}
