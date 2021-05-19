#include<bits/stdc++.h>
using namespace std;

vector<int >arr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M, K;
    cin>>N>>M>>K;
    for(int i=0;i<N;i++)
        arr.push_back(i+1);;
    int point = 0;
    for(int i=0;i<K;i++){
        point=(point+M-1)%arr.size();
        arr.erase(arr.begin()+point);
    }
    cout<<arr[(point)%arr.size()]<<endl;
    return 0;
}