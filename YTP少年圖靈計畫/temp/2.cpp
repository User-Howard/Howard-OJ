#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
#include <cmath>
using namespace std;


int N;
typedef vector<vector<bool> > vvb;
typedef pair<vvb, int> pvvbi;
unordered_set<vvb> s;
queue<pvvbi> q;
int max_pl(vvb & m){
    vector<vector<int> > dp(N, vector<int>(N, 0));
    int max_item = -1;
    for(int i = 0;i < N;++i)
        dp[i][0] = m[i][0];
    for(int i = 0;i < N;++i)
        dp[0][i] = m[0][i];
    for(int i = 1;i < N;++i){
        for(int j = 1;j < N;++j){
            if(!m[i][j])
                continue;
            int d = min(dp[i][j - 1], dp[i - 1][j]);
            if(min(i, j) >= d and m[i - d][j - d])
                dp[i][j] = d + 1;
            else dp[i][j] = d;
            max_item = max(dp[i][j], max_item);
        }
    }
    return max_item;
}
int main(){
    cin >> N;
    getchar();
    vvb Narrary(N, vector<bool>(N));
    for(int i = 0;i < N;++i){
        string input;
        getline(cin, input);
        for(int j = 0;j < N;++j)
            Narrary[i][j] = (input[j] == '+');
    }
    q.push(make_pair(Narrary, 0));
    s.insert(Narrary);
    while(!q.empty()){
        vvb thismap = q.front().first;int thiscount = q.front().second;q.pop();

    }
    // if(s.find(Narrary) != s.end())
    //     cout << '1' << '\n';
    return 0;
}