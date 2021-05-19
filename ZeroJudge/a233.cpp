#include<iostream>
#include<algorithm>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int len;
    cin>>len;
    int arr[len]={};
    
    for(int i=0;i<len;++i)
        cin>>arr[i];
    sort(arr,arr+len);
    for(int i=0;i<len;++i)
        cout<<arr[i]<<" ";
    cout<<"\n";
    
    return 0;
}
