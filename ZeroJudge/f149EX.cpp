#include<stdio.h>
int main()
{
	int a=0,b=0,all_bomb=0;
	int str[20][20];
	scanf("%d %d",&a,&b);
	for(int i=0;i<a;i+=1)
	{
		for(int j=0;j<b;j+=1)
		{
			scanf("%d",&str[i][j]);
		}
	}
	for(int i=0;i<a;i+=1)
	{
		for(int j=0;j<b;j+=1)
		{
			int flag=0;
			if(str[i][j]==1)
			{
				all_bomb+=1;
			}
			if(str[i][j]==5)
			{
				for(int k=-1;k<=1;k+=1)
				{
					for(int l=-1;l<=1;l+=1)
					{
						if(i+k<0||j+l<0||(i+k==i&&j+l==j)||i+k>=a||j+l>=b)
						{
							continue;
						}
						if(str[i+k][j+l]==5||str[i+k][j+l]==6)
						{
							str[i+k][j+l]=6;
							flag=1;
						}
						
					}
				}
				if(flag==1)
				{
					str[i][j]=0;	
				}	
			}	
		}
	}
	int detect_bomb=0;
	for(int i=0;i<a;i+=1)
	{
		for(int j=0;j<b;j+=1)
		{	
			int temp=0;	
			if(str[i][j]==5)
			{
				//bomb that is around the detector
				for(int k=-1;k<=1;k+=1)
				{
					for(int l=-1;l<=1;l+=1)
					{
						if(i+k<0||j+l<0||i+k>=a||j+l>=b)
						{
							continue;
						}
						if(str[i+k][j+l]==1)
						{
							detect_bomb+=1;
							str[i+k][j+l]=0;//remove the bomb
							temp=1;
						}
					}
				}		
			}	
		}
	}
	int not_detect_bomb = all_bomb-detect_bomb;
	printf("%d %d\n",detect_bomb,not_detect_bomb);
}
