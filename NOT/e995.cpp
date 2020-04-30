//e995
#include<iostream>
#include<sstream>
#include<cmath>

using namespace std;

string str(long long int a)
{
    string Ans;
    stringstream s;
    s<<a;
    s>>Ans;
    return Ans;
}

int solve(int a)
{
    // 9 90 900 9000 90000
    int i=0,rest=0;
    while(a != 0)
    {
        a/=10;
        i++;
    }
    cout<<i;
}

int main(void)
{
    
    string lstr="";
    long long int N=9000000000,i=0;
    solve(999);
    while(scanf("%lld",&N) != EOF)
    {
        break;
    }
    
    return 0;
}
//123456789101112131415161718192021222324252627282930313233343536373839404142434445464748495051525354555657585960
//99100101102103104105106107108109