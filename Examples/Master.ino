#include <MoteID.h>
#include <EEPROM.h>

void eeprom_serial_dump_column() {
  // counter
  int i;

  // byte read from eeprom
  byte b;

  // buffer used by sprintf
  char buf[10];

  for (i = 0; i <= 16; i++) {
    b = EEPROM.read(i);
    sprintf(buf, "%03X: %02X", i, b);
    Serial.println(buf);
  }
}

void setup() {
  Serial.begin(115200);
  delay(100);

  MoteID myID;

  eeprom_serial_dump_column();
   myID.init(true);
  Serial.print("Am I the master?");
  if(myID.isMaster()){
      Serial.println(" Yes");
   } else {
      Serial.println(" No");
   }

   Serial.print("My ID is: ");
   Serial.println( myID.getNodeID());
 
}


void loop() {
}


