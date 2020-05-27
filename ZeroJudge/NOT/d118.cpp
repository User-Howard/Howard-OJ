// https://zerojudge.tw/ShowThread?postid=2208&reply=0
#include<iostream>
using namespace std;


bool visited[36000000];
int need;
char findi;
string R;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    while(cin>>R>>need){
        findi='9';
        while(need > 0){
            for(int i=0;i<R.size();i++){
                if(R[i] == findi){
                    cout<<R[i];
                    visited[i]=1;
                    need--;
                }
                if(need == 0)
                    break;
            }
            findi--;
        }
        for(int i=0;i<R.size();i++){
            if(visited[i]);
                //cout<<R[i];
        }
        cout<<endl;
    }
    return 0;
}