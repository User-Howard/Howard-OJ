#include<iostream>
#include<algorithm>
using namespace std;


int solve(){
    int K, m, ans=0, cnt=0;
    cin>>K;
    while(K--){
        cin>>m;
        cnt += m;
        if(cnt<0)
            cnt = 0;
        else
            ans = max(cnt, ans);
    }
    return ans!=0 ? ans : -1;
}
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	int N;
	cin>>N;
	while(N--){
        cout<<solve()<<'\n';
	}
	return 0;
}

// finish time: 4	min, 17	sec, 72	hsec
