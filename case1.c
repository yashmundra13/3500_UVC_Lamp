//Case when UVC light is used.

//Library to access the current time.
#include <TimeLib.h>
#include <math.h>


int inPin = 0;
int outPin = 10;

double distance(double volt){
    double dist;
    dist = pow(volt,-1.16);
    return dist;
}

void loop() {             
  int val;                
  double temp;            
  val=analogRead(inPin); 
  dist= distance(val);
  time_t t = now();
  int h = hour(t);
  if (dist >= 75 & (h >= 22 || h <= 6)){
      digitalWrite(outPin,HIGH);
  }else{
      digitalWrite(outPin,LOW);
  }
  delay(1000);
}