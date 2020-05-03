#include<iostream>
using namespace std;


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	string ad,all;
	cin>>ad;
	getline(cin,all);
	
	for(int i=1;i<all.size();i++){
		if(all[i] == ' ')
			cout<<" "<<ad<<" ";
		else
			cout<<all[i];
	}
	
	return 0;
}
