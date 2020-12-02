#include<iostream>
using namespace std;


int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N;
	int arr[44];
	arr[1]=1, arr[2]=3;
	cin>>N;
	for(int i=3;i<=N;i++)
		arr[i] = arr[i-1] + arr[i-2];
	cout<<arr[N]<<endl;
	return 0;
}
