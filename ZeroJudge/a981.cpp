#include<iostream>
#include<algorithm>
using namespace std;


int N, M, cnt=0;
int arr [33];
int output[33];
void find(int elm, int last, int d){
    for (int i = elm;i < N;i++) {
        if(last-arr[i]<0)
            break;
        output[d] = arr[i];
        if(last-arr[i]==0){
            cnt++;
            for (int i = 0;i <= d;i++)
                cout << output [i] << ' ';
            cout << '\n';
        }
        else{
            find(i+1, last-arr[i], d+1);
        }
    }
}
int main() {
	cin>>N>>M;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    sort(arr, arr+N);
    find(0, M, 0);
    if(cnt==0)
        cout<<-1<<'\n';
	return 0;
}
/*

*/
