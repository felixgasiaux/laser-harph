/* Buttons to USB MIDI Example

   You must select MIDI from the "Tools > USB Type" menu

   To view the raw MIDI data on Linux: aseqdump -p "Teensy MIDI"

   This example code is in the public domain.
*/

#include <Bounce.h>

// the MIDI channel number to send messages
const int channel = 1;

// Create Bounce objects for each button.  The Bounce object
// automatically deals with contact chatter or "bounce", and
// it makes detecting changes very simple.
Bounce button0 = Bounce(0, 10);
Bounce button1 = Bounce(1, 10);  // 5 = 5 ms debounce time
Bounce button2 = Bounce(2, 10);  // which is appropriate for good
Bounce button3 = Bounce(3, 10);  // quality mechanical pushbuttons
Bounce button4 = Bounce(4, 10);
Bounce button5 = Bounce(5, 10);  // if a button is too "sensitive"
Bounce button6 = Bounce(6, 10);  // to rapid touch, you can
Bounce button7 = Bounce(7, 10);  // increase this time.
Bounce button8 = Bounce(8, 10);
Bounce button9 = Bounce(9, 10);
Bounce button10 = Bounce(10, 10);
Bounce button11 = Bounce(11, 10);
Bounce button12 = Bounce(12, 10);
// 13 is the LED
Bounce button14 = Bounce(14, 10);


void setup() {
  // Configure the pins for INPUT mode with pullup resistors.

  //For our project, the laser harph, use INPUT and connect the
  // different pins on one hand to one of the inputs, from 0-13 and the other 
  // End  TO GROUND
  // Using this the diode should work as a button... I want to make clear SHOULD
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);  // Teensy++ 2.0 LED, may need 1k resistor pullup
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP); 
  pinMode(12, INPUT_PULLUP);
  pinMode(13, OUTPUT);       // 13 is the LED
  pinMode(14, INPUT_PULLUP); 
  // flash LED 3 times to show that it has booted
  digitalWrite(13, HIGH);   // LED on
  delay(500);             
  digitalWrite(13, LOW);   // LED off
  delay(500);             
  digitalWrite(13, HIGH);   // LED on
  delay(500);             
  digitalWrite(13, LOW);   // LED off
  delay(500);             
  digitalWrite(13, HIGH);   // LED on
  delay(500);             
  digitalWrite(13, LOW);   // LED off
}

void loop() {
  // Update all the buttons.  There should not be any long
  // delays in loop(), so this runs repetitively at a rate
  // faster than the buttons could be pressed and released.
  button0.update();
  button1.update();
  button2.update();
  button3.update();
  button4.update();
  button5.update();
  button6.update();
  button7.update();
  button8.update();
  button9.update();
  button10.update();
  button11.update();
  button12.update();
  // 13 is the LED
  button14.update();

  // Check each button for "rising" edge.
  // Send a MIDI Note On message when each button presses
  // Update the Joystick buttons only upon changes.
  // falling = high (not pressed - voltage from pullup resistor)
  //           to low (pressed - button connects pin to ground)
  if (button0.risingEdge()) {
    usbMIDI.sendNoteOn(48, 99, channel);  // 48 = C4
    digitalWrite(13, HIGH);   // LED on
  }
  if (button1.risingEdge()) {
    usbMIDI.sendNoteOn(50, 99, channel);  // 50 = D4
    digitalWrite(13, HIGH);   // LED on
  }
  if (button2.risingEdge()) {
    usbMIDI.sendNoteOn(52, 99, channel);  // 52 = E4
    digitalWrite(13, HIGH);   // LED on
  }
  if (button3.risingEdge()) {
    usbMIDI.sendNoteOn(53, 99, channel);  // 53 = F4
    digitalWrite(13, HIGH);   // LED on
  }
  if (button4.risingEdge()) {
    usbMIDI.sendNoteOn(55, 99, channel);  // 55 = G4
    digitalWrite(13, HIGH);   // LED on
  }
  if (button5.risingEdge()) {
    usbMIDI.sendNoteOn(57, 99, channel);  // 57 = A4
    digitalWrite(13, HIGH);   // LED on
  }
  if (button6.risingEdge()) {
    usbMIDI.sendNoteOn(59, 99, channel);  // 59 = B4
    digitalWrite(13, HIGH);   // LED on
  }
  if (button7.risingEdge()) {
    usbMIDI.sendNoteOn(60, 99, channel);  // 60 = C5
    digitalWrite(13, HIGH);   // LED on
  }
  if (button8.risingEdge()) {
    usbMIDI.sendNoteOn(62, 99, channel);  // 62 = D5
    digitalWrite(13, HIGH);   // LED on
  }
  if (button9.risingEdge()) {
    usbMIDI.sendNoteOn(64, 99, channel);  // 64 = E5
    digitalWrite(13, HIGH);   // LED on
  }
  if (button10.risingEdge()) {
    usbMIDI.sendNoteOn(65, 99, channel);  // 65 = F5
    digitalWrite(13, HIGH);   // LED on
  }
  if (button11.risingEdge()) {
    usbMIDI.sendNoteOn(67, 99, channel);  // 67 = G5
    digitalWrite(13, HIGH);   // LED on
  }
  if (button12.risingEdge()) {
    usbMIDI.sendNoteOn(69, 99, channel);  // 69 = A5
    digitalWrite(13, HIGH);   // LED on
  }
  // 13 is the LED
  if (button14.risingEdge()) {
    usbMIDI.sendNoteOn(71, 99, channel);  // 71 = B5
    digitalWrite(13, HIGH);   // LED on
  }

  // Check each button for "rising" edge
  // Send a MIDI Note Off message when each button releases
  // For many types of projects, you only care when the button
  // is pressed and the release isn't needed.
  // rising = low (pressed - button connects pin to ground)
  //          to high (not pressed - voltage from pullup resistor)
  if (button0.fallingEdge()) {
    usbMIDI.sendNoteOff(48, 99, channel);  // 48 = C4
    digitalWrite(13, LOW);   // LED on
  }
  if (button1.fallingEdge()) {
    usbMIDI.sendNoteOff(50, 99, channel);  // 50 = D4
    digitalWrite(13, LOW);   // LED on
  }
  if (button2.fallingEdge()) {
    usbMIDI.sendNoteOff(52, 99, channel);  // 52 = E4
    digitalWrite(13, LOW);   // LED on
  }
  if (button3.fallingEdge()) {
    usbMIDI.sendNoteOff(53, 99, channel);  // 53 = F4
    digitalWrite(13, LOW);   // LED on
  }
  if (button4.fallingEdge()) {
    usbMIDI.sendNoteOff(55, 99, channel);  // 55 = G4
    digitalWrite(13, LOW);   // LED on
  }
  if (button5.fallingEdge()) {
    usbMIDI.sendNoteOff(57, 99, channel);  // 57 = A4
    digitalWrite(13, LOW);   // LED on
  }
  if (button6.fallingEdge()) {
    usbMIDI.sendNoteOff(59, 99, channel);  // 59 = B4
    digitalWrite(13, LOW);   // LED on
  }
  if (button7.fallingEdge()) {
    usbMIDI.sendNoteOff(60, 99, channel);  // 60 = C5
    digitalWrite(13, LOW);   // LED on
  }
  if (button8.fallingEdge()) {
    usbMIDI.sendNoteOff(62, 99, channel);  // 62 = D5
    digitalWrite(13, LOW);   // LED on
  }
  if (button9.fallingEdge()) {
    usbMIDI.sendNoteOff(64, 99, channel);  // 64 = E5
    digitalWrite(13, LOW);   // LED on
  }
  if (button10.fallingEdge()) {
    usbMIDI.sendNoteOff(65, 99, channel);  // 65 = F5
    digitalWrite(13, LOW);   // LED on
  }
  if (button11.fallingEdge()) {
    usbMIDI.sendNoteOff(67, 99, channel);  // 67 = G5
    digitalWrite(13, LOW);   // LED on
  }
  if (button12.fallingEdge()) {
    usbMIDI.sendNoteOff(69, 99, channel);  // 69 = A5
    digitalWrite(13, LOW);   // LED on
  }
  // 13 is the LED
  if (button14.fallingEdge()) {
    usbMIDI.sendNoteOff(71, 99, channel);  // 71 = B5
    digitalWrite(13, LOW);   // LED on
  }

  // MIDI Controllers should discard incoming MIDI messages.
  // http://forum.pjrc.com/threads/24179-Teensy-3-Ableton-Analog-CC-causes-midi-crash
  while (usbMIDI.read()) {
    // ignore incoming messages
  }
}
