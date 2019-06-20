<h1>Remotely control your robot built on ESP8266 from PC using python script</h1>

This is a simple approach how to control you robot from computer over WiFi using the python script and ESP8266 controller.
The python script give you ability to script the robot movements on fly, without re-flashing controller.

<h2>Instructions</h2>
Write your WiFi network SSID and Password to <b>esp8266.ino</b>, compile it in Arduino IDE and flash to ESP8266.
Then in serial monitor you should see how ESP8266 connects to your WiFi network and prints its IP address.<br/>
<br/>
Put this IP address to <b>client.py</b> and run:<br/>
<b>python client.py</b>
<br/>
NB! Check the comments in client.py if you are running on python version 3.x
(to check the python version run: python -V)<br/>
<br/>
Demo video:</br>
...

Components used in the robot:
- EPS8266 Wemos D1
- L9110S H-bridge (to drive two DC motors) 
- LM2596 Mini (3A Step Down Voltage Regulator)
