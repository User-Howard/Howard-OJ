#include<bits/stdc++.h>
using namespace std;


const int MAXRANGE = 1e5;
int N;
struct OBJ{
    int w;
    int f;
}arr[MAXRANGE];


bool cmp(struct OBJ a, struct OBJ b){
    return a.w*b.f > b.w*a.f;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>N;
    for(int i=0;i<N;i++){
        cin>>arr[i].w;
    }
    for(int i=0;i<N;i++){
        cin>>arr[i].f;
    }
    sort(arr, arr+N, cmp);
    for(int i=0;i<N;i++){
        // PASS
    }
	return 0;
}
