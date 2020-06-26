#include <Servo.h>

Servo base;  // create servo object to control a servo
Servo arm1;
Servo arm2;
Servo arm3;
Servo arm4;
Servo palm;
int i=0,j=0;
int anglep = 120;//initial angle of palm servo(servo used as fingers)
int anglet = 150;//fifth servo(servo before palm)
int anglew = 180;//fourth servo
int anglee = 30;//third servo
int anglec = 40;//initial angle of servo after base(second servo)
int angleb = 89;//initial angle of base servo(servo on the bottom)
int temp1=0;
int temp2=0;
int flag=0;
int t1=0;
int p1=0;
int w1=0;
int b1=0;
int e1=0;
int cs1=0;
void setup() {
  Serial.begin(9600);
  arm1.attach(3);
  arm2.attach(5);
  arm3.attach(10);
  arm4.attach(6);
  palm.attach(11);
  base.attach(9);
  base.write(angleb);
  arm1.write(anglec);
  arm2.write(anglee);
  arm3.write(anglet);
  arm4.write(anglew);  
  palm.write(anglep);
}

void loop() {
Outerloop:
    if(Serial.available()) {
    char c1 = Serial.read();
    if(c1=='P' || flag==1)
    {
    if(c1=='P')
    {
    flag=1;
    p1=anglep;
    anglep=0;
    goto Outerloop; 
    }
    if ((c1 >= '0') && (c1 <= '9')) {
        anglep *= 10;
        anglep += (c1 - '0');
    }    
    else if (c1 == '\n') {
     Serial.println('P'+String(anglep)); 
     if(p1<anglep)
     {
     for(int i=p1;i<=anglep;i++)
     {
     palm.write(i);
     delay(15);
     }
     }
     else if(p1>anglep)
     {
      for(int j=p1;j>anglep;j--)
      {
      palm.write(j);
      delay(15);
      }
     }
     else if(p1==anglep)
     {
      palm.write(anglep);
     }
     flag=0;
     goto Outerloop; 
      }
    }
    else if(c1=='T' || flag==2)
    {
    if(c1=='T')
    {
    flag=2;
    t1=anglet;
    anglet=0;
    goto Outerloop;  
    }
    if ((c1 >= '0') && (c1 <= '9')) {
        anglet *= 10;
        anglet += (c1 - '0');
    }    
    else if (c1 == '\n') { 
    Serial.println('T'+String(anglet));
     if(t1<anglet)
     {
     for(int i=t1;i<=anglet;i++)
     {
     arm3.write(i);
     delay(15);
     }
     }
     else if(t1>anglet)
     {
      for(int j=t1;j>anglet;j--)
      {
      arm3.write(j);
      delay(15);
      }
     }
     else if(t1==anglet)
     {
      arm3.write(anglet);
     }
     flag=0;
     goto Outerloop;
      }
    }
    else if(c1=='B' || flag==3)
    {
    if(c1=='B')
    {
    flag=3;
    b1=angleb;
    angleb=0;
    goto Outerloop; 
    }
    if ((c1 >= '0') && (c1 <= '9')) {
        angleb *= 10;
        angleb += (c1 - '0');
    }    
    else if (c1 == '\n') {
     Serial.println('B'+String(angleb)); 
     if(b1<angleb)
     {
     for(int i=b1;i<=angleb;i++)
     {
     base.write(i);
     delay(15);
     }
     }
     else if(b1>angleb)
     {
      for(int j=b1;j>angleb;j--)
      {
      base.write(j);
      delay(15);
      }
     }
     else if(b1==angleb)
     {
      base.write(angleb);
     }
     flag=0;
     goto Outerloop; 
      }
    }
    else if(c1=='C' || flag==4)
    {
    if(c1=='C')
    {
    flag=4;
    cs1=anglec;
    anglec=0;
    goto Outerloop;  
    }
    if ((c1 >= '0') && (c1 <= '9')) {
        anglec *= 10;
        anglec += (c1 - '0');
    }    
    else if (c1 == '\n') { 
    Serial.println('C'+String(anglec));
     if(cs1<anglec)
     {
     for(int i=cs1;i<=anglec;i++)
     {
     arm1.write(i);
     delay(15);
     }
     }
     else if(cs1>anglec)
     {
      for(int j=cs1;j>anglec;j--)
      {
      arm1.write(j);
      delay(15);
      }
     }
     else if(cs1==anglec)
     {
      arm1.write(anglec);
     }
     flag=0;
     goto Outerloop;
      }
    }
    else if(c1=='E' || flag==5)
    {
    if(c1=='E')
    {
    flag=5;
    e1=anglee;
    anglee=0;
    goto Outerloop; 
    }
    if ((c1 >= '0') && (c1 <= '9')) {
        anglee *= 10;
        anglee += (c1 - '0');
    }    
    else if (c1 == '\n') {
     Serial.println('E'+String(anglee)); 
     if(e1<anglee)
     {
     for(int i=e1;i<=anglee;i++)
     {
     arm2.write(i);
     delay(15);
     }
     }
     else if(e1>anglee)
     {
      for(int j=e1;j>anglee;j--)
      {
      arm2.write(j);
      delay(15);
      }
     }
     else if(e1==anglee)
     {
      arm2.write(anglee);
     }
     flag=0;
     goto Outerloop; 
      }
    }
    else if(c1=='W' || flag==6)
    {
    if(c1=='W')
    {
    flag=6;
    w1=anglew;
    anglew=0;
    goto Outerloop;  
    }
    if ((c1 >= '0') && (c1 <= '9')) {
        anglew *= 10;
        anglew += (c1 - '0');
    }    
    else if (c1 == '\n') { 
    Serial.println('W'+String(anglew));
     if(w1<anglew)
     {
     for(int i=w1;i<=anglew;i++)
     {
     arm4.write(i);
     delay(15);
     }
     }
     else if(w1>anglew)
     {
      for(int j=w1;j>anglew;j--)
      {
      arm4.write(j);
      delay(15);
      }
     }
     else if(w1==anglew)
     {
      arm4.write(anglew);
     }
     flag=0;
     goto Outerloop;
      }
    }
    }
}
    
