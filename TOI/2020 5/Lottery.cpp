#include<iostream>
#include<map>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

	int lucky[3];
	int temp[5][2];
	bool check[5];
	int Money=0;
	int i;
    
    for(i=0;i<3;i++)
    	cin>>lucky[i];
    for(i=0;i<5;i++)
    	cin>>temp[i][0];
    for(i=0;i<5;i++){
    	cin>>temp[i][1];
	}
	for(int i=0;i<5;i++){
		for(int j=0;j<3;j++){
			if(temp[i][0] == lucky[j]){
			
				Money+=temp[i][1];
				// cout<<Money<<endl;
			}
		}	
	}
	bool c;
	c=1;
	for(int i=0;i<5;i++){
		if(temp[i][0] == lucky[2]){
			Money-=temp[i][1]*2;
			c=0;
		}
	}
	if(c)
		Money*=2;
	if(Money<0)
		Money=0;
	cout<<Money;
    return 0;
}
