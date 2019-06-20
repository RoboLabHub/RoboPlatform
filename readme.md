How to remotely control your robot from PC (built on ESP8266).

This is a simple approach how to control you robot from computer over WiFi using the python script and ESP8266 controller.
The python script give you ability to script the robot movements on fly, without re-flashing controller.

Instructions:
Write your WiFi network SSID and Password to esp8266.ino, compile it in Arduino IDE and flash to ESP8266.
Then in serial monitor you should see how ESP8266 connects to your WiFi network and prints its IP address.

Put this IP address to client.py and run:
python client.py

NB! Check the comments in client.py if you are running on python version 3.x
(to check the python version run: python -V)

Demo video:
...

Components used in the robot:
- EPS8266 Wemos D1
- L9110S H-bridge (to drive two DC motors) 
- LM2596 Mini (3A Step Down Voltage Regulator)
