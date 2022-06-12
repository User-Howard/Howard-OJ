#include <iostream>
#include <vector>
using namespace std;


const int INF = 0x3f3f3f3f;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    int N, L;
    cin >> N >> L;
    vector<int> C(N+2), H(N+2), space(N+2);
    int removed = 0, max_tree = 0;
    C[0] = 0, C[N+1] = L;
    for(int i=1;i<=N;++i)
        cin >> C[i];
    for(int i=1;i<=N;++i)
        cin >> H[i];
    
    for(int i=1;i<=N;++i)
        space[i] = max(C[i] - C[i-1], C[i+1] - C[i]);
    for(int i=0;i<N+2;++i){
        bool cut = false;
        for(int j=1;j<=N;++j){
            if(space[j] >= H[j]){
                ++removed;
                max_tree = max(max_tree, H[j]);
                H[j] = INF;
                cut = true;

                for(int k=j+1;k<=N+1;++k){
                    if(H[k] != INF){
                        space[j-1] = max(space[j-1], C[k] - C[j-1]);
                        break;
                    }
                }
                for(int k=j-1;k>=0;--k){
                    if(H[k] != INF){
                        space[j+1] = max(space[j+1], C[j+1] - C[k]);
                        break;
                    }
                }
            }
        }
        /*
        for(int i=1;i<=N;++i){
            if(H[i] == INF)
                cout << "INF\t";
            else
                cout << H[i] << '\t';
        }
        cout << '\n';
        for(int i=1;i<=N;++i){
            cout << space[i] << '\t';
        }
        cout << '\n';
        cout << '\n';
*/
        if(!cut)
            break;
    }
    
    cout << removed << '\n' << max_tree << '\n';
    return 0;
}