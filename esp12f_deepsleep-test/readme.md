# Programming with a USB to serial adapter:
https://circuits4you.com/2016/12/14/reset-programming-esp8266/

To wire up the programmer you need to connect the following pins (also shown in an image above):

![alt text](https://raw.githubusercontent.com/staceyszigeti/OwnTestCollection/master/esp12f_deepsleep-test/ESP8266-Programming-Circuit.png)
![alt text](https://www.allaboutcircuits.com/uploads/articles/20170323-lee-wifieye-circuit-pgm-1.jpg)

Connect TX of the programmer to RX of the ESP8266 (Not a typo, the connections are reversed)
Connect RX of the programmer to TX of the ESP8266
Connect Ground of the programmer to Ground of the ESP8266
To upload your sketch, do the following steps:

Select the port number of your Serial adapter (Tools->Port)
Enable programming mode on your ESP8266 as described above
Click the upload button. (If it fails double check your wiring and try resting your board into programming mode again)
Click the reset button when the upload has finished
Here are the board settings I used when uploading using this method:

Board: Generic ESP8266 Module
Flash Mode: DIO
Flash Size: 4M (3M Spiffs)
Reset Method: ck
Flash Frequency: 40MHz
Upload Speed: 115200
The last thing to note is the LED_BUILIN definition for a generic ESP8266 module points to pin 1, but the built in LED of a ESP12 module is connected to pin 2 (It's active low too just as an FYI). So if you are testing out a blink sketch you will need to use the number 2 rather than LED_BUILTIN


To put device in serial programming mode
1. Press and hold FLASH (S2) Button.
2. Press and release RESET (S1) button while S2 is in pressed condition.
3. Release FLASH(S2) button after device reset.
4. These steps put ESP8266 in serial programming mode.
Once the device is programmed the internal default flash will be erased, default program can control ESP8266 using AT commands. Once you flash it using above steps you will not able to use AT commands on ESP8266. You have to re-flash with its original AT command boot code to use AT commands again.

# Deepsleep
https://randomnerdtutorials.com/esp8266-deep-sleep-with-arduino-ide/
