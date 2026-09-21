

# Task 4.2D: Calling a Function from the Web

Remote light control for Linda's home. A carer clicks a room button on a web page, and the matching LED on an Arduino Nano 33 IoT turns ON or OFF.

## How it works

Web page (`toggleLight`) -> Firebase Realtime Database -> Arduino reads the value over Wi-Fi -> LED switches.

## Files

- `index.html`, `style.css`, `script.js`: web page with buttons for Living Room, Bathroom and Closet
- Arduino sketch: connects to Wi-Fi and Firebase, reads the three values and sets the LEDs

## Hardware

- Arduino Nano 33 IoT, breadboard, jumper wires
- 3 LEDs with resistors: Living Room on D4, Bathroom on D5, Closet on D6

## Setup

1. Create a Firebase Realtime Database with `livingroom`, `bathroom` and `closet` set to `true` or `false`.
2. Add your own Firebase config to `script.js` and your Wi-Fi and Firebase details to the Arduino sketch.
3. Upload the sketch to the Arduino and open `index.html` in a browser.
