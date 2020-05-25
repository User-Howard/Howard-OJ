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
<<<<<<< HEAD:ZeroJudge/AC/a054.cpp

        check=R[0]-48;
        for(int i=1;i!=8;i++)
            $1
        
=======
		sum=0;
		
        check=R[0]-'0';
		for(int i=8; i != 1; i--)
			sum += i * (R[8 - i] - '0');
        // cout << (check - (sum % 10)) % 10 << '\n';
>>>>>>> 4b5098c9346b56bb768564a0a82520faa3c5299f:ZeroJudge/NOT/a054.cpp
    }

    return 0;
}
