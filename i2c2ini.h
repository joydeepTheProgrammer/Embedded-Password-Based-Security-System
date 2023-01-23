#include"types.h"
void I2C_start(void);
void I2C_stop(void);
void I2C_write_byte(u8 ch);
u8 I2C_read_byte(void);
void I2C_slaveack(void);
void I2C_restart(void);
void I2C_masterack(void);
void I2C_masternoack(void);



