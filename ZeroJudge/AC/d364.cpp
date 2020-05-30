#include<iostream>
#include<cmath>
#include<vector>
using namespace std;


int N, t, s;
vector<int >arr;
void solve();
void BFS(int, int);
int GCD(int, int);
bool Judge(int);

int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    
    int N;
    while(cin>>N){
        for(int Case=1;Case<=N;Case++){
            cout<<"Case "<<Case<<":"<<endl;
            cin>>s>>t;
            BFS(1, 0);
        }
    }
    return 0;
}
void BFS(int x, int Sum){
    if(arr.size() == t){
        if(Sum == s){
            for(int i=0;i<arr.size();i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
        return;
    }
    for(int i=x;i<=s;i++){
        if(Sum+i>s or Judge(i)) continue;
        arr.push_back(i);
        BFS(i, Sum+i);
        arr.pop_back();
    }
}
int GCD(int  a, int  b) {
	if(b) while((a %= b) && (b %= a));
	return a + b;
}
bool Judge(int a){
    if(arr.size() == 0) return 0;
    for(int i=0;i<arr.size();i++){
        if(GCD(arr[i], a) > 1)
            return 1;
    }
    return 0;
}
