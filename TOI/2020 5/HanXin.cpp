#include<iostream>
using namespace std;


template < typename T >
T GCD(T a, T b) {
	if(b) while((a %= b) && (b %= a));
	return a + b;
}


int main(void){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
    	int li[3][2];
    	for(int i=0;i<3;i++){
    		for(int j=0;j<2;j++){
    			cin>>li[i][j];
		}
	}
	
	int r=1;
	while(((r)%li[0][0] != li[0][1])||((r)%li[1][0] != li[1][1])||((r)%li[2][0] != li[2][1])){
		r++;
	}
	cout<<r;
    return 0;
}
