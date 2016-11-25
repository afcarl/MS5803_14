/* MS5803_14_test.ino

  A basic sketch to test communication with a Measurement Specialties MS5803
  pressure sensor using a Teensy 3.X microcontroller. 

  Luke Miller April 1 2014
  Simon D. Levy 10 November 2016
*/

#include <MS5803_14.h> 

MS_5803 sensor(0x76, 1, I2C_PINS_37_38, I2C_PULLUP_EXT, I2C_RATE_400);

void setup() {

  sensor.begin();

  // Start the serial ports.
  Serial.begin(9600); // other values include 9600, 14400, 57600 etc.
  delay(2000);

  // Initialize the MS5803 sensor. This will report the
  // conversion coefficients to the Serial terminal if present.
  // If you don't want all the coefficients printed out, 
  // set sensor.initializeMS_5803(false).
  if (sensor.begin()) {
    Serial.println( "MS5803 CRC check OK." );
  } 
  else {
    Serial.println( "MS5803 CRC check FAILED!" );
  }
  delay(3000);
}

void loop() {

  // Use readSensor() function to get pressure and temperature reading. 
  sensor.readSensor();

  // Show pressure
  Serial.print("Pressure = ");
  Serial.print(sensor.pressure());
  Serial.println(" mbar");
  
  // Show temperature
  Serial.print("Temperature = ");
  Serial.print(sensor.temperature());
  Serial.println("C");

  delay(1000); // For readability
}



