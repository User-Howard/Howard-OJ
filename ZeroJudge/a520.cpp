#include<iostream>
using namespace std;



int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    string L;
    int count;
    bool nospace;

    while(getline(cin,L)){
        count = 0;
        do{
            nospace=1;
            for(int i=0;i<L.size()-1;i++){
                if((L[i]==' ') && (L[i+1]==' ')){
                    L.erase(i,1);
                    nospace=0;
                }
            }
            if(!nospace)
                count++;
        }
        while(! nospace);
        cout<<count<<endl;
    }
    return 0;
}
