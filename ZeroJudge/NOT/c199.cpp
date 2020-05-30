#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, arr[10002];
    int highest, sum;
    while(cin>>n){
        highest=-1, sum=0;
        for(int i=0;i<n;i++)
            cin>>arr[i];
        
        for(int i=1;i<n-1;){
            if(arr[i] > arr[i+1]){
                sum++;
                while(arr[i] >= arr[i+1])i++;
            }
            else
                i++;
        }
        cout<<sum<<endl;
    }
    
    return 0;
}