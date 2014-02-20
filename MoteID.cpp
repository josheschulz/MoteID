#include <MoteID.h>
#include <EEPROM.h>

/*    Base Constructor

   This constructor will initialze the moteino as a master.  It won't ask anybody 
      else for it's ID, it will pull it out of EEPROM.  If there's nothing in 
      memory it will take #1 for itself.
*/

#define NODE_ID_ADDRESS 0

MoteID::MoteID(){
   //Read my ID from EPROM. 
   IDStruct idInfo;
   byte* p = (byte*)(void*)&idInfo;
   int address = NODE_ID_ADDRESS;
   for (int i = 0; i < sizeof(IDStruct); i++) {
        *p++ = EEPROM.read(address++);
    }

   //At this point idInfo has everything we need
   if(idInfo.NodeID == -1){ //-1 == 0xFF unless I'm horribly misremembering my CS education.  
      //We've never done this before... Set my node id and the next Node ID
   } 
}

MoteID::MoteID(int masterID){

}

bool MoteID::isMaster(){

}

int MoteID::getNodeID(){

}

int MoteID::getIDFromEEPROM(){

}

int MoteID::getIDFromMaster(){

}

