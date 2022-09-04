#include<iostream>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    string li[10] = { "BNZ" ,"AMW" ,"KLY" ,"JVX" ,"HU" ,"GT" ,"FS" ,"ER" ,"DOQ" ,"CIP"};
    int check, sum;
    string R;
    cin >> R;
    sum = 0;
    check = R[8]-'0';
    for(int i=0;i<8;i++)
        sum += (R[i]-'0')*(8-i);
    cout << li[(20 - check - (sum%10))%10] << '\n';

    return 0;
}
