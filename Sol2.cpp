#include<iostream>
#include<vector>
#define all(x) (x).begin(),x.end() 
#define rall(x) (x).rbegin(),x.rend()
#define sz(x) (int)((x).size())
#define V vector
#define vi V<int>
#define pii pair<int,int>
#define vpii V<pii>
#define F first
#define S second
#define pb push_back
#define int long long
#define vvi V<vi>
using namespace std;

int n,m;
vvi to;
int cnt;
void dfs(int x,set<int> s,vi visited){
	cerr<<x<<'\n';
	if(cnt>100){
		cout<<"0.0\n";
		exit(0);
	}
	for(int j:to[x]){
		s.insert(j);
	}
	s.erase(s.find(x));
	if(sz(s)==0){
		cnt++;
		return;
	}
	for(int i:s)cout<<1+i<<' ';
	cout<<'\n';
	for(int i:s){
		set<int> s1=s;
		s1.erase(s1.find(i));
		for(int j:to[i]){
			if(visited[j])continue;
			visited[j]=1;
			dfs(j,s1,visited);
			visited[j]=0;
		}
	}
}

signed main(){
	cin>>n>>m;
	to.resize(n+1);
	vi f(n,1);
	while(m--){
		int a,b;
		char c;
		cin>>a>>c>>b;
		if(c=='<'){
			to[b-1].pb(a-1);
			f[a-1]=0;
		}
		else{
			to[a-1].pb(b-1);
			f[b-1]=0;
		}
	}
	set<int> next;
	for(int i=0;i<n;i++){
		if(f[i]){
			next.insert(i);
			f[i]=0;
		}
	}
	dfs(n,next,f);
	cout<<cnt<<'\n';
	cout<<fixed<<setprecision(20)<<1.0/cnt<<'\n';
} 
