#include<iostream>
#include<stdio.h>
using namespace std;

string la[5]={
    "Medium Wac",
    "WChicken Nugget",
    "Geez Burger",
    "ButtMilk Crispy Chicken",
    "Plastic Toy"
};
int lai[5]{
    4,
    8,
    7,
    6,
    3
};
string lb[4]={
    "German Fries",
    "Durian Slices",
    "WcFurry",
    "Chocolate Sunday"
};
int lbi[4]{
    2,
    3,
    5,
    7
};
int main(void){
    int N, m, money=0;
    while(scanf("%d %d", &N, &m) == 2, N!=0){
        if(N == 1){
            cout<<la[m-1]<<" "<<lai[m-1]<<endl;
            money+=lai[m-1];
        }
        else if(N == 2){
            cout<<lb[m-1]<<" "<<lbi[m-1]<<endl;
            money+=lbi[m-1];
        }
    }
    cout<<"Total: "<<money<<endl;
    return 0;
}
