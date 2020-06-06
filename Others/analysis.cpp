#include<iostream>
#include<vector>
#define LEN arr.size()
using namespace std;


int N;
vector<int >arr;
int Arithmetic_sequence(int, int );//等差
int Proportional_sequence(int, int);// 等比


int main(void){
    scanf("%d",&N);
    for(int i=0,r;i<N;i++){
        scanf("%d",&r);
        arr.push_back(r);
    }
    int l=0;
    while(l<LEN-1){
        for(int le=LEN-l;le>=2;le--){
            if(Arithmetic_sequence(l, le) != 0){
                printf("[%d~%d d%d] ", arr[l], arr[l+le-1], Arithmetic_sequence(l, le));
                l+=le;
                break;
            }
        }
        for(int le=LEN-l;le>=2;le--){
            if(Proportional_sequence(l, le) != 0){
                printf("[%d~%d r%d] ", arr[l], arr[l+le-1], Proportional_sequence(l, le));
                l+=le;
                break;
            }
        }
    }
    return 0;
}
int Arithmetic_sequence(int x, int le){
    int r=arr[x+1]-arr[x];
    for(int i=x;i<x+le-1;i++){
        if(arr[i+1] - arr[i] != r)
            return 0;
    }
    return r;
}
int Proportional_sequence(int x, int le){
    double r=arr[x+1]/arr[x];
    for(int i=x;i<x+le-1;i++){
        if(arr[i+1]/arr[i] != r)
            return 0;
    }
    return r;
}