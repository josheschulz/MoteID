#ifndef RFM69_h
#define RFM69_h
#include <Arduino.h>            

/*
   TODO: Add the ability to provide a custom offset to the location in EEPROM
*/

//Master and Remotes will all use the struct.  Wasting bytes like crazy.
struct IDStruct{
   int NodeID,
   int NextNodeID
}


class MoteID{
   public:
      bool isMaster();
      bool setAsMaster();
      int getNodeID();
   protected:
      int MasterID;
      int NodeID;
      bool isMaster;
      int getIDFromEEPROM();
      int getIDFromMaster();
         
}

#endif


