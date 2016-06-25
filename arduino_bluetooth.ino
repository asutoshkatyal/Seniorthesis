//This sketch will use bluetooth to send temperature and humidity
// to a Raspberry PI using bluetooth
// Arduino -> bluetooth

#include <SoftwareSerial.h> //Serial library
#include <DHT.h>

#define DHTPIN 2  //Where is DHT connected
#define DHTTYPE DHT22  // Type of sensor used

/**
 * Arduino connection HC-05 connection: 
 * HC-05  | Arduino
 * TX     | 5
 * RX     | 6
*/
// Here, we exchange them -
SoftwareSerial bt (5,6);  //RX, TX (Switched on the Bluetooth - RX -> TX | TX -> RX)
int btdata; // the data given from the computer

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);
  Serial.println("DHT22 test!");

  bt.begin(9600);
  dht.begin();
}

void loop() {
  
    float h = dht.readHumidity();
    float t = dht.readTemperature();
    float f = dht.readTemperature(true);
    
    Serial.print("Humidity: ");
    Serial.print(h);
    Serial.print(" %\t");
    Serial.print("Temperature: ");
    Serial.print(t);
    Serial.print(" *C   ");
    Serial.print(f);
    Serial.println(" *F\t");
  
    bt.print (String(h) + "," + String(t) + "," + String(f));
    bt.print("\n");

    delay(2000);
}

