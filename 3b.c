#include<lpc214x.h>

void delay(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<10000;j++);
	}
}

int main()
{
	unsigned int a=100,b=100;
	IO0DIR=0XFF<<16;
	
	IO0CLR=0XFF<<16;
	
	while(1)
	{
		IO0CLR=0XF<<16;IO0DIR=1<<16;delay(10);if(--a==0)break;
		IO0CLR=0XF<<16;IO0DIR=1<<17;delay(10);if(--a==0)break;
		IO0CLR=0XF<<16;IO0DIR=1<<18;delay(10);if(--a==0)break;
		IO0CLR=0XF<<16;IO0DIR=1<<19;delay(10);if(--a==0)break;
	}
	
	while(1)
	{
		IO0CLR=0XF<<16;IO0DIR=1<<19;delay(10);if(--b==0)break;
		IO0CLR=0XF<<16;IO0DIR=1<<18;delay(10);if(--b==0)break;
		IO0CLR=0XF<<16;IO0DIR=1<<17;delay(10);if(--b==0)break;
		IO0CLR=0XF<<16;IO0DIR=1<<16;delay(10);if(--b==0)break;
	}
}
	
		
	
	