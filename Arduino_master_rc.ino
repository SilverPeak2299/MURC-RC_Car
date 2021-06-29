#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

RF24 radio(7, 8); // CE, CSN

const byte address[6] = "00001";
char *msg {NULL};

void setup() {
  Serial.begin(9600);
  radio.begin();
  radio.openWritingPipe(address);
  radio.setPALevel(RF24_PA_MIN);
  radio.stopListening();
  
}

void loop() {
  while(Serial.available()) {
   int n {(Serial.readString()).length()};
   msg = new char [n];
   *msg = Serial.read();
   radio.write(msg, (n-1));
   delete [] msg;
   msg = NULL;
  }
}
