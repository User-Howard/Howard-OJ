#include<iostream>
#include<string.h>
using namespace std;


int N;
int bit[(int)(1e5+2)]={0};
void update(int i, int x){
	while(i<=N){
		bit[i]+=x;
		i += i&-i;
	}
	return;
}
int sum(int i){
	int s=0;
	while(i>0){
		s+=bit[i];
		i -= i&-i;
	}
	return s;
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (cin >> N){
		memset(bit, 0, sizeof(bit));
		for(int i=1, m;i<=N;i++){
			cin>>m;
			cout<<i-sum(m)<<'\n';
			update(m, 1);
		}
	}
	
	return 0;
}