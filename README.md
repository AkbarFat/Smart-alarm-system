# Smart-alarm-system
Content of the project 

ESP32 microcontroller connected to passive infrared light (PIR) 
sensor sends an alarm message when somebody comes in or out the 
door via Telegram bot. Plus I added a buzzer to the circuit 
which is also controlled from Telegram bot. 
Items required for the project: 
Passive infrared light sensor 

 ESP32 board 
 
 Bread board 
 
 USB Cable 
 
 Buzzer 
 
 Wires
 
 LED 
 
 220-ohm resistor 

 Building the circuit:

ESP32 is connected to PIR sensor (GPIO 5) 

ESP32 is connected to Yellow LED through the resistor of value 220-Ohm (GPIO 19) 

ESP32 is connected to buzzer (GPIO 23)

Creating Telegram Bot:

Open Telegram and follow the next steps to create a Telegram Bot. First, search for “botfather” and click the BotFather as shown below. Or open this link t.me/botfather in your smartphone. 

• Start the bot  

• Choose command /newbot to create a new bot

• After this, you will be given your BOT TOKEN, copy and save it! 
