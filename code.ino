#include <DHT.h>

// ===================== SENSOR SETUP =====================
#define DHTPIN 2          // DHT11 DATA pin connected to Arduino D2
#define DHTTYPE DHT11     // Sensor type

DHT dht(DHTPIN, DHTTYPE);

// ===================== MOTOR DRIVER PINS =====================
int IN1 = 9;       // L293D IN1
int IN2 = 8;       // L293D IN2
int ENA = 10;      // L293D Enable pin (PWM Speed Control)

// ===================== TEMPERATURE SETTINGS =====================
float thresholdTemp = 30.0;   // Fan turns ON above 30°C

// ===============================================================
void setup() {

  Serial.begin(9600);
  dht.begin();

  // Motor Driver pins as OUTPUT
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);

  // Fan initially OFF
  digitalWrite(IN1, LOW);
  digitalWrite(IN2, LOW);
  analogWrite(ENA, 0);

  Serial.println("======================================");
  Serial.println(" Automatic Fan Control System Started ");
  Serial.println(" Using Arduino + DHT11 + L293D Driver ");
  Serial.println("======================================");
}

// ===============================================================
void loop() {

  // Read Temperature and Humidity
  float temp = dht.readTemperature();
  float hum = dht.readHumidity();

  // Check if sensor reading failed
  if (isnan(temp) || isnan(hum)) {
    Serial.println("❌ Failed to read from DHT11 sensor!");
    delay(2000);
    return;
  }

  // Display readings
  Serial.println("--------------------------------------");
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.println(" °C");

  Serial.print("Humidity: ");
  Serial.print(hum);
  Serial.println(" %");

  // ================= FAN CONTROL LOGIC =================
  if (temp > thresholdTemp) {

    Serial.println("✅ Fan Status: ON");

    // Motor Forward Direction
    digitalWrite(IN1, HIGH);
    digitalWrite(IN2, LOW);

    // Variable Speed Control (PWM)
    int fanSpeed = map(temp, thresholdTemp, 45, 120, 255);
    fanSpeed = constrain(fanSpeed, 0, 255);

    analogWrite(ENA, fanSpeed);

    Serial.print("Fan Speed (PWM): ");
    Serial.println(fanSpeed);

  } 
  else {

    Serial.println("🛑 Fan Status: OFF");

    // Stop Motor
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, LOW);
    analogWrite(ENA, 0);
  }

  delay(2000);   // Update every 2 seconds
}
