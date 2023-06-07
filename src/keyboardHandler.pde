import themidibus.*; //Import the library
import processing.serial.*;
int channel = 0;
int pitch1 = 64;
int velocity1 = 0;
String strval = "";
Boolean[] notesArray = new Boolean[25]; 
// The serial port:

Serial myPort;
//Serial myPort2;
//Serial myPort3;
//Serial myPort4;
// pitches go from 48 - 72
// List all the available serial ports:

MidiBus myBus; // The MidiBus

void setup() {

  int vd = 'a';
  char vg = 65;
  println(vd);
  println(vg);
  println("S");
  println("A");
  printArray(Serial.list());
  println("B");
// Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[2], 9600);
  //myPort2 = new Serial(this, Serial.list()[2], 9600);
  //myPort3 = new Serial(this, Serial.list()[3], 9600);
  //myPort4 = new Serial(this, Serial.list()[4], 9600);
  
// Send a capital "A" out the serial port
//  myPort.write(65);
  size(1400, 800);
  //PImage img;
  //img = loadImage("Gradient.jpg");
  background(0);
  for (int i = 0; i < 25; i++ ) {
     notesArray[i] = false; 
  }
  MidiBus.list(); // List all available Midi devices on STDOUT. This will show each device's index and name.
  
  // Either you can
  //                   Parent In Out
  //                     |    |  |
  //myBus = new MidiBus(this, 0, 1); // Create a new MidiBus using the device index to select the Midi input and output devices respectively.
  myBus = new MidiBus(this, 1, 1);
  // or you can ...
  //                   Parent         In                   Out
  //                     |            |                     |
  //myBus = new MidiBus(this, "IncomingDeviceName", "OutgoingDeviceName"); // Create a new MidiBus using the device names to select the Midi input and output devices respectively.

  // or for testing you could ...
  //                 Parent  In        Out
  //                   |     |          |
  //myBus = new MidiBus(this, -1, "Java Sound Synthesizer"); // Create a new MidiBus with no input device and the default Java Sound Synthesizer as the output device.
}

void draw() {

  
  //int channel = 0;
  //int pitch = 64;
  //int velocity = 0;
  background(152,190,100);
  myBus.sendNoteOn(channel, pitch1, velocity1);
   //println(pitch1);
   //println(velocity1);
  // Send a Midi noteOn
  //if (pitch1 == 48 && velocity1 > 0) {
  //   myPort.write(0);
  //}
  //if (pitch1 == 49 && velocity1 > 0) {
  //   myPort.write(1);
  //}
  delay(50);
  // Drawing to Canvas
  //
  myBus.sendNoteOff(channel, pitch1, velocity1); // Send a Midi nodeOff

  int ctr = 0;
  for (int i = 0; i < 25; i++) {
     if (notesArray[i] == true) {
       ctr += 1;
     }
  }

  if (ctr == 3) {
     if (notesArray[0] && notesArray[4] && notesArray[7]) {
        size(1400, 800);
        textSize(200);
        String s = "C Major";
        fill(0, 0, 150);
        textAlign(CENTER, CENTER);
        text(s, 0, 0, 1400, 800); 
        
     } else if (notesArray[1] && notesArray[5] && notesArray[8]) {
        size(1400, 800);
        textSize(200);
        String s = "C Sharp Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[2] && notesArray[6] && notesArray[9]) {
        size(1400, 800);
        textSize(200);
        String s = "D Sharp Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[3] && notesArray[7] && notesArray[10]) {
        size(1400, 800);
        textSize(200);
        String s = "E Flat Major";
         fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[4] && notesArray[8] && notesArray[11]) {
        size(1400, 800);
        textSize(200);
        String s = "E Flat Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[5] && notesArray[9] && notesArray[12]) {
        size(1400, 800);
        textSize(200);
        String s = "F Major";
        fill(0, 0, 150);
        text(s,0, 0, 1400, 800); 
     } else if (notesArray[6] && notesArray[10] && notesArray[13]) {
        size(1400, 800);
        textSize(200);
        String s = "F Sharp Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[7] && notesArray[11] && notesArray[14]) {
        size(1400, 800);
        textSize(200);
        String s = "G Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[8] && notesArray[12] && notesArray[15]) {
        size(1400, 800);
        textSize(200);
        String s = "A Flat Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[9] && notesArray[13] && notesArray[16]) {
        size(1400, 800);
        textSize(200);
        String s = "A Major";
        fill(0, 0, 150);
        text(s, 0, 0,1400, 800); 
     } else if (notesArray[10] && notesArray[14] && notesArray[17]) {
        size(1400, 800);
        textSize(200);
        String s = "B Flat Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[11] && notesArray[15] && notesArray[18]) {
        size(1400, 800);
        textSize(200);
        String s = "B Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[12] && notesArray[16] && notesArray[19]) {
        size(1400, 800);
        textSize(200);
        String s = "C Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[13] && notesArray[17] && notesArray[20]) {
        size(1400, 800);
        textSize(200);
        String s = "C Sharp Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[14] && notesArray[18] && notesArray[21]) {
        size(1400, 800);
        textSize(200);
        String s = "D Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[15] && notesArray[19] && notesArray[22]) {
        size(1400, 800);
        textSize(200);
        String s = "E Flat Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[16] && notesArray[20] && notesArray[23]) {
         size(1400, 800);
        textSize(200);
        String s = "E Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[17] && notesArray[21] && notesArray[24]) {
        size(1400, 800);
        textSize(200);
        String s = "F Major";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[0] && notesArray[3] && notesArray[7]) {
        size(1400, 800);
        textSize(200);
        String s = "C Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[1] && notesArray[4] && notesArray[8]) {
        size(1400, 800);
        textSize(200);
        String s = "C Sharp Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[2] && notesArray[5] && notesArray[9]) {
        size(1400, 800);
        textSize(200);
        String s = "D Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[3] && notesArray[6] && notesArray[10]) {
        size(1400, 800);
        textSize(200);
        String s = "E Flat Minor";
        fill(0, 0, 150);
        text(s,0, 0, 1400, 800); 
     } else if (notesArray[4] && notesArray[7] && notesArray[11]) {
        size(1400, 800);
        textSize(200);
        String s = "E Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[5] && notesArray[8] && notesArray[12]) {
        size(1400, 800);
        textSize(200);
        String s = "F Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[6] && notesArray[9] && notesArray[13]) {
        size(1400, 800);
        textSize(200);
        String s = "F Sharp Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[7] && notesArray[10] && notesArray[14]) {
        size(1400, 800);
        textSize(200);
        String s = "G Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[8] && notesArray[11] && notesArray[15]) {
        size(1400, 800);
        textSize(200);
        String s = "A Flat Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[9] && notesArray[12] && notesArray[16]) {
        size(1400, 800);
        textSize(200);
        String s = "A Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[10] && notesArray[13] && notesArray[17]) {
        size(1400, 800);
        textSize(200);
        String s = "B Flat Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[11] && notesArray[14] && notesArray[18]) {
        size(1400, 800);
        textSize(200);
        String s = "B Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[12] && notesArray[15] && notesArray[19]) {
        size(1400, 800);
        textSize(200);
        String s = "C Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[13] && notesArray[16] && notesArray[20]) {
        size(1400, 800);
        textSize(200);
        String s = "C Sharp Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[14] && notesArray[17] && notesArray[21]) {
        size(1400, 800);
        textSize(200);
        String s = "D Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[15] && notesArray[18] && notesArray[22]) {
        size(1400, 800);
        textSize(200);
        String s = "E Flat Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[16] && notesArray[19] && notesArray[23]) {
        size(1400, 800);
        textSize(200);
        String s = "E Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     } else if (notesArray[17] && notesArray[20] && notesArray[24]) {
        size(1400, 800);
        textSize(200);
        String s = "F Minor";
        fill(0, 0, 150);
        text(s, 0, 0, 1400, 800); 
     }
       
  }
  //} else {
  //  clear();
  //}
  int number = 0;
  int value = 90;

  myBus.sendControllerChange(channel, number, value); // Send a controllerChange
  delay(500);
  //String test = myPort.readString();
  
}

void noteOn(int channel, int pitch, int velocity) {
  // Receive a noteOn
  println();
  println("Note On:");
  println("--------");
  println("Channel:"+channel);
  println("Pitch:"+pitch);
  println("Velocity:"+velocity);
  //velocity1 = velocity;
  //pitch1 = pitch;
  //strval = "";
  // Function for conversion here
  /*
  if (velocity > 0) {
    char val = 49 + pitch;
    
  }
  */
  //
  if (velocity > 0) {
    if (pitch == 43) {
      myPort.write('z');
      //myPort2.write('z');
      //myPort3.write('z');
      //myPort4.write('z');
    } else {
      char val = char(49 + pitch);
      myPort.write(val);
      //myPort2.write(val);
      //myPort3.write(val);
      //myPort4.write(val);
      //  if (velocity > 0) {
        if (pitch >= 48) {
        notesArray[pitch - 48] = true;
        }
//  }
    }
  }
}

void noteOff(int channel, int pitch, int velocity) {
  // Receive a noteOff
  println();
  println("Note Off:");
  println("--------");
  println("Channel:"+channel);
  println("Pitch:"+pitch);
  println("Velocity:"+velocity);
  //myPort.clear();
   if (pitch == 43) {
      myPort.write('Z');
      //myPort2.write('Z');
      //myPort3.write('Z');
      //myPort4.write('Z');
   } else {
    if (pitch >= 48) {
       notesArray[pitch - 48] = false;
    }
    char val = char(17 + pitch);
    myPort.write(val);
    //myPort2.write(val);
    //myPort3.write(val);
    //myPort4.write(val);
    }
}

void controllerChange(int channel, int number, int value) {
  // Receive a controllerChange
  println();
  println("Controller Change:");
  println("--------");
  println("Channel:"+channel);
  println("Number:"+number);
  println("Value:"+value);
}

void delay(int time) {
  int current = millis();
  while (millis () < current+time) Thread.yield();
}