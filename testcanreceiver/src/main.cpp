#include <Arduino.h>
#include <FlexCAN.h>

FlexCAN can(50000);
CAN_message_t rxmsg;

static uint8_t hex[17] = "0123456789abcdef";

static void hexDump(uint8_t dumpLen, uint8_t *bytePtr)
{
  uint8_t working;
  while( dumpLen-- ) {
    working = *bytePtr++;
    Serial.write( hex[ working>>4 ] );
    Serial.write( hex[ working&15 ] );
  }
  Serial.write('\r');
  Serial.write('\n');
}


void setup() {
can.begin();
pinMode(13, OUTPUT);
delay(1000);
}


void loop() {
  //hexDump(8, rxmsg.buf);
  Serial.println("data: ");
  Serial.println(rxmsg.buf[0]);
  Serial.println("data buffer: ");
  Serial.println(can.read(rxmsg));
  if(can.read(rxmsg))
  digitalWrite(13,HIGH);
  delay(500);

}
