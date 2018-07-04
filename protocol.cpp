#include "protocol.h"   

Protocol::Protocol() {

}

void Protocol::sendMessage(float *message, int taille) {
  String bDatas = "";
  for(int i = 0; i < taille; i++){
    bDatas += String(message[i]);
    bDatas += ',';
  }
  bDatas += '\0';
  uint8_t datas[bDatas.length()];
  for(int i = 0; i < bDatas.length(); i++){
    datas[i] = uint8_t(char(bDatas[i]));
  }
  /*Serial.println("Testing :" );
  for(int i = 0; i < bDatas.length(); i++){
    Serial.print(datas[i]);
    Serial.print(",");
  }
  Serial.println("");
  Serial.println(bDatas);*/
  vw_send(datas, bDatas.length());
  vw_wait_tx();
}

void Protocol::receiveMessage(String *data) {
  uint8_t bDatas[250];
  vw_get_message(bDatas, 250);
  Serial.println("Trying to receive");
  //vw_wait_rx();
  Serial.println("receive");

  char temp = '0';
  for(int i = 0; i < 250; i++){
    temp = char(bDatas[i]);
    Serial.println("Receiving : " + temp);
    if(bDatas[i] == 0){
      break;
    }
    else{
      *data += temp;
    }
  }

  

}


