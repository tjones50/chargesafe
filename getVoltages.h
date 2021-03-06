#include "Arduino.h"

double getVoltages(double * arr){
  unsigned long c1 =0;
  unsigned long c2 = 0;
  unsigned long c3 = 0;
  unsigned long c4 = 0;
  double v1, v2, v3, v4;
  double vpd = .0049; //volts per divison
  int numAvgs = 20;
  
  for(int i=0; i<numAvgs; i++){
    Serial.println(c1);
    c1 += analogRead(A0);
    c2 += analogRead(A1);
    c3 += analogRead(A2);
    c4 += analogRead(A3);
  }
  
  c1 /= numAvgs;
  c2 /= numAvgs;
  c3 /= numAvgs;
  c4 /= numAvgs;
  
  v1 = (c1 - 3)*vpd;
  v2 = 2*(c2-7)*vpd - v1;
  v3 = 3*(c3-4)*vpd - v2 - v1;
  v4 = 4*(c4+10)*vpd - v3 - v2 - v1;

  arr[0] = v1;
  arr[1] = v2;
  arr[2] = v3;
  arr[3] = v4;

//  Serial.print(v1);
//  Serial.print("   -    ");
//  Serial.print(v2);
//  Serial.print("   -    ");
//  Serial.print(v3);
//  Serial.print("   -    ");
//  Serial.println(v4);

  return v1+v3+v3+v4;
      
}

