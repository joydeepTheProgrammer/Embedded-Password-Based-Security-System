#include"types.h"
#include<reg51.h>
sbit sclk=P1^0;
sbit sda=P1^1;
void I2C_start(void)
{
	sclk=0;
    sda=1;
	sclk=1;
	sda=0;
}
void I2C_restart(void)
{
	sclk=0;
    sda=1;
	sclk=1;
	sda=0;
}

void I2C_stop(void)
{
	sclk=0;
    sda=0;
	sclk=1;
	sda=1;
}
//master write(8-bits) to slave
void I2C_write_byte(u8 ch)
{
	s8 i;
	for(i=7;i>=0;i--)
	{
		sclk=0;
		sda=(ch>>i)&1;
		sclk=1;
	}
}
//master reading(8-bits) from slave
u8 I2C_read_byte(void)
{
	u8 ch=0;
	s8 i;
	for(i=7;i>=0;i--)
	{
		sclk=0;
		sclk=1;
		if(sda==1)
			ch|=1<<i;//bit set logic
	
	}
	return(ch);
}
//Slave Ack(After receiving 8-bits from master, Slave sends ack)
void I2C_slaveack(void)
{
	sclk=0;
	sda=1;//Master(transmitter) is releasing the bus
	sclk=1;
	if(sda==1)//Ack has not come from the slave
		I2C_stop();		
}
//Master no ack
void I2C_masternoack(void)
{
	sclk=0;
	sda=1;
	sclk=1;	
}
//Master ack
void I2C_masterack(void)
{
	sclk=0;//Master makes clk as low
	sda=0;//master pullds sda line low
	sclk=1;
	sclk=0;//one clk pulse
	sda=1;//master released the bus so slave can regain the sda line
          //control
}

