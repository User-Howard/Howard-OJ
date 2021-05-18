#include<iostream>
#include<vector>
#include<cmath>
using namespace std;


const int INF = 0x3f3f3f3f;
int trans(int from, int to, int f){
    if(from==to)
        return f;
    else{
        if(f>=1000){
            return 3000+2*(f-1000);
        }
        else
            return 3*f;
    }
}
int main(){
    int N, M, K;
    int Q[52][52]={0};
    cin>>N>>M>>K;
    for(int i=0;i<N;i++)
        for(int j=0;j<M;j++)
            cin>>Q[i][j];
    int min_money = INF;
    while(K--){
        vector<int>city[52];
        for(int i=0;i<N;i++){
            int x;
            cin>>x;
            city[x].push_back(i);
        }
        int sum=0;
        for(int i=0;i<M;i++){
            for(int j=0;j<M;j++){
                int citysumflow=0;
                for(int k=0;k<city[i].size();k++)
                    citysumflow+=Q[city[i][k]][j];
                sum+=trans(i, j, citysumflow);
            }
        }
        min_money = min(sum, min_money);
    }
    cout<<min_money<<endl;
    return 0;
}