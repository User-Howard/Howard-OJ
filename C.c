# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <math.h>



int N=0;
char* int_to_base18(int x) {
    char *c = malloc(100*sizeof(char));
    int T=0;
    while(x) {
        char tc;
        switch (x%18)
        {
        case 0:
        case 1:
        case 2:
        case 3:
        case 4:
        case 5:
        case 6:
        case 7:
        case 8:
        case 9:
            tc = '0' + (x%18);
        break;

        case 10:
        case 11:
        case 12:
        case 13:
        case 14:
        case 15:
        case 16:
        case 17:
            tc = 'A'+(x%18-10);
        break;
        }
        c[T++] = tc;
        x /=18;
    }
    for(int i=0;i<T/2;++i) {
        char tmp = c[T-i-1];
        c[T-i-1]= c[i];
        c[i] = tmp;
    }
    return c;
}
int ctoint(char c) {
    if('0'<=c && c <='9')
        return c-'0';
    else 
        return (int)(c-'A')+10;
}
int b18_to_int(char c[], int T) {
    int tmp = 1;
    int answer = 0;
    for(int i=T-1;i>=2;--i) {
        answer += tmp*(ctoint(c[i]));
        tmp*=18;
    }
    return answer;
}
int stoi(char c[], int T) {
    int answer = 0;
    for(int i=0;i<T;++i) {
        answer = answer*10+ctoint(c[i]);
    }
    return answer;
}
int main(){
    int T;
    scanf("%d", &T);
    
    /*
    char* c;
    c = int_to_base18(28597031);
    printf("%s\n", c);
    */
    // printf("%d\n", b18_to_int(c, strlen(c)));
    while(T--) {

    
    char a[10000];
    char b[10000];
    scanf("%s", &a);
    scanf("%s", &b);

    int ia;
    int ib = b18_to_int(b, strlen(b));
    if(a[0] == '0')
        ia = b18_to_int(a, strlen(a));
    else
        ia = stoi(a, strlen(a));
    if(b[0] == '0')
        ib = b18_to_int(b, strlen(b));
    else
        ib = stoi(b, strlen(b));
    //printf("%d %d\n", ia, ib);
    int ans = ia+ib;
    if(ans == 0) {
        printf("Sum in hexadecimal number is: 0y0\n");
        continue;
    }
    char* c;
    c = int_to_base18(ans);
    printf("Sum in hexadecimal number is: 0y%s\n", c);
    
    }
}
