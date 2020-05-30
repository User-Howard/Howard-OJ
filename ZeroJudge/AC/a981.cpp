#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


vector<int >arr;
int N, M;
int list[30];
bool f;
void BFS(int ,int);


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	cin>>N>>M;
	for(int i=0;i<N;i++)
		cin>>list[i];
	sort(list,list+N);
	
	f=true;
	BFS(0, 0);
	if(f)
		cout<<-1;
	return 0;
}
void BFS(int x, int sum){
	if(sum == M){
		f=false;
		for(int i=0;i<arr.size();i++){
			cout<<arr[i]<<" ";
		}
		cout<<endl;
		return;
	}
	for(int i=x;i<N;i++){
		if(sum+list[i] >M) break;
		arr.push_back(list[i]);
		BFS(i+1, sum+list[i]);
		arr.pop_back();
	}
	return;
}
