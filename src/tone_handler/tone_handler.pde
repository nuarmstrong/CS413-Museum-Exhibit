import processing.serial.*;
import ddf.minim.*;
 
Serial myPort;
Minim minim;
AudioPlayer player;
byte arbitraryCode = 1;
 
void setup()
{
  // In the next line, you'll need to change this based on your USB port name
  myPort = new Serial(this, "/dev/cu.usbmodem2101", 9600);
  minim = new Minim(this);
 
  // Put in the name of your sound file below, and make sure it is in the same directory
  player = minim.loadFile("/Users/ian/Documents/PlatformIO/Projects/museumExhibit/lib/sounds/Note-A.mp3");
}
 
void draw() {
  while (myPort.available() > 0) {
    int inByte = myPort.read();
    if (inByte == arbitraryCode) {
      player.rewind();
      player.play();
    }
  }
}
