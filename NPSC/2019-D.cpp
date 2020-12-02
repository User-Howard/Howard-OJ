#include<iostream>
#include <stdint.h>
using namespace std;


char s[1000002];
uint64_t MeowHash(char *s) {
    uint64_t meow = 7122ul;
    while (*s != 0)
    meow = (meow << 13) ^ (meow >> 11) ^ (meow << 9)
        ^ (meow >> 7) ^ (meow << 5) ^ (meow >> 3)
        ^ (meow << 1) ^ ((uint64_t)(*s++) * 0xdeadbeeful);
    return meow;
}
int main(){
    scanf("%s", s);
    cout<<MeowHash(s)<<endl;
    return 0;
}
