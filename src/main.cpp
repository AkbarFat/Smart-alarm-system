#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>


// Replace with your network credentials
const char* ssid = " IoTExperiment";
const char* password = "iotexperiment303ab";

// Replace with your Telegram bot token
const char* telegramBotToken = 
"Your Telegram bot token";

// Replace with your Telegram chat ID
const String chat_id = "Your chat id";

// Initialize WiFi and Telegram bot clients
WiFiClientSecure client;
UniversalTelegramBot bot(telegramBotToken, client);

// Define the IR sensor pin
const int irSensorPin = 5; 
const int led = 19;
const int buzzerPin = 23;

// Function prototypes
void sendTelegramMessage(const String &message);

void handleNewMessages(int numNewMessages) {
  for (int i = 0; i < numNewMessages; i++) {
    String chat_id = String(bot.messages[i].chat_id);
    String text = bot.messages[i].text;

    if (text == "/buzz") {
      bot.sendMessage(chat_id, "Buzzer activated!", "");
      tone(buzzerPin, 1000);  // Send 1KHz sound signal
      delay(500);             // Wait for 500ms
      noTone(buzzerPin);      // Stop sound
    }
  }
}


void setup() {
  Serial.begin(115200);
  pinMode(irSensorPin, INPUT);
  pinMode(led, OUTPUT);
  pinMode(buzzerPin, OUTPUT);

  // Connect to Wi-Fi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }
  Serial.println("Connected to WiFi");

  // Set certificate for Telegram (optional)
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT);

}


void loop() {
  int sensorValue = digitalRead(irSensorPin);

  if (sensorValue == HIGH) {
      digitalWrite(led,HIGH);
      String message = "Person detected at the door!";
      Serial.println(message);
      sendTelegramMessage(message); // Send message via Telegram bot
    } else if (sensorValue == LOW) {
      digitalWrite(led,LOW);
      Serial.println("No person detected.");
  }

  if (WiFi.status() != WL_CONNECTED) {
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
      delay(1000);
      Serial.println("Reconnecting to WiFi...");
    }
    Serial.println("Reconnected to WiFi");
  }

  int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

  while (numNewMessages) {
    handleNewMessages(numNewMessages);
    numNewMessages = bot.getUpdates(bot.last_message_received + 1);
  }

  delay(1000);

}

void sendTelegramMessage(const String &message) {
  bot.sendMessage(chat_id, message, ""); // Send message via Telegram bot
}

