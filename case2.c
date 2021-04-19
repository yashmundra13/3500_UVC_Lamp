//Case when far UVC lights is used. 

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
  bool occ;            
  val=analogRead(inPin); 
  dist= distance(val);
  if (dist < 80){
      digitalWrite(outPin,LOW);
      occ = true;
  }else{
      if(occ){
        digitalWrite(outPin,HIGH);
        delay(480000);
        digitalWrite(outPin,LOW);
        occ = false;
      }
  }
  delay(1000)
}