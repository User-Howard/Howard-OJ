#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
using namespace std;
#define pos first
#define cha second

int N;
string S;
vector<pair<int, int> >points;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cin >> S;
    S += '+';
    N = S.size();
    for(int i=0;i<N;i++){
        if(S[i]=='+')
            points.push_back(make_pair(i, 1));
        else if(S[i]=='-')
            points.push_back(make_pair(i, -1));
    }
    for(int i=0;i<points.size()-1;i++){
        if(points[i].cha==-1){
            reverse(&S[points[i].pos+1], &S[points[i+1].pos]);
        }
    }
    for(int i=0;i<N;i++)
        if(S[i]!='+' && S[i]!='-')
            cout << S[i];
    cout << '\n';
    return 0;
}

