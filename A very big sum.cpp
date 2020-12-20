#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
using namespace std;


// int: -2147483647~2147483647
class BigNumber
{
public:
    vector<char > ar = {};
    void add(string str);
    void print();
};
void BigNumber::add(string str)
{
    for(int i=0;i<str.size();i++){
        if(ar.size()<i+1)
            ar.push_back(str[str.size()-i-1]);
        else {
            int p=ar[i]-'0'+str[str.size()-i-1]-'0';
            if(p<10){
                ar[i] = p +'0';
            }
            else if(ar.size()<=i+1){
                ar[i] = p%10 +'0';
                ar.push_back(p/10 +'0');
            }
            else{
                //
            }
        }
    }
    return;
}
void BigNumber::print()
{
    for(int i=ar.size()-1;i>=0;i--)
        cout<<ar[i];
    cout<<endl;
    return;
}
int main(void)
{
    BigNumber E;
    int N;
    string s;
    cin>>N;
    while(N--){
        cin>>s;
        E.add(s);
    }
    E.print();
    return 0;
}
