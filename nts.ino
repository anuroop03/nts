#include <SD.h>                      // need to include the SD library
//#define SD_ChipSelectPin 53  //example uses hardware SS pin 53 on Mega2560
#define SD_ChipSelectPin 4  //using digital pin 4 on arduino nano 328, can use other pins
#include <TMRpcm.h>           //  also need to include this library...
#include <SPI.h>

TMRpcm tmrpcm;   // create an object for use in this sketch


void setup(){

  tmrpcm.speakerPin = 9; //5,6,11 or 46 on Mega, 9 on Uno, Nano, etc

  Serial.begin(9600);
  if (!SD.begin(SD_ChipSelectPin)) {  // see if the card is present and can be initialized:
    Serial.println("SD fail");  
    return;   // don't do anything more if not
  }
  
}



void loop(){  
  long int num;
  num= Serial.read();
  if(num>999999999)
  return;
  int n[9];
  int i=0;
  while(num)
  {
    n[i]=num%10;
    num/=num;
    i++;
  }
  
  while(i)
{
 i--;
  switch(i)
  {
    case 8:sid(n[i]);
           tmrpcm.play("hundred.wav");
           
    case 7:mid(n[i],n[i-1]);
           tmrpcm.play("million.wav");
           i--;
           break;
    case 6:sid(n[i]);
           tmrpcm.play("million.wav");
           
           break;
    case 5:sid(n[i]);
           tmrpcm.play("hundred.wav");
           
           break;
    case 4:mid(n[i],n[i-1]);
           tmrpcm.play("thousand.wav");
           i--;
           break;
    case 3:sid(n[i]);
           tmrpcm.play("thousand.wav");
           break;
    case 2:sid(n[i]);
           tmrpcm.play("hundred.wav");
           
           break;
    case 1:mid(n[i],n[i-1]);
           i--;
           break;
    case 0:sid(n[i]);
           break;
    }
    
  }
}
void sid(int n)
{
  switch(n)
  {
    case 1: tmrpcm.play("1.wav");
            break;
    case 2: tmrpcm.play("2.wav");
            break;
    case 3: tmrpcm.play("3.wav");
            break;
    case 4: tmrpcm.play("4.wav");
            break;
    case 5: tmrpcm.play("5.wav");
            break;
    case 6: tmrpcm.play("6.wav");
            break;
    case 7: tmrpcm.play("7.wav");
            break;
    case 8: tmrpcm.play("8.wav");
            break;
    case 9: tmrpcm.play("9.wav");
            break;
  }
}
void mid(int n,int m)
{
  if(n==0||n==1)
  {
    n=n*10+m;
    switch(n)
  {
    case 1: tmrpcm.play("1.wav");
            break;
    case 2: tmrpcm.play("2.wav");
            break;
    case 3: tmrpcm.play("3.wav");
            break;
    case 4: tmrpcm.play("4.wav");
            break;
    case 5: tmrpcm.play("5.wav");
            break;
    case 6: tmrpcm.play("6.wav");
            break;
    case 7: tmrpcm.play("7.wav");
            break;
    case 8: tmrpcm.play("8.wav");
            break;
    case 9: tmrpcm.play("9.wav");
            break;
    case 10: tmrpcm.play("10.wav");
            break;
    case 11: tmrpcm.play("11.wav");
            break;
    case 12: tmrpcm.play("12.wav");
            break;
    case 13: tmrpcm.play("13.wav");
            break;
    case 14: tmrpcm.play("14.wav");
            break;
    case 15: tmrpcm.play("15.wav");
            break;
    case 16: tmrpcm.play("16.wav");
            break;
    case 17: tmrpcm.play("17.wav");
            break;
    case 18: tmrpcm.play("18.wav");
            break;
    case 19: tmrpcm.play("19.wav");
            break;
  
  }
  }
  else
  {
    switch(n)
  {
    case 1: tmrpcm.play("10.wav");
            break;
    case 2: tmrpcm.play("20.wav");
            break;
    case 3: tmrpcm.play("30.wav");
            break;
    case 4: tmrpcm.play("40.wav");
            break;
    case 5: tmrpcm.play("50.wav");
            break;
    case 6: tmrpcm.play("60.wav");
            break;
    case 7: tmrpcm.play("70.wav");
            break;
    case 8: tmrpcm.play("80.wav");
            break;
    case 9: tmrpcm.play("90.wav");
            break;
  }
  sid(m);
  }
  
}

