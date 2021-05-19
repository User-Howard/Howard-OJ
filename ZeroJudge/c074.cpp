#include<iostream>
using namespace std;


int K;
int nums[14], arr[7];
void dfs(int n=0, int savet=0){
	if(savet == 6){
		cout<<arr[0]<<' '<<arr[1]<<' '<<arr[2]<<' '<<arr[3]<<' '<<arr[4]<<' '<<arr[5]<<endl;
	}
	else{
		for(int i=n;i<=K-(6-savet);i++){
			arr[savet] = nums[i];
			dfs(i+1, savet+1);
		}
	}
}
int main() {
	int cases=0;
	while(cin>>K && K){
		if(++cases>1)
			cout<<endl;
		for(int i=0;i<K;i++)
			cin>>nums[i];
		dfs();
	}
	return 0;
}
/*
K -> (6, 13)
*/
// finish time: 1215	sec