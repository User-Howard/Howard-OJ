#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int li[26]={1,0,9,8,7,6,5,4,9,3,2,2,1,0,8,9,8,7,6,5,4,3,1,3,2,0};
    int check, sum;
    string R;
    while(cin>>R){
        check=0;
        sum=0;

        check=R[8]-'0';
        for(int i=0;i<8;i++)
            sum+=(R[i]-'0')*(8-i);
        for(int i=0;i<26;i++)
            if(10 - (sum + li[i]) % 10 == check)
                cout<<(char)(i+'A');
        cout<<endl;
        
    }

    return 0;
}
