#include<iostream>
using namespace std;


int N, M, P [200000 + 2], Q [20000 + 2];
int get_prefix_sum(int it){
	if(it<0)
		return 0;
	if(it<N)
		return P[it];
	else
		return P[N-1]+P[it%N];
}
int main() {
	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>P[i];
	for(int i=0;i<M;i++)
		cin>>Q[i];
	for(int i=1;i<N;i++)
		P[i] += P[i-1];
	int point=0;
	for(int i=0;i<M;i++){
		int lb = point, rb = point+N;
		while (rb - lb >= 1) {
			int mid = (rb + lb) / 2;
			if(get_prefix_sum(mid)-get_prefix_sum(point-1)>=Q[i])
				rb = mid;
			else
				lb = mid+1;
		}
		point = (lb+1)%N;
	}
	cout<<point<<endl;
	return 0;
}
/*

*/
// finish time: 1483	sec
