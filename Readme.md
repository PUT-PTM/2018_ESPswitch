# ESPswitch

### Hardware
 
+ESP8266 NodeMCU v3
 
+LED Display

+micro-USB cable

### Software
 
Arduino IDE - with ESP8266 package

### Overview

Project of displaying digits on LED display by ESP module through WLAN

### Description

ESP module (powered through micro-USB cable) connects to local WiFi (need to provice SSID and password), puts web server by which it is controlled, next the module itself is connected to LED Display, which displays digits.

## Pin connect pattern

+ Digit 1-4 - 3,3V
+ VCC - 3,3V
+ a - PIN1(GPIO5)
+ b - PIN2(GPIO4)
+ c - PIN3(GPIO0)
+ d - PIN4(GPIO2)
+ e - PIN5(GPIO14)
+ f - PIN6(GPIO12)
+ g - PIN7(GPIO13)

### How to use

1. Adjust the code to Your WiFi settings, such as SSID and password, for letting ESP connect to your LAN
2. Push the code into ESP module through USB cable
3. Once the connection to WiFi is established, put IP of the module into the web browser
4. Chose button with digit
5. Enjoy

### Credit

Adam Sołczak

<hr>
The project was conducted during the Microprocessor Lab course held by the Institute of Control and Information Engineering, Poznan University of Technology. Supervisor: Tomasz Mańkowski
