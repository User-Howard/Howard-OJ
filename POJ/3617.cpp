#include<iostream>
using namespace std;


int N;
char arr[2002];
int compare(int low, int high){
    if(high<=low)
        return 1;
    else
        return (arr[low]!=arr[high])?arr[low]>arr[high] : compare(low+1, high-1);
}
int main(){
    cin>>N;
    for(int i=0;i<N;i++)
        cin>>arr[i];
    int low=0, high=N-1;
    int p=-1;
    while(high-low>=0){
        if(++p==80){
            p=0;
            cout<<endl;
        }
        if(compare(low, high))
            cout<<arr[high--];
        else
            cout<<arr[low++];
    }
    if(p!=0)
        cout<<endl;
    return 0;
}
