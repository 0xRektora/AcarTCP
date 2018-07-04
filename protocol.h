#include <Arduino.h>
#include "VirtualWire.h"

class Protocol {
  public:
    Protocol();
    void sendMessage(float *message, int taille);
    void receiveMessage(String *data);

};

