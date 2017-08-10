/*	MS5803_14
 * 	A Teensy 3,X library for the Measurement Specialties MS5803 family
 * 	of pressure sensors using the Teensy 3.X family of microcontrollers. 
 *	
 *	This library only works with the MS5803-14BA model sensor. It DOES NOT
 *	work with the other pressure-range models such as the MS5803-30BA or
 *	MS5803-01BA. Those models will return incorrect pressure and temperature 
 *	readings if used with this library. See http://github.com/millerlp for
 *	libraries for the other models. 
 *	 
 * 	No warranty is given or implied. You are responsible for verifying that 
 *	the outputs are correct for your sensor. There are likely bugs in
 *	this code that could result in incorrect pressure readings, particularly
 *	due to variable overflows within some pressure ranges. 
 * 	DO NOT use this code in a situation that could result in harm to you or 
 * 	others because of incorrect pressure readings.
 * 	 
 * 	
 * 	Licensed under the GPL v3 license. 
 * 	Please see accompanying LICENSE.md file for details on reuse and 
 * 	redistribution.
 * 	
 * 	Copyright Luke Miller, April 1 2014
 *  Simon D. Levy 10 November 2016
 */


#ifndef __MS_5803__
#define __MS_5803__

#include <i2c_t3.h>

class MS_5803 {

public:

	// Constructor for the class. 
    // Simon D. Levy (sdl): added ability to specify I^2C parameters
    MS_5803(uint8_t address=0x76, uint8_t bus=0, i2c_pins pins=I2C_PINS_18_19, i2c_pullup=I2C_PULLUP_EXT, uint32_t i2cRate=I2C_RATE_400);

    // Initialize the sensor 
    boolean begin(uint16_t resolution = 512, boolean verbose = true);

    // Reset the sensor
    void resetSensor();

    // Read the sensor
    void readSensor();

    //*********************************************************************
    // Additional methods to extract temperature, pressure (mbar), and the 
    // D1,D2 values after readSensor() has been called
    
    // Return temperature in degrees Celsius.
    float temperature() const {return tempC;}  

    // Return pressure in mbar.
    float pressure() const {return mbar;}

    // Return the D1 and D2 values, mostly for troubleshooting
    unsigned long D1val() const {return D1;}
    unsigned long D2val() const {return D2;}
    
    
private:

    // sdl    
    uint8_t    _address;
    uint8_t    _bus;
    i2c_pins   _pins;
    i2c_pullup _pullups;
    uint32_t   _i2cRate;
    
    float mbar; // Store pressure in mbar. 
    float tempC; // Store temperature in degrees Celsius
    unsigned long D1;	// Store D1 value
    unsigned long D2;	// Store D2 value
    int32_t mbarInt; // pressure in mbar, initially as a signed long integer

    // Check data integrity with CRC4
    unsigned char MS_5803_CRC(unsigned int n_prom[]); 

    // Handles commands to the sensor.
    unsigned long MS_5803_ADC(char commandADC);

    // Oversampling resolution
    uint16_t _resolution;
};

#endif 
