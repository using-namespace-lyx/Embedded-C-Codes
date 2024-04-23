#include<lpc214x.h>
#define SW1 (IO0PIN&(1<<14))
#define SW2 (IO0PIN&(1<<15))
#define SW3 (IO1PIN&(1<<18))
#define SW4 (IO1PIN&(1<<19))
#define SW5 (IO1PIN&(1<<20))

short int sine[]={0,53,106,157,207,255,300,341,379,413,442,466,485,499,508,511,
	508,499,485,466,442,413,379,341,300,255,207,157,106,53,0,
	-53,-106,-157,-207,-255,-300,-341,-379,-413,-442,-466,-485,-499,-508,-511,
	-508,-499,-485,-466,-442,-413,-379,-341,-300,-255,-207,-157,-106,-53
};
short int half[]={0,53,106,157,207,255,300,341,379,413,442,466,485,499,508,511,
	508,499,485,466,442,413,379,341,300,255,207,157,106,53};
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
	short int value,i;
	PINSEL1|=(0x3<<((25-16)*2));
	IO0DIR=0XFF<<16;
	
	while(1)
	{
		if(!SW1)
		{
			i=0;
			while(i!=60)
			{
				value=512+sine[i++];
				DACR=((value<<6)|1<<16);
				delay(1);
			}
		}
		
		else if(!SW2)
		{
			i=0;
			while(i!=30)
			{
				value=512+half[i++];
				DACR=((value<<6)|1<<16);
				delay(1);
			}
		}
		else if(!SW3)
		{
			value=0;
			while(value!=1023)
			{
				
				DACR=((value<<6)|1<<16);
				value++;
				
			}
			while(value!=0)
			{
				
				DACR=((value<<6)|1<<16);
				value--;
				
			}
		}
		else if(!SW4)
		{
			value=0;
			while(value!=1023)
			{
				
				DACR=((value<<6)|1<<16);
				value++;
				
			}
		}
		
		else if(!SW5)
		{
			value=1023;
			DACR=((value<<6)|1<<16);
			delay(1);
			value=0;
			DACR=((value<<6)|1<<16);
			delay(1);
		}
		else
		{
			value=1023;
			DACR=((value<<6)|1<<16);
		}
	}
}
			
			
			
		
		
		