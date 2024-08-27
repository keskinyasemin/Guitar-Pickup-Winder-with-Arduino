#include <EEPROM.h>

uint8_t EEPROMaddress = 130;
uint8_t EEPROMaddress2 = 131;

byte A=11, B=10, C=9, D=8;
int adim_sayisi=75;
int sayac=0;
int i = 0;
bool direction = true;
int x1 = 0, x2 = 0, x3 = 0, x4 = 0;
int adim_position[8][4] = { {1, 0, 0, 0},
                            {1, 1, 0, 0},
                            {0, 1, 0, 0},
                            {0, 1, 1, 0},
                            {0, 0, 1, 0},
                            {0, 0, 1, 1},
                            {0, 0, 0, 1},
                            {1, 0, 0, 1}   } ;

void setup () {
pinMode (A,OUTPUT);
pinMode (B,OUTPUT);
pinMode (C,OUTPUT);
pinMode (D,OUTPUT);
Serial.begin(9600);
//Serial.println("Hello World!");
}
void loop() {
  sayac = EEPROM.read(EEPROMaddress);
  direction = EEPROM.read(EEPROMaddress2);

  i = abs(sayac % 8);
  int sensorReading = analogRead(A0);
  int motorSpeed = map(sensorReading, 0, 1023, 0, 100);

  x1 = adim_position[i][0];
  x2 = adim_position[i][1];
  x3 = adim_position[i][2];
  x4 = adim_position[i][3];

  digitalWrite(A,x1);
  digitalWrite(B,x2);
  digitalWrite(C,x3);
  digitalWrite(D,x4);
  delay(motorSpeed+10); // 0-100

  if(direction == true){
  if(sayac < abs(adim_sayisi)){
    sayac++;
  }
  else {
    direction = false;
  }
  }
  else{
  if (sayac > 0){
    sayac--;
  }
  else {
    direction = true;
  }
  }
  EEPROM.write(EEPROMaddress2, direction);
  EEPROM.write(EEPROMaddress, sayac);
  Serial.println(sayac);
}