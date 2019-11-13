// I2C Scanner

#include <Wire.h>

#define SDA_PIN   4    // Arduino nano - A4 ; NodeMCU - D1 
#define SCL_PIN   5    // Arduino nano - A5 ; NodeMCU - D2

void setup() {
  Serial.begin (115200);

  Wire.begin(SDA_PIN, SCL_PIN);

  while (!Serial) { }

  Serial.println ();
  Serial.println ("Scanning ...");
  byte count = 0;

  Wire.begin();

  // ONLY FOR ARDUINO
  //TWBR = 12;  // 400 kHz (maximum)

  for (byte i = 8; i < 120; i++)
  {
    Wire.beginTransmission (i);
    if (Wire.endTransmission () == 0)
    {
      Serial.print ("Found address: ");
      Serial.print (i, DEC);
      Serial.print (" (0x");
      Serial.print (i, HEX);
      Serial.println (")");
      count++;
      delay (1);
    }
  }
  Serial.println ("Done.");
  Serial.print ("Found ");
  Serial.print (count, DEC);
  Serial.println (" device(s).");
}

void loop() {}
