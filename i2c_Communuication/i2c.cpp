/****************************************************************************** 
	i2ctest.cpp Raspberry Pi I2C interface demo prasad @ mpulse
	Electronics> 4/21/2017 https://github.com/sparkfun/Pi_Wedge A brief 
	demonstration of the Raspberry Pi I2C interface,Resources: This example 
	makes use of the Wiring Pi library, which streamlines the interface the the I/O pins on the 
	Raspberry Pi, providing an API that is similar to the Arduino.  You can 
	learn about installing Wiring Pi here: 
	http://wiringpi.com/download-and-install/ The I2C API is documented 
	here: https://projects.drogon.net/raspberry-pi/wiringpi/i2c-library/ The 
	init call returns a standard file descriptor.  More detailed 
	configuration of the interface can be performed using ioctl calls on 
	that descriptor. See the wiringPi I2C implementation 
	(wiringPi/wiringPiI2C.c) for some examples. Parameters configurable with 
	ioctl are documented here: 
	 The board was connected as follows: (Raspberry Pi)(Arduino) GND -> GND  SCL 
	-> A5 SDA -> A4  To compile g++ i2ctest.cpp -lwiringPi
	Then to run it, first the I2C kernel module needs to be loaded 
	To execute   ./i2c
******************************************************************************/
#include <iostream> 
#include <stdio.h>
#include <string.h>
#include <errno.h> 
#include <wiringPiI2C.h>
using namespace std; 
int main() {
	int fd,i=0, result,len;char str1[80] ;
	fd = wiringPiI2CSetup(0x04); // Arduino I2C Address default = 0x04 
	while(1)
	{
		cout << "Enter the Value=";    
		scanf ("%s",str1);
		len = strlen(str1);
		i=0;
		while (len != 0)
		{
			char value = str1[i++];
			printf ("%c\n",value);
			len -- ;
			result = wiringPiI2CWrite(fd,int(value));
		}
		wiringPiI2CWrite(fd,0x0A);     
		if(result == -1)
		{
			cout << "Error.  Errno is: " << errno << endl;
		}
	}
}

