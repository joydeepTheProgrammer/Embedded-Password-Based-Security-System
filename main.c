#include "types.h"
#include "i2c2fun.h"
#include "delay.h"
#include "keypad.h"
#include "lcd.h"
#include <reg51.h>
#include <string.h>
sbit led = P1^7;
//LCD_Init();
u8 ID(u8);
u8 passadd[3]={0x08,0x0E,0x14};
main();

void extINT0(void) interrupt 0
{
	u8 ch,h[5],k=0;

	again:Write_CMD_LCD(0x01);
	Write_CMD_LCD(0x80);
	Write_str_LCD("1.ID1   2.ID2");
	Write_CMD_LCD(0xC0);
	Write_str_LCD("3.ID3   4.EXIT");
	ch=KeyValue();
	if(ch=='4')
		return;
	else if(ch>'4')
	{
		Write_CMD_LCD(0x01);
	  Write_CMD_LCD(0x80);
		Write_str_LCD("Invalid Input");
			delay_ms(1000);
		return;
	}
	else
	{
		Write_CMD_LCD(0x01);
Write_CMD_LCD(0x80);
Write_str_LCD("Enter Password :");	
Write_CMD_LCD(0xC0);
for(k=0;k<5;k++)
	{
		h[k]=KeyValue();
		Write_DAT_LCD('*');
	}

		k=KeyValue();
		if(k=='E')
			seq_write_EEPROM(0xD0,passadd[(ch-'1')],h,5);
		else
		{
			Write_str_LCD("Invalid Input");
			goto again;
		}
	}
	return;
}
main()
{
	
	u8 choice,ret,a[5]={'1','2','3','4','5'},b[5]={'6','7','8','9','0'},c[]={'1','6','3','8','5'};
	seq_write_EEPROM(0xD0,0x08,a,5);
	seq_write_EEPROM(0xD0,0x0E,b,5);
	seq_write_EEPROM(0xD0,0x14,c,5);
	IE=0x81;//EA=EX0=1
	IT0=0x01; 
	LCD_Init();
		while(1)
		{
open:	Write_CMD_LCD(0x01);
	Write_CMD_LCD(0x80);
	Write_str_LCD("SMART LOCKER");
		//Write_CMD_LCD(0xC0);
	//Write_str_LCD("DEVICE");
	delay_ms(3000);
	Write_CMD_LCD(0x01);
	Write_CMD_LCD(0x80);
	Write_str_LCD("1. ID1   2. ID2");
	Write_CMD_LCD(0xC0);
	Write_str_LCD("3. ID3   4. EXIT");
	choice=KeyValue();
	if(choice=='4')
		goto open;
	else if(choice>'4')
	{
		Write_CMD_LCD(0x01);
	  Write_CMD_LCD(0x80);
		Write_str_LCD("Invalid Input");
			delay_ms(1000);
		goto open;
	}
	else
		ret=ID(choice);
	if(ret==0)
	{
		Write_CMD_LCD(0x01);
	  Write_CMD_LCD(0x80);
		Write_str_LCD("Access Granted");
		led=~led;
		delay_ms(2000);
		Write_CMD_LCD(0x01);
		led=~led;
		goto open;
	}
	else
	{
		Write_CMD_LCD(0x01);
	  Write_CMD_LCD(0x80);
		Write_str_LCD("Device Blocked");
		while(1);
	}
}
	return ;
}

u8 ID(u8 choice)
{
u8 *ptr,count=0,i=0,d[6],j;
start:Write_CMD_LCD(0x01);
Write_CMD_LCD(0x80);
Write_str_LCD("Enter Password :");	
Write_CMD_LCD(0xC0);
for(i=0;i<5;i++)
	{
		d[i]=KeyValue();
		Write_DAT_LCD('*');
	}
	j=KeyValue();
	if(j=='E')
		d[i]='\0';
	ptr=seq_read_EEPROM(0xD0,passadd[(choice-'1')],5);
	if(strcmp(ptr,d)==0)
	{
		return 0;
	}
	else
	{
		count++;
		if(count==3)
			return (1);
		goto start;
	}
}
