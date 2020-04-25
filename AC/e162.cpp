#include <iostream>
using namespace std;

int main(void)
{
    int times, R;
    int Cp[50], Iv[50], EndCp[50];
    scanf("%d %d", &times, &R);
    for(int i = 0; i < times; i++)
        scanf("%d %d", &Cp[i], &Iv[i]);


    for(int i = 0;i<times;i++)
    {
        if(Iv[i] <= 29)
            EndCp[i]=Cp[i] + (R/1000)*10;
        else if(Iv[i] <=39)
            EndCp[i]=Cp[i] + (R/1000)*50;
        else if(Iv[i] <= 45)
            EndCp[i]=Cp[i] + (R/1000)*100;
    }

    int maxium=0;
    for(int i=1;i<times;i++)
    {
        if(EndCp[maxium]<EndCp[i])
            maxium=i;
    }
    printf("%d %d\n",maxium+1,EndCp[maxium]);
    return 0;
}