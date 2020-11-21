#include<iostream>
using namespace std;


int N;
int arr[(int )1e4+2];
int main(void){
	ios::sync_with_stdio(false);
	cin.tie(0);
	
    arr[0] = arr[1] = 1;
    for (int i=2;i<10000;i++) {
        arr[i] = (arr[i-1] + arr[i-2]) % 1000000007;
    }
    while(cin>>N) {
        cout<<arr[N]<<endl;
    }
	return 0;
}
