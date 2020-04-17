#include<iostream>
#include<math.h> 
using namespace std;

bool problemis(bool all[],int a){
    for(int i=1;i<a;i++){
        if(all[i]==true){
            return false;
        }
    }
    return true;
}

int main(void)
{
    int a,de[]={0};
    while(cin>>a){
        for(int i=0;i<a;i++){
            cin>>de[i];
        }
        bool all[a];
        for(int i=1;i<a;i++){
            all[i]=true;
        }
        for(int i=0;i<a-1;i++){
            if(1<=abs(de[i]-de[i+1]) && abs(de[i]-de[i+1])<=a-1){
                all[abs(de[i]-de[i+1])]=false;
            }
        }
        if(problemis(all,a)){
            printf("Jolly\n");
        }
        else{
            printf("Not jolly\n");
        }
    }
    return 0;
}
