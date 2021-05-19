#include<iostream>
#include<stack>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int >arr;
    int N;
    int cas, data;
    cin>>N;

    while(N--){
        cin>>cas;
        switch(cas){
        case 1:
            arr.pop();
            break;
        case 2:
            cout<<arr.top()<<endl;
            break;
        case 3:
            cin>>data;
            arr.push(data);
            break;
        }
    }
    return 0;
}
