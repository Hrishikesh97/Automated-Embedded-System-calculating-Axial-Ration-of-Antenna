//char buffer[3];
int w=0;
int f=0;
float a=0;
float d=0;
int r=1;
char inChar;
String inputString = "";// a string to hold incoming data
String inputString1 = "";
boolean stringComplete = false;  // whether the string is complete
const int PUL = 5;              //Initializing 5th digital pin as ENABLE
const int DIR = 6;              //Initializing 6th digital pin as DIRECTION
const int ENA = 7;//Initializing 7th digital pin as PULSE
const int Transpin = 0;
void setup() {
  // initialize serial:
  Serial.begin(9600);
  // reserve 1000 bytes for the inputString:
  inputString.reserve(1000);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(ENA,HIGH);
  Serial.println("Enter the angle of rotation:");
}


void serialEvent() {
   
    // clear the string:
   // print the string when a newline arrives: 
   if (stringComplete) {
    //Serial.println(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  } 
    
}

   
void loop () {
  if(Serial.available()) {
    // get the new byte:
    while(w != 3)
    {
    inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if(inChar == '0')
    {
      stringComplete = true;
      a = (0*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   
    
    }
    else if(inChar == '1')
    {
      stringComplete = true;
      a = (1*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '2')
    {
      stringComplete = true;
      a = (2*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '3')
    {
      stringComplete = true;
      a = (3*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '4')
    {
      stringComplete = true;
      a = (4*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '5')
    {
      stringComplete = true;
      a = (5*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '6')
    {
      stringComplete = true;
      a = (6*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '7')
    {
      stringComplete = true;
      a = (7*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '8')
    {
      stringComplete = true;
      a = (8*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      String inputString = "";
      boolean stringComplete = false;   

    }
    else if(inChar == '9')
    {
      stringComplete = true;
      a = (9*pow(10,(2-f)))+a;
      f = f+1;
      w++;
      //String inputString = "";
      boolean stringComplete = false;   

    }
    }     
         d=a*(0.5555555555555555555555);   
         w=0;
         Serial.println("Enter the direction of rotation:");
         while(w != 1)
         {
   
    inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;
     if (inChar == 'C') {
      w++;
      stringComplete = true;
      digitalWrite(DIR,HIGH);     
      String inputString = "";
      boolean stringComplete = false;                    
                       }
     else if (inChar == 'A') {
      w++;
      stringComplete = true;
      digitalWrite(DIR,LOW);     
      String inputString = "";
      boolean stringComplete = false;                    
                       }    
         }
         w=0;
         Serial.println("Enter B to begin:");
         while(w==0)
         {                     
    inChar = (char)Serial.read();
    // add it to the inputString:
    inputString += inChar;                                              
    if( inChar == 'B'){  
      stringComplete = true;
    //   Serial.println(a); 
    //   Serial.println(d);
      for (int i = 1; i <= d ; i++) {
          digitalWrite(PUL, HIGH); 
          delay(200);
          digitalWrite(PUL, LOW);
          delay(0.2);
          float q = (i * 0.9);
          Serial.println(q);
               
       } 
      for (int j = 1; j <= d ; j++) {
          digitalWrite(PUL, HIGH); 
          delay(200);
          digitalWrite(PUL, LOW);
          delay(0.2);
          float v = ((d+j) * 0.9);
          Serial.println(v);
          //delay(1000);
          //Serial.write((byte)v);
          //digitalWrite(PUL, HIGH); 
          //delay(100);
          
          //digitalWrite(PUL, LOW);     
       }
    }
      a=0;
      f=0;
  }
  goto X;
  }
        X: 
        for (int i = 1; i <= d ; i++) {
          digitalWrite(PUL, HIGH); 
          delay(200);
          digitalWrite(PUL, LOW);
          delay(0.2);
          float q = (i * 0.9);
          Serial.println(q);
               
       } 

}    

