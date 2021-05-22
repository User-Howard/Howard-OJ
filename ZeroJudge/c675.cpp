#include<iostream>
using namespace std;



string S;
struct E{
    char c=0;
    int hold=0;
};

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
	while(cin>>S){
        E MAX, e;
        S+='/';
        for(int i=0;i<S.size();i++){
            if(e.c!=S[i]){
                if(MAX.hold<e.hold)
                    MAX = e;
                e.c = S[i];
                e.hold = 1;
            }
            else{
                e.hold++;
            }
        }
        cout<<MAX.c<<' '<<MAX.hold<<'\n';
    }
	return 0;
}
