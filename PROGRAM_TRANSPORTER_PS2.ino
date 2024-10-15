#include <PS2X_lib.h>
#include <Servo.h>

PS2X ps2x;
Servo servoA;
Servo servoB;

int IN1 = 9;
int IN2 = 8;
int IN3 = 7;
int IN4 = 4;
int ENA = 6;
int ENB = 5;

int error = 0;
byte type = 0;
byte vibrate = 0;
int posA = 0;
int posB = 0;

void setup() {
  Serial.begin(9600);

  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(ENA, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(ENB, OUTPUT);
  
  servoA.attach(2);
  servoA.write(posA);
  servoB.attach(3);
  servoB.write(posB);

  error = ps2x.config_gamepad(13,11,10,12, true, true);

  if(error == 0) {
    Serial.println("Controller connected successfully!");
  } else {
    Serial.print("Controller error: ");
    Serial.println(error);
  }
}

void loop() {
  if(error != 0) return;

  ps2x.read_gamepad(false, vibrate);

  if(ps2x.Button(PSB_L1)){
    posA+=5;
    servoA.write(posA);
    Serial.println("Servo A +5");
  } else if(ps2x.Button(PSB_R1)){
    posA-=5;
    servoA.write(posA);
    Serial.println("Servo A -5");
  }

  if(ps2x.Button(PSB_L2)){
    posB+=5;
    servoB.write(posB);
    Serial.println("Servo B +5");
  } else if(ps2x.Button(PSB_R2)){
    posB-=5;
    servoB.write(posB);
    Serial.println("Servo B -5");
  }

  if(ps2x.Analog(PSS_LY) < 127 && ps2x.Analog(PSS_LY) > 0) {
    Serial.println("Maju Kiri");
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, 150); // Atur kecepatan motor
  } else if(ps2x.Analog(PSS_LY) == 0) {
    Serial.println("maju Kiri Gaspol");
    digitalWrite(IN3, LOW);
    digitalWrite(IN4, HIGH);
    analogWrite(ENB, 255); // Gas penuh
  } else if(ps2x.Analog(PSS_LY) > 127 && ps2x.Analog(PSS_LY) < 255) {
    Serial.println("Mundur Kiri");
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 150); // Atur kecepatan motor mundur
  } else if(ps2x.Analog(PSS_LY) == 255) {
    Serial.println("Mundur Kiri Gaspol");
    digitalWrite(IN3, HIGH);
    digitalWrite(IN4, LOW);
    analogWrite(ENB, 255); // Gas penuh mundur
  } else {
    Serial.println("Berhenti");
    digitalWrite(IN3, LOW); 
    digitalWrite(IN4, LOW); 
  }

  if(ps2x.Analog(PSS_RY) < 127 && ps2x.Analog(PSS_RY) > 0) {
    Serial.println("Maju Kanan");
    digitalWrite(IN1, LOW); // Atur pin motor kanan
    digitalWrite(IN2, HIGH); 
    analogWrite(ENA, 150); // Set kecepatan motor kanan
  } else if(ps2x.Analog(PSS_RY) == 0) {
    Serial.println("maju Kanan Gaspol");
    digitalWrite(IN1, LOW);
    digitalWrite(IN2, HIGH);
    analogWrite(ENA, 255); // Gas penuh kanan
  } else if(ps2x.Analog(PSS_RY) > 127 && ps2x.Analog(PSS_RY) < 255) {
    Serial.println("Mundur Kanan");
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    analogWrite(ENA, 150);
  } else if(ps2x.Analog(PSS_RY) == 255) {
    Serial.println("Mundur Kanan Gaspol");
    digitalWrite(IN1, HIGH); 
    digitalWrite(IN2, LOW); 
    analogWrite(ENA, 255); // Gas penuh mundur kanan
  } else {
    Serial.println("Berhenti");
    digitalWrite(IN1, LOW); 
    digitalWrite(IN2, LOW); 
  }
  delay(100);
}
