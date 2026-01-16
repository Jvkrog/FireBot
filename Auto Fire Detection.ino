#define BLYNK_TEMPLATE_ID ""
#define BLYNK_TEMPLATE_NAME "Fire Detection"
#define BLYNK_AUTH_TOKEN ""

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <Servo.h>

// Wi-Fi credentials
char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Vamshi's A55 5g";
char pass[] = "jvkrog26";

// Pins
#define flameSensor D1
#define servoSensorPin D2
#define servoPipePin D3
#define buzzer D4

Servo servoSensor;
Servo servoPipe;

int flameDetected = HIGH;
int currentAngle = 0;
int flamePosition = -1;

BlynkTimer timer;

void setup() {
  Serial.begin(115200);

  pinMode(flameSensor, INPUT);
  pinMode(buzzer, OUTPUT);
  digitalWrite(buzzer, LOW);

  servoSensor.attach(servoSensorPin);
  servoPipe.attach(servoPipePin);

  servoSensor.write(0);
  servoPipe.write(90);

  Serial.println("Connecting to Blynk...");
  Blynk.begin(auth, ssid, pass);
  Serial.println("Connected!");

  timer.setInterval(2000L, checkFire);
}

void checkFire() {
  flameDetected = digitalRead(flameSensor);
  if (flameDetected == LOW) {
    Serial.println("🔥 Fire detected!");
    digitalWrite(buzzer, HIGH);

    // Send alert to Blynk app
    Blynk.logEvent("fire_detected", "🔥 Fire detected by NodeMCU system!");
    Blynk.virtualWrite(V1, "Fire Detected!");

    extinguishFire();

    digitalWrite(buzzer, LOW);
  } else {
    Blynk.virtualWrite(V1, "No Fire");
  }
}

void extinguishFire() {
  // Move pipe to fire direction (use servo 2)
  servoPipe.write(90);
  delay(300);
  for (int i = 0; i < 3; i++) {
    servoPipe.write(60);
    delay(300);
    servoPipe.write(120);
    delay(300);
  }
  servoPipe.write(90);
}

void loop() {
  Blynk.run();
  timer.run();

  // Servo 1 scanning motion
  for (currentAngle = 0; currentAngle <= 180; currentAngle += 15) {
    servoSensor.write(currentAngle);
    delay(200);
    if (digitalRead(flameSensor) == LOW) return;
  }

  for (currentAngle = 180; currentAngle >= 0; currentAngle -= 15) {
    servoSensor.write(currentAngle);
    delay(200);
    if (digitalRead(flameSensor) == LOW) return;
  }
}