#include<iostream>
#include<cmath>


int main(){
    int N;
    while(std::cin>>N && N){
        int answer=0;
        for(int i=0;i<N;i++)
            answer+=pow(N-i, 2);
        std::cout<<answer<<std::endl;
    }
    return 0;
}