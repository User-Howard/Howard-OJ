#include<iostream>
#include<map>
#include<math.h> 
using namespace std;


int main(void)
{
    map<char,int>Rome;
    Rome['I']=1;
    Rome['V']=5;
    Rome['X']=10;
    Rome['L']=50;
    Rome['C']=100;
    Rome['D']=500;
    Rome['M']=1000;
    ///
    string a,b;
    int sum=0,asum=0,bsum=0;
    while(cin>>a && a!="#" && cin>>b)
    {
        asum=0;
        bsum=0;
        ///
        for(int i=0;i<a.length();i++){
            asum+=Rome[a[i]];
        }
        for(int i=0;i<a.length()-1;i++){
            if(Rome[a[i]]<Rome[a[i+1]]){
                asum-=Rome[a[i]]*2;
            }
        }
        for(int i=0;i<b.length();i++){
            bsum+=Rome[b[i]];
        }
        for(int i=0;i<b.length()-1;i++){
            if(Rome[b[i]]<Rome[b[i+1]]){
                bsum-=Rome[b[i]]*2;
            }
        }
        sum=abs(asum-bsum);
        ///
        if(a == b){
            printf("ZERO\n");
        }
        else{
//            cout<<asum<<" "<<bsum<<endl;MCMXCVIII
            map<int,string>wx;
            wx[4000]="MMMM";
            wx[3000]="MMM";
            wx[2000]="MM";
            wx[1000]="M";
            wx[900]="CM";
            wx[800]="DCCC";
            wx[700]="DCC";
            wx[600]="DC";
            wx[500]="D";
            wx[400]="CD";
            wx[300]="CCC";
            wx[200]="CC";
            wx[100]="C";
            wx[90]="XC";
            wx[80]="LXXX";
            wx[70]="LXX";
            wx[60]="LX";
            wx[50]="L";
            wx[40]="XL";
            wx[30]="XXX";
            wx[20]="XX";
            wx[10]="X";
            wx[9]="IX";
            wx[8]="VIII";
            wx[7]="VII";
            wx[6]="VI";
            wx[5]="V";//MCMXCIX MCMXCVIII
            wx[4]="IV";
            wx[3]="III";
            wx[2]="II";
            wx[1]="I";
//            cout<<asum<<" "<<bsum<<endl;
            for(int i=4000;i>0;i--){
                if(wx[i] != "" && sum>=i){
                    cout<<wx[i];
                    sum-=i;
                }
            }
            printf("\n");
        }
    }
    ///
    return 0;
}
