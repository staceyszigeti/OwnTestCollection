# Wiring #
https://iotbyhvm.ooo/arduino-spi-tutorial/

![picture alt](https://www.electronicwings.com/public/images/user_images/images/NodeMCU/NodeMCU%20Basics%20using%20Arduino%20IDE/NodeMCU%20SPI/Arduino_NodeMCU_SPI_Interface_modified.png)

# Programming #
## Arduino SPI as Master ##
Master unit sends hello world data to slave unit.

## Arduino SPI as Slave ##
Slave unit waits for data as soon as data is arrived process variable becomes true, indicating there is data in buffer. in main loop we read this buffer and send to serial terminal.
