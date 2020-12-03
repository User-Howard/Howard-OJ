#include<iostream>
#include<cmath>
using namespace std;


string arr[(int )1e6+2];
int same(string a, string b){
	int ans=0;
	for(int i=0;i<min(a.size(), b.size());i++){
		ans+= (a[i]==b[i]);
	}
	return ans;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	
	int N, ans=0;
	cin>>N;
	if(N==1)
		cout<<"1"<<endl;
	for(int i=0;i<N;i++){
		cin>>arr[i];
	}
	for(int i=0;i<N-1;i++){
		for(int j=i+1;j<N;j++){
			ans+=same(arr[i], arr[j]);
		}
	}
	cout<<ans<<endl;
	return 0;
}
