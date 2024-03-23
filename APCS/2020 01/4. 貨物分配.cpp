#include <iostream>
#include <vector>
using namespace std;



int N, M;
int goods[(int)1e4];
struct E{
    int parent;
    int lson, rson;
    int val = 0;
    bool end = false;
}G[(int)2e6];
void fill_goods(int x, int index=1){
    G[index].val += x;
    if(G[index].end){
        cout << index << ' ';
        return;
    }
    if(G[G[index].lson].val > G[G[index].rson].val)
        fill_goods(x, G[index].rson);
    else
        fill_goods(x, G[index].lson);
    return;
}
void update_goods(int x, int index){
    G[index].val += x;
    if(index <= 1)
        return;
    update_goods(x, G[index].parent);
}
int main(){
    ios::sync_with_stdio(0);cin.tie(0);
    cin >> N >> M;
    for(int i=0;i<N;++i){
        cin >> G[N + i].val;
        G[N + i].end = true;
    }
    for(int i=0;i<M;++i)
        cin >> goods[i];
    for(int i=0;i<N-1;++i){
        int a, b, c;
        cin >> a >> b >> c;
        G[a].lson = b, G[b].parent = a;
        G[a].rson = c, G[c].parent = a;
    }
    for(int i=0;i<N;++i)
        update_goods(G[N + i].val, G[N + i].parent);
    
    for(int i=0;i<M;++i)
        fill_goods(goods[i]);
    cout << '\n';
    return 0;
}