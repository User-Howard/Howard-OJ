#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;


vector<vector<int> > G;
vector<int> cnt;
int N, M;
int main(){
    int T;
    cin >> T;
    while(T--){
        cin >> N >> M;
        priority_queue<int, vector<int>, greater<int> > que;
        vector<int> output;
        cnt.resize(N);
        cnt.clear();
        G.resize(N);
        for(int i=0;i<N;++i)
            G[i].clear();
        for(int a, b, i=0;i<M;++i){
            cin >> a >> b;
            G[a].push_back(b);
            ++cnt[b];
        }
        for(int i=0;i<N;++i){
            if(cnt[i] == 0)
                que.push(i);
        }
        while(!que.empty()){
            int p = que.top();que.pop();
            output.push_back(p);
            for(int i:G[p]){
                if(--cnt[i] == 0)
                    que.push(i);
            }
        }
        if(output.size() != N)
            cout << "QAQ" << '\n';
        else{
            for(int i=0;i<N;++i)
                cout << output[i] << " \n"[i==N-1];
        }
    }
    return 0;
}