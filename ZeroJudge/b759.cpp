#include<iostream>
using namespace std;


int main(void){
	
	string R;
	cin>>R;
	
	for(int i=0;i<R.size();i++){
		for(int j=0;j<R.size();j++){
			printf("%c",R[(j+i)%R.size()]);
		}
		printf("\n");
	}
	return 0;
}
