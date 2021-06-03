#include<iostream>
#include<functional>
#include<queue>
#include<algorithm>
using namespace std;
#define presum  first
#define pos     second
typedef pair<int, int> pii;


int N, K;
int nums[(int)(1e5+2)];
priority_queue<pii, vector<pii>, greater<pii> >prque;
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>N>>K;
    for(int i=0;i<N;i++)
        cin>>nums[i];
    for(int i=1;i<N;i++)
        nums[i] += nums[i-1];
    int ans=0;
    prque.push(make_pair(0, -1));
    for(int i=0;i<N;i++){
        while(prque.top().pos<i-K)prque.pop();
        ans = max(nums[i]-prque.top().presum, ans);
        prque.push(make_pair(nums[i], i));
    }
    cout<<ans<<'\n';
	return 0;
}

// finish time: 23	min, 59	sec, 21	hsec