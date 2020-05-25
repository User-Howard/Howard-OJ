#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin>>N;
    int arr[N];
    bool OKarr[N];
    
    for(int i=0;i<N;i++){
    	cin>>arr[i];
    	OKarr[i]=1;
	}
    
    bool r;
	r=0;
    for(int i=0;i<N;i++){
    	if(arr[i] == 1){
    		r=1;
		}
    	if(r==0 || arr[i] == 1) OKarr[i] = 0;
	}
	r=0;
    for(int i=N-1;i>=0;i--){
    	if(arr[i] == 1){
    		r=1;
		}
    	if(r==0 || arr[i] == 1) OKarr[i] = 0;
	}
    for(int i=0;i<N;i++){
    	if(arr[i] == 9){
    		OKarr[i-1]=0;
    		OKarr[i  ]=0;
    		OKarr[i+1]=0;
		}
	}
	int Count=0;
    for(int i=0;i<N;i++)
    	if(OKarr[i]) Count++;
    
    cout<<Count;
    return 0;
}
