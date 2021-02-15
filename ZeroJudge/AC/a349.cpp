#include <iostream>
using namespace std;


const int MAX_SIZE = 1<<16;
int MS[MAX_SIZE]={0}, RD[MAX_SIZE]={0};
void load(int rd, int ms){
    RD[rd] = MS[ms];
}
void store(int md, int rs){
    MS[md] = RD[rs];
}
void add(int rd, int rs1, int rs2){
    RD[rd] = RD[rs1] + RD[rs2];
}
void move(int rd, int rs){
    RD[rd] = RD[rs];
}
void test(){
    for(int i=0;i<8;i++)
        cout<<MS[i]<<'\t';
    cout<<endl;
    for(int i=0;i<8;i++)
        cout<<RD[i]<<'\t';
    cout<<endl;
    
}
int main(){
    int N;
    string command;
    int a, b, c;
    for (int i=0;i<8;++i)
        cin>>MS[i];
    cin>>N;
    while (N--){
        cin>>command;
        if (command=="LOAD") {
            cin>>a>>b;
            load(a, b);
        }
        else if (command=="STORE") {
            cin>>a>>b;
            store(a, b);
        }
        else if (command=="ADD") {
            cin>>a>>b>>c;
            add(a, b, c);
        }
        else if (command=="MOVE") {
            cin>>a>>b;
            move(a, b);
        }
        // test();
    }
    cout<<RD[0]<<endl<<MS[0]<<endl;
    return 0;
}
