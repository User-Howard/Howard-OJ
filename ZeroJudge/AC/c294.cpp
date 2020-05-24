#include<iostream>
#include<algorithm>
using namespace std;


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int li[3];
    cin>>li[0]>>li[1]>>li[2];
    sort(li,li+3);
    cout<<li[0]<<" "<<li[1]<<" "<<li[2]<<endl;
    if(li[0]+li[1]<=li[2])
        cout<<"No"<<endl;
    else if(li[0]*li[0]+li[1]*li[1]>li[2]*li[2])
        cout<<"Acute"<<endl;
    else if(li[0]*li[0]+li[1]*li[1]==li[2]*li[2])
        cout<<"Right"<<endl;
    else if(li[0]*li[0]+li[1]*li[1]<li[2]*li[2])
        cout<<"Obtuse"<<endl;

    return 0;
}