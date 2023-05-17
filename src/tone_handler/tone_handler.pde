import themidibus.*; //Import the library
import processing.serial.*;
int channel = 0;
int pitch1 = 64;
int velocity1 = 0;
String strval = "";

// The serial port:
Serial myPort;
// pitches go from 48 - 72
// List all the available serial ports:

MidiBus myBus; // The MidiBus
// Define constants for the notes
final int NOTE_C3 = 48;
final int NOTE_D3b = 49;
final int NOTE_D3 = 50;
final int NOTE_E3b = 51;
final int NOTE_E3 = 52;
final int NOTE_F3 = 53;
final int NOTE_G3b = 54;
final int NOTE_G3 = 55;
final int NOTE_A3b = 56;
final int NOTE_A3 = 57;
final int NOTE_B3b = 58;
final int NOTE_B3 = 59;
final int NOTE_C4 = 60;
final int NOTE_D4b = 61;
final int NOTE_D4 = 62;
final int NOTE_E4b = 63;
final int NOTE_E4 = 64;
final int NOTE_F4 = 65;
final int NOTE_G4b = 66;
final int NOTE_G4 = 67;
final int NOTE_A4b = 68;
final int NOTE_A4 = 69;
final int NOTE_B4b = 70;
final int NOTE_B4 = 71;
final int NOTE_C5 = 72;



void setup() {
  println("Available Serial Ports:");
  println("-------------------------");
  printArray(Serial.list());
// Open the port you are using at the rate you want:
  myPort = new Serial(this, Serial.list()[3], 9600);
  
// Send a capital "A" out the serial port
  myPort.write(65);
  size(400, 400);
  background(0);

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

  myBus.sendNoteOn(channel, pitch1, velocity1);
  delay(200);
  myBus.sendNoteOff(channel, pitch1, velocity1); // Send a Midi nodeOff

  int number = 0;
  int value = 90;

  myBus.sendControllerChange(channel, number, value); // Send a controllerChange
  delay(2000);
  
}

void writeByte(int pitch) {
  byte highByte = (byte) ((pitch >> 8) & 0xFF);
  byte lowByte = (byte) (pitch & 0xFF);
  myPort.write(highByte);
  myPort.write(lowByte);
}

void noteOn(int channel, int pitch, int velocity) {
  // Receive a noteOn
  println();
  println("Note On:");
  println("--------");
  println("Channel:"+channel);
  println("Pitch:"+pitch);
  println("Velocity:"+velocity);
  if (velocity > 0 ) {
    switch (pitch) {
      case NOTE_C3:
        //myPort.write('c');
        writeByte(pitch);
        break;
      case NOTE_D3b:
        myPort.write('a');
        break;
      case NOTE_D3:
        myPort.write('b');
        break;
      case NOTE_E3b:
        myPort.write('d');
        break;
      case NOTE_E3:
        myPort.write('e');
        break;
      case NOTE_F3:
        myPort.write('f');
        break;
      case NOTE_G3b:
        myPort.write('g');
        break;
      case NOTE_G3:
        myPort.write('h');
        break;
      case NOTE_A3b:
        myPort.write('i');
        break;
      case NOTE_A3:
        myPort.write('j');
        break;
       case NOTE_B3b:
        myPort.write('k');
        break;
      case NOTE_B3:
        myPort.write('l');
        break;
      case NOTE_C4:
        myPort.write('m');
        break;
      case NOTE_D4b:
        myPort.write('n');
        break;
      case NOTE_D4:
        myPort.write('o');
        break;
      case NOTE_E4b:
        myPort.write('p');
        break;
      case NOTE_E4:
        myPort.write('q');
        break;
      case NOTE_F4:
        myPort.write('r');
        break;
      case NOTE_G4b:
        myPort.write('s');
        break;
      case NOTE_G4:
        myPort.write('t');
        break;
      case NOTE_A4b:
        myPort.write('u');
        break;
      case NOTE_A4:
        myPort.write('v');
        break;
      case NOTE_B4b:
        myPort.write('w');
        break;
      case NOTE_B4:
        myPort.write('x');
        break;
      default:
        myPort.write('y');
        break;
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
  switch (pitch)  { 
    case NOTE_C3 : 
      //myPort.write('3');
      writeByte(-pitch);
      break;
    case NOTE_D3b: 
      myPort.write('1');
      break;
    case NOTE_D3: 
      myPort.write('2');
      break;
    case NOTE_E3b: 
      myPort.write('4');
      break;
    case NOTE_E3: 
      myPort.write('5');
      break;
    case NOTE_F3: 
      myPort.write('6');
      break;
    case NOTE_G3b:
      myPort.write('7');
      break;
    case NOTE_G3: 
      myPort.write('8');
      break;
    case NOTE_A3b: 
      myPort.write('A');
      break;
    case NOTE_A3:
      myPort.write('9');
      break;
    case NOTE_B3b:
      myPort.write('B');
      break;
    case NOTE_B3:
      myPort.write('C');
      break;
    case NOTE_C4:
      myPort.write('D');
      break;
    case NOTE_D4b: 
      myPort.write('E');
      break;
    case NOTE_D4:
      myPort.write('F');
      break;
    case NOTE_E4b:
      myPort.write('G');
      break;
    case NOTE_E4:
      myPort.write('H');
      break;
    case NOTE_F4:
      myPort.write('I');
      break;
    case NOTE_G4b:
      myPort.write('J');
      break;
    case NOTE_G4:
      myPort.write('K');
      break;
    case NOTE_A4b:
      myPort.write('L');
      break;
    case  NOTE_A4: 
      myPort.write('M');
      break;
    case NOTE_B4b: 
      myPort.write('N');
      break;
    case NOTE_B4: 
      myPort.write('O');
      break;
    default:
     myPort.write('P');
     break;
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
