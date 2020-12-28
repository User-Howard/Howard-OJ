#include<iostream>
using namespace std;


int main(int argc, char* argv[]){
    cout<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
    for(int i=1;i<argc;++i)
        cout<<"~ "<<"argv["<<i<<"]= "<<argv[i]<<endl;
    cout<<"~~~~~~~~~~~~~~~~~~~~"<<endl;
    return 0;
}