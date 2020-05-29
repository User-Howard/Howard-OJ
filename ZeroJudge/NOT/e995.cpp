//e995
#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;

string str(long long int a){
    string Ans;
    stringstream s;
    s<<a;
    s>>Ans;
    return Ans;
}

int len(int a){
    // 9 90 900 9000 90000
    int i=0,rest=0;
    while(a != 0)
    {
        a/=10;
        i++;
    }
    return i;
}

int main(void){
    
    string lstr="";
    long long int N,n,r;
    long long int li[]={0,9,90,900,9000,90000,900000,9000000,90000000,900000000,9000000000};
    int area=0;
    while(scanf("%lld",&N) != EOF){
        if(N<10)
            printf("%d\n",N);
        else{
            r = 0;
            for (int i = 0;; i++)
            {
                r += li[i];
                area = i;
                if (r + li[i + 1] >= N)
                {
                    break;
                }
            }
            n=N-r;
            int l;
            
            l=n/(area+1);
            if(n%(area+1) != 0)
            	l++;
            
            int Ans=l-1;
            printf("area=%d r=%d l=%d\n",area,n,l);
            cout<<str(Ans+pow(10,area))[(n-1)%(area+1)]<<endl;
        }
        
        
    }    
    return 0;
}
