#include<lpc214x.h>

unsigned char getcode(unsigned char data)
{
	switch(data)
	{
		case 'f':
			return 0x
		case 'i':
			return 0x
		case 'r':
			return 0x
		case 'e':
			return 0x
		case 'h':
			return 0x
		case 'l':
			return 0x
		case 'p':
			return 0x
		default:
			return 0x
			}
		}

void delay(unsigned int n)
{
	unsigned int i,j;
	for(i=0;i<n;i++)
	{
		for(j=0;j<10000;j++);
	}
}

void display(char*buffer)
{
	unsigned char i,j,temp,data;
	
	for(i=0;i<5;i++)
	{
		data=getcode(*(buf+i));
		for(j=0;j<8;j++)
		{
			temp=data&(1<<7);
			if(temp)
				IO0SET|=1<<19;
			else
				IO0CLR|=1<<19;
			
			IO0SET=1<<20;
			delay(1);
			IO0CLR=1<<20;
			
		data<<=1;
		}
	}
	IO0SET|=1<<30;
	delay(1);
	IO0CLR|=1<<30;
	
}

int main()
{
	IO0DIR=1<<20|1<<19|1<<30;
	while(1)
	{
		display("fire ");
		delay(500);
		display("help ");
		delay(500);
	}
}

	
		