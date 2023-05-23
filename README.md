# Arduino LED Array Controller

This Arduino application is designed to control a 16x16 LED matrix (WS2812B) using an Arduino MEGA2560. It features 6 physical buttons that, when pressed, create a "line" of light that moves in a random direction across the LED array. Each button is associated with a specific color from the rainbow (red, orange, yellow, green, blue, purple).

## Repository Structure
<pre>
.
├── test
&#124;   └── README
├── src
&#124;   └── main.cpp
├── platformio.ini
├── lib
&#124;   └── README
└── include
    ├── README
    ├── Note.h
    ├── Location.h
    └── Bitset.h
</pre>

## Dependencies

This project uses the following dependencies:
* **FastLED** - A powerful and efficient library for controlling a broad range of addressable RGB LEDs, by Daniel Garcia.
* **Arduino.h** - The standard Arduino library.

## Code Structure and Description

### Main.cpp

`main.cpp` is the main program file where the setup and main loop function is present. The file includes the header files `Arduino.h`, `FastLED.h`, `Location.h`, and `Note.h`. It also defines the data pin for LED control and the maximum brightness of the LEDs. The program creates six `Note` objects, one for each button color. It checks if any button has been pressed in the main loop and if so, triggers the respective `Note` object's `draw_line` function.

### Note.h

`Note.h` is a header file that defines the `Note` class. A `Note` object represents a button and the actions to be performed when it's pressed. 

The `Note` class contains the following member variables:
* `Location* loc`: A pointer to a `Location` object that stores the current location of the light "line".
* `uint8_t pin`: The pin number of the associated button.
* `BitSet written`: A BitSet object to keep track of which LEDs have been lit.
* `CRGB color`: The color associated with the button.
* `CRGB (*leds)[256]`: A pointer to an array of CRGB objects, representing the LED matrix.

And the following member functions:
* `Note()`: The constructor which initializes the `Note` object.
* `~Note()`: The destructor of the `Note` object.
* `draw_px()`: Lights up the current pixel and updates the FastLED display.
* `pushed()`: Checks if the button associated with the `Note` object has been pressed.
* `draw_line()`: Draws a "line" of light by lighting up pixels in a random direction until it reaches an unlit pixel.

### BitSet.h

`BitSet.h` defines the BitSet class which can store and operate on a set of 256 boolean values using four 64-bit integers.

### Location.h

`Location.h` defines the `Location` class, which stores the current position (x, y) of the light "line" in the LED matrix and provides methods to update and retrieve the location.

## Installation and Usage

1. Clone this repository.
2. Open the project in VSCode with the PlatformIO extension installed.
3. Connect the Arduino MEGA2560 to your computer via USB.
4. Compile and upload the code to the Arduino board.
5. Press the physical buttons connected to your Arduino to draw lines of different colors on the LED array.

## Contributing
Pull requests and issues are welcome. Please feel free to contribute by submitting them.

## License
This project is released under the MIT License.
