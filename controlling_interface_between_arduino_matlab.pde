import processing.serial.*;
PrintWriter output;
PrintWriter error;
int lf = 10;
int i=0;
String myString = null;
Serial myPort;
float val;
String[] lines;
int len;

void setup() {
  String portName = Serial.list()[0];
  myPort = new Serial(this, portName, 9600);
  size(800,600);
  background(0);
  error = createWriter("error.txt");
   
}

void draw() { 
   while(myPort.available() > 0) {
     lines = null;
     //lines = loadStrings("feedback.txt");
  myString = myPort.readStringUntil(lf);
  if(myString != null) {
    print(myString);
  output = createWriter("test.txt");
  output.println(myString);
  output.flush();
  output.close();
    //val = float(myString);
    //println(val);
     }
   }
 //delay(87);

  lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
  //delay(36);
  //lines = loadStrings("feedback.txt");
//  error.println(lines[0]);
  len = lines.length;
  while(len == 0)
  {
    lines = loadStrings("feedback.txt");
    len = lines.length;
  } 
  println(len);
  if(len > 0)
  {
   
    if(!lines[0].equals(null) && lines[0].equals("GO"))
  {
 //   lines = loadStrings("feedback.txt");
        println("0");
        myPort.write('0');
        lines = null;
   //     myPort.clear();
  }
  else if(!lines[0].equals(null) && lines[0].equals("WAIT"))
  {
    println("1");
    myPort.write('1');
    lines = null;
  }
}
if(len == 0)
{
  error.println("error");
  error.println(len);
  println("2");
  myPort.write('2');
}

}
