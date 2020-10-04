#include<bits/stdc++.h>
using namespace std;

int N, d, step, location;
int arr[2500];
bool arr_check[2500];

int __getSideblockLocation(int x){
    if(x==0)
        return location-1;
    else if(x==1)
        return location-N;
    else if(x==2)
        return location+1;
    else if(x==3)
        return location+N;
}
bool side(){
    if(arr_check[__getSideblockLocation((d+1)%4)])
        return 1;
    else
        return 0;
}
void goForward(){
    step++;
    location=__getSideblockLocation(d);
    arr_check[location] = true;
    cout<<arr[location];
    return;
}
void turnRight(){
    step++;
    d=(d+1)%4;
    location=__getSideblockLocation(d);
    arr_check[location] = true;
    cout<<arr[location];
    goForward();
    return;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N>>d;
    for(int i=0;i<N*N;i++){
        cin>>arr[i];
        arr_check[i] = false;
    }
    step = 2;
    location = (N*N)/2;
    arr_check[location] = true;
    cout<<arr[location];
    location = __getSideblockLocation(d);
    arr_check[location] = true;
    d = (d+1)%4;
    cout<<arr[location];
    while(step<N*N){
        if(side())
            goForward();
        else
            turnRight();
    }
    return 0;
}

/*

5
1
24 9  10 11 12
23 8  1  2  13
22 7  0  3  14
21 6  5  4  15
20 19 18 17 16
*/
