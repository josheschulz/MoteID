#ifndef RFM69_h
#define RFM69_h
#include <Arduino.h>            

/*
   TODO: Add the ability to provide a custom offset to the location in EEPROM
*/

//Master and Remotes will all use the struct.  Wasting bytes like crazy.
//NOTE: These structs need to be
// the exact same.  NextNodeID == Master ID if you're
// not a master
typedef struct {
   int NodeID;
   int NextNodeID;
} IDStruct;

typedef struct {
   int YourID;
   int MasterID;
} IDInfo;

class MoteID{
   public:
      void init(bool asMaster);
      bool isMaster();
      int getNodeID();
      int getMasterID();
   protected:
      int _MasterID;
      int _NodeID;
      bool _isMaster;
      int _getIDFromEEPROM();
      int _getIDFromMaster();
      int _writeNodeID();
      int _writeNextID(); 
};

#endif


