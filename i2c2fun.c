#include"types.h"
#include"delay.h"
#include"i2c2ini.h"
void seq_write_EEPROM(u8 SlaveAddr,u8 Buff_Addr,u8 *ptr,u8 cnt)
{
	u8 i;
	I2C_start();
	I2C_write_byte(SlaveAddr);//8-bit word(7-bit Slave addr+R/w)
	I2C_slaveack();
	I2C_write_byte(Buff_Addr);//8-bit buff addr is sent for writing
	I2C_slaveack();
	for(i=0;i<cnt;i++)
	{
		I2C_write_byte(*ptr++);
		I2C_slaveack();	
	}
	I2C_stop();
	
}

//Sequential Read(Reading from the continous locations)
u8*  seq_read_EEPROM(u8 SlaveAddr,u8 Buff_Addr,u8 cnt)
{
	u8 a[6],i;
	I2C_start();
	I2C_write_byte(SlaveAddr);//8-bit word(7-bit Slave addr+R/w)
	I2C_slaveack();
	I2C_write_byte(Buff_Addr);//8-bit buff addr is sent for writing
	I2C_slaveack();
	I2C_restart();
	I2C_write_byte(SlaveAddr|0x01);//8-bit word(7-bit Slave addr+R/w)
	I2C_slaveack();
	for(i=0;i<(cnt-1);i++)
	{
		a[i]=I2C_read_byte();
		I2C_masterack();
	}
	a[i]=I2C_read_byte();
	I2C_masternoack();
	I2C_stop();
	a[i+1]='\0';
	return(a);
}	
