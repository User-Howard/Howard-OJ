#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


const int MAX_N = 2e3 + 2;
int main(){
    int N;
    int S[MAX_N], D[MAX_N];

    cin>>N;
    for(int i=0;i<N;i++)
        cin>>S[i]>>D[i];
    int money=0;
    vector<int> book;
    for(int i=0;i<N;i++){
        if(D[i]>100){
            book.push_back(S[i]);
            money+=5*(D[i]-100);
        }
    }
    sort(book.begin(),book.end());
    for(int i=0;i<book.size();i++)
        cout<<book[i]<<' ';
    cout<<endl<<money<<endl;
    return 0;
}