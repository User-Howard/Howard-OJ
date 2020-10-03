#include<iostream>
using namespace std;


int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    int f1, f2, f3, f4;
    while(cin>>N){
        for(int i=0;i<N;i++){
            cin>>f1>>f2>>f3>>f4;
            if(f1 == 0){
                if(f2 == 0){
                    cout<<'C';
                }
                else{
                    if(f3 == 0){
                        cout<<'A';
                    }
                    else{
                        cout<<'B';
                    }
                }
            }
            else{
                if(f2 == 0){
                    cout<<'E';
                }
                else{
                    if(f4 == 0){
                        cout<<'F';
                    }
                    else{
                        cout<<'D';
                    }
                }
            }
        }
        cout<<endl;
    }
}
