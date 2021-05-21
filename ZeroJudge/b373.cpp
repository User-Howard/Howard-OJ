#include<iostream>
#include<algorithm>
using namespace std;


int N;
int ans=0;
int arr[(int)(1e4+2)];
int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	cin>>N;
	for(int i=0;i<N;i++)
        cin>>arr[i];
    while(true){
        bool all_corect=true;
        for(int i=0;i<N-1;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i], arr[i+1]);
                ans++;
                all_corect = false;
            }
        }
        if(all_corect)
            break;
    }
    cout<<ans<<'\n';
	return 0;
}
/*

*/
