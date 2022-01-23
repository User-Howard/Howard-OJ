#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math")
#include<bits/stdc++.h>
#include<unistd.h>
using namespace std;
int64_t cnt = 0;
inline void pc(char c){
    constexpr size_t buf_size=1<<20;
    static char buf[buf_size];
    static char *ptr=buf;
    if (ptr>=buf+buf_size||c==EOF)write(STDOUT_FILENO,buf,ptr-buf),ptr=buf;
    if (c!=EOF)*ptr++=c;
}
inline void print(long long x){
    if(x==0){pc('0');pc(' ');return;}
    static int stk[20];
    int *ptr;
    ptr=&stk[0];
    while(x){*ptr=x%10;x/=10;ptr++;}
    ptr--;
    while(ptr>=(&stk[0])){pc(*ptr+'0');pc(' ');ptr--;}
    pc('\n');
}

void solve(string s="", int last=20){

    if(last == 0){
        for(char c:s)
            pc(c), pc(' ');
        for(int i=0;i<9-s.size();++i)
            pc('0'), pc(' ');
        pc('\n');
        return ;
    }
    if(s.size() == 9){
        if(last == 0)
        {
            for(char c:s)
                pc(c), pc(' ');
            pc('\n');
        }
        return;
    }
    for(int i=0;i<10;++i){
        if(last >= i){
            solve(s+char('0'+i), last - i);
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    solve();
    pc(EOF);
    return 0;
}
