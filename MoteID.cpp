#include <MoteID.h>
#include <EEPROM.h>

/*    Base Constructor

   This constructor will initialze the moteino as a master.  It won't ask anybody 
      else for it's ID, it will pull it out of EEPROM.  If there's nothing in 
      memory it will take #1 for itself.
*/

#define NODE_ID_ADDRESS 0
/*
MoteID::MoteID(){
   
}
*/

void MoteID::init(bool asMaster){
   //TODO:  Assuming right now that I'm the master

   //Read my ID from EPROM. 
   IDStruct idInfo;
   byte* p = (byte*)(void*)&idInfo;
   int address = NODE_ID_ADDRESS;
   char buf[10];
   for (unsigned int i = 0; i < sizeof(IDStruct); i++) {

        *p++ = EEPROM.read(address++);
         sprintf(buf, "Read %02X", p);
         Serial.println(buf);
         //STOP
    }
  
   if(Serial){
      Serial.println("Loaded ID Info");
      Serial.print(" ID: ");
      Serial.println(idInfo.NodeID);
     
      Serial.print(" NextID: ");
      Serial.println(idInfo.NextNodeID);
   }
   //At this point idInfo has everything we need
   if(idInfo.NodeID == -1){ //-1 == 0xFF unless I'm horribly misremembering my CS education.  
      //We've never done this before... Set my node id and the next Node ID
      idInfo.NodeID = 1;
      idInfo.NextNodeID = 2; 

      int address = NODE_ID_ADDRESS;
      byte *p = (byte*)(void*)&idInfo;

      for(unsigned int i = 0 ; i < sizeof(IDStruct); i++){
         EEPROM.write(address + i, *p++);
         Serial.print("Writing: ");
         Serial.println(*p++);
      }
   }
   _NodeID = idInfo.NodeID;
 
}

bool MoteID::isMaster(){
   return _isMaster;
}

int MoteID::getNodeID(){
   return _NodeID;
}

int MoteID::getMasterID(){
   return 0;
}

int MoteID::_getIDFromEEPROM(){
   return 0;
}

int MoteID::_getIDFromMaster(){
   return 0;
}

int MoteID::_writeNextID(){
   return 0;
}

int MoteID::_writeNodeID(){
   return 0;
}

