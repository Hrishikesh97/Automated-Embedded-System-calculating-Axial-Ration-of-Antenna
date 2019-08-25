//char buffer[3];
int d=0;
int i=0;
float deg=0;
int nextChar;
const int PUL = 5;              //Initializing 5th digital pin as PULSE
const int DIR = 6;              //Initializing 6th digital pin as DIRECTION
const int ENA = 7;//Initializing 7th digital pin as ENABLE
void setup() {
  // initialize serial:
  Serial.begin(9600);
  pinMode(5,OUTPUT);
  pinMode(6,OUTPUT);
  pinMode(7,OUTPUT);
  pinMode(13,OUTPUT);
  digitalWrite(ENA,HIGH);
  pinMode(9,INPUT);
  deg=i*0.9;
  Serial.println(deg);
  i=i+1;
 // pinMode(10,INPUT);
}

void loop() {
   
      d = digitalRead(9);
      //k = digitalRead(10); 
      if (digitalRead(9) == HIGH) 
      {
      digitalWrite(DIR,HIGH); //clockwise     
      }
      if (digitalRead(9) == LOW ) 
     {
      digitalWrite(DIR,LOW);  //counter-clockwise   
     }                                                                       
     
    while(Serial.available()) 
    {
      nextChar = Serial.read();
          if(nextChar == '0')
             {
              go:
          digitalWrite(13,HIGH);
        //  delay(2500);
          digitalWrite(PUL, HIGH); 
          delay(500);
          digitalWrite(PUL, LOW);
          delay(500);
          deg = (i * 0.9);
          Serial.println(deg);
          i = i+1;  
          while(1){
          nextChar = Serial.read();
          if(nextChar == '1')
            { 
            goto wait;
            }
          }
             }
   while(nextChar == '1')
        {
          wait:
      nextChar = Serial.read();
          digitalWrite(13,LOW);
          if(nextChar == '0')
          { goto go; }
          //delay(5000);
          //digitalWrite(PUL, HIGH); 
          //delay(50);
          //digitalWrite(PUL, LOW);
          //delay(50);
          //float deg = (i * 0.9);
          //Serial.println(deg);
          //i = i+1;  
        }
    
    }
}

