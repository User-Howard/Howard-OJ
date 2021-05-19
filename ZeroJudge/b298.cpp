#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


int N, M, L, Q;
struct E{
	int bad=-1;
	vector<int>father;
}stores[(int)(1e4+2)];
bool check_bad(int it){
	if(stores[it].bad!=-1)
		return stores[it].bad;
	else{
		bool is_bad=false;
		for(int i:stores[it].father)
			is_bad = max(check_bad(i), is_bad);
		return stores[it].bad = is_bad;
	}
}
int main() {
	cin>>N>>M>>L>>Q;
	int a, b;
	for(int i=0;i<M;i++){
		cin>>a>>b;
		stores[b].father.push_back(a);
	}
	for(int i=0;i<L;i++){
		cin>>a;
		stores[a].bad=true;
	}
	for(int i=0;i<Q;i++){
		cin>>a;
		if(check_bad(a))
			cout<<"TUIHUOOOOOO"<<'\n';
		else
			cout<<"YA~~"<<'\n';
	}
	return 0;
}
/*
N, L, Q -> (0, 10000]
M -> (0, 100000]
*/
// finish time: 935	sec