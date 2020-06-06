#include<iostream>
#include<algorithm>
using namespace std;


int Repr(int );


int main(void){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int s1, s2, max;
    while(cin>>s1>>s2){
	printf("%d %d", s1, s2);
        if(s2<s1) swap(s1, s2);
        max=-1;
        for(int i=s1;i<=s2;i++){
            if(max<Repr(i)) max=Repr(i);
        }
        printf(" %d\n", max);
    }
    
    return 0;
}
int Repr(int a){
    int step=1;
    while(a!=1){
        if(a%2){
            a=3*a+1;
        }
        else{
            a=a/2;
        }
        step++;
    }
    return step;
}