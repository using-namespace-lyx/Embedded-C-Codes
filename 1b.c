#include<lpc214x.h>

#define SW1 (IO0PIN&(1<<14))
#define SW2 (IO0PIN&(1<<15))
#define SW3 (IO1PIN&(1<<18))
#define SW4 (IO1PIN&(1<<19))

unsigned int ls=1,rs=1<<7,contup=0,contdwn=99;

void delay(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<10000;j++);
	}
}

void reset_values(int i)
{
	switch(i)
	{
		case 0:
			contdwn=99;
			ls=1;
		rs=1<<7;
		break;
		
			case 1:
			contup=0;
			ls=1;
		rs=1<<7;
		break;
			
				case 2:
			contup=0;
			contdwn=99;
		rs=1<<7;
		break;
				
					case 3:
			contdwn=99;
			ls=1;
		contup=0;
		break;
		
		}
}
		
int main()
{
	IO0DIR=0XFF<<16;
	IO0SET=0XFF<<16;
	while(1)
	{
		if(!SW1)
		{
			reset_values(0);
			IO0SET=0xFF<<16;
			IO0CLR=(((contup/10)<<4)|contup%10)<<16;
			contup++;
			if(contup>99)
				contup=0;
		}
		if(!SW2)
		{
			reset_values(1);
			IO0SET=0xFF<<16;
			IO0CLR=(((contdwn/10)<<4)|contdwn%10)<<16;
			contdwn--;
			if(contdwn<0)
				contdwn=99;
		}
		if(!SW3)
		{
			reset_values(2);
			IO0SET=0xFF<<16;
			IO0CLR=(ls)<<16;
			ls<<=1;
			if(ls>1<<7)
				ls=1;
		}
		if(!SW4)
		{
			reset_values(3);
			IO0SET=0xFF<<16;
			IO0CLR=(rs)<<16;
			rs>>=1;
			if(rs<1)
				rs=1<<7;
		}
		
		delay(300);
	}
}	
