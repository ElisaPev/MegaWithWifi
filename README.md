# Mega With Wifi
Documentation for the Mega with Wifi to help anyone
The Mega with Wifi is comprised of an Arduino Mega and has an ESP32 added on for the Wifi potential.

There are two arduino files included. 

ESPExV and MegaEXv

MegaExV is the code used to communicate from the Mega to the ESP32.

ESPExV is the code used to read the Mega's serial message.

Overall the code is a simple program. All it does it the Mega generates a random number and then sends it over Serial to the ESP32, ESP32 then reads the randonnumber and depending on the random number it will light up an LED.

This is created to help people learn how to make the Mega communicate to the ESP32. Any other questions are able to be answered by looking at the Arduino Mega information of the individual ESP32 information.

I will be uploading a video for more detail on how to upload code to the Mega, ESP, see Mega's serial, see the EPS's serial and how to allow communication between both.

If you have any questions before that, please feel free to add it in discussions and I'll try to help out as soon as possible.
