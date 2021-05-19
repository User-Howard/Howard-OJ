#include<iostream>
#include<algorithm>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
	
	int N;
	int arr[8], Crr[8];
	while(cin>>N){
		for(int i=0;i<N;i++){
			Crr[i]=i;
			arr[i]=N-i;
		}
		do{
			for(int i=0;i<N;i++)
				cout<<arr[Crr[i]];
			cout<<endl;
		}
		while(next_permutation(Crr,Crr+N) );
	}
    
   return 0;
}
