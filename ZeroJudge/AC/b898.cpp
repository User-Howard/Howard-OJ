#include<iostream>
#include<algorithm>
using namespace std;


bool compare(string a, string b) {
    if(a.size() == b.size()){
        for(int i=0;i<a.size();i++){
            if(a[i] != b[i])
                return a[i] > b[i];
        }
    }
    else
        return a.size() > b.size();
}


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    string arr[3];
    cin>>N;
    while(N--){
        cin>>arr[0]>>arr[1]>>arr[2];
        sort(arr,arr+3,compare);
        cout<<arr[0]<<endl;
    }
    return 0;
}