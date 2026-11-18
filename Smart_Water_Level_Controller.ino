
/*
  Controller : Arduino Uno
  Sensor     : HC-SR04 Ultrasonic Sensor
  Display    : 16x2 I2C LCD
  Actuator   : 5V Relay Module + DC Water Pump

  Developed by: Rajan Robotics
  Vision to Reality
*/

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

// Pin definitions
#define TRIG_PIN   9
#define ECHO_PIN   10
#define RELAY_PIN  7

// LCD address (commonly 0x27)
LiquidCrystal_I2C lcd(0x27, 16, 2);

// Tank dimensions in centimetres
const float TANK_HEIGHT = 30.0;

// Water level control thresholds (%)
const int LOW_LEVEL = 30;
const int HIGH_LEVEL = 90;

// Change to HIGH if your relay is active HIGH
const int RELAY_ON = LOW;
const int RELAY_OFF = HIGH;

bool pumpState = false;

float measureDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  unsigned long duration =
      pulseIn(ECHO_PIN, HIGH, 30000UL);

  if (duration == 0)
    return -1;

  return (duration * 0.0343) / 2.0;
}

void controlPump(int level)
{
  // Start filling when water level is low
  if (level <= LOW_LEVEL)
  {
    pumpState = true;
  }

  // Stop filling when upper level is reached
  else if (level >= HIGH_LEVEL)
  {
    pumpState = false;
  }

  digitalWrite(RELAY_PIN,
               pumpState ? RELAY_ON : RELAY_OFF);
}

void displayStatus(int level)
{
  lcd.setCursor(0, 0);
  lcd.print("Water Level:    ");

  lcd.setCursor(12, 0);
  lcd.print(level);
  lcd.print("% ");

  lcd.setCursor(0, 1);

  if (pumpState)
  {
    lcd.print("Pump: ON        ");
  }
  else
  {
    lcd.print("Pump: OFF       ");
  }
}

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(RELAY_PIN, OUTPUT);

  digitalWrite(TRIG_PIN, LOW);

  // Keep pump OFF during startup
  pumpState = false;
  digitalWrite(RELAY_PIN, RELAY_OFF);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("RAJAN ROBOTICS");

  lcd.setCursor(0, 1);
  lcd.print("Water Controller");

  delay(2000);
  lcd.clear();

  Serial.println("RAJAN ROBOTICS");
  Serial.println("Smart Water Level Controller");
}

void loop()
{
  float distance = measureDistance();

  // Validate ultrasonic reading
  if (distance < 0 || distance > TANK_HEIGHT)
  {
    Serial.println("Invalid sensor reading");

    // Fail-safe: stop pump if sensor reading is invalid
    pumpState = false;
    digitalWrite(RELAY_PIN, RELAY_OFF);

    lcd.setCursor(0, 0);
    lcd.print("Sensor Error    ");
    lcd.setCursor(0, 1);
    lcd.print("Pump: OFF       ");

    delay(500);
    return;
  }

  // Calculate water level percentage
  float waterHeight = TANK_HEIGHT - distance;

  int waterLevel =
      constrain((int)((waterHeight / TANK_HEIGHT) * 100),
                0, 100);

  controlPump(waterLevel);
  displayStatus(waterLevel);

  // Serial Monitor information
  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.print(" cm | Water Level: ");
  Serial.print(waterLevel);
  Serial.print("% | Pump: ");

  Serial.println(pumpState ? "ON" : "OFF");

  delay(500);
}
