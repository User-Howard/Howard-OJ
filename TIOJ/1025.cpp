#include<iostream>
#include<list>
using namespace std;


bool in_(int  x, int arr[], int len){
    for(int i=0;i<len;i++){
        if(arr[i] == x)
            return 1;
    }
    return 0;
}

int main(){
    int a[2]={1, 2}
    cout<<in_(1, a, a.size());
    return 0;
}
