#include <WiFi.h>
#include <HTTPClient.h>

#define MOISTURE_PIN A0  // Assuming the moisture sensor is connected to analog pin A0

String URL = "http://192.168.0.106/G-innovator/index.php";

const char* ssid = "Zabir";
const char* password = "zabirhasan";



int moistureValue = 100;



void setup() {
  Serial.begin(9600);
  connectWiFi();
}





void loop() {
  if(WiFi.status() != WL_CONNECTED) {
    connectWiFi();
  }

  Load_Moisture_Data();
  String postData = "moisture=" + String(moistureValue);
  
  HTTPClient http;
  http.begin(URL);
  http.addHeader("Content-Type", "application/x-www-form-urlencoded");
  
  int httpCode = http.POST(postData);
  String payload = "";

  if(httpCode > 0) {
    if(httpCode == HTTP_CODE_OK) {
      payload = http.getString();
      Serial.println(payload);
    } 
   else 
   {
      Serial.printf("[HTTP] POST... code: %d\n", httpCode);
    }
  } 

else {
    Serial.printf("[HTTP] POST... failed, error: %s\n", http.errorToString(httpCode).c_str());
  }
  
  http.end();  //Close connection

  Serial.print("URL : "); Serial.println(URL);
  Serial.print("Data: "); Serial.println(postData);
  Serial.print("httpCode: "); Serial.println(httpCode);
  Serial.print("payload : "); Serial.println(payload);
  Serial.println("--------------------------------------------------");
  delay(5000);
}




void Load_Moisture_Data() {
  moistureValue = analogRead(4);
  Serial.printf("Moisture level: \n");
  Serial.println(analogRead(4));
  delay(2000); 
}



void connectWiFi() {
  WiFi.mode(WIFI_OFF);
  delay(1000);
  WiFi.mode(WIFI_STA);
  
  WiFi.begin(ssid, password);
  Serial.println("Connecting to WiFi");
  
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
    
  Serial.print("connected to : "); Serial.println(ssid);
  Serial.print("IP address: "); Serial.println(WiFi.localIP());
}
