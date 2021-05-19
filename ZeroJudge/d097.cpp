#include<iostream>
#include<vector>
using namespace std;



int main(void)
{    
    vector< bool > number_l(3000);
    vector< int > li(3000);
    int len;
    while(scanf("%d",&len) != EOF)
    {
        for(int i=0;i<len;i++)
            scanf("%d",&li[i]);

        for(int i=0;i<3000;i++)
            number_l[i]=true;

        for(int i=0;i<len-1;i++)
            number_l[abs(li[i]-li[i+1])]=false;

        bool ist=true;

        for(int i=1;i<len;i++)
            if(number_l[i])
            {
                //cout<<i<<endl;
                ist=false;
                break;
            }
        
        if(ist)
            printf("Jolly\n");
        else
            printf("Not jolly\n");

    }
    //cout<<number_l[3];
    return 0;
}