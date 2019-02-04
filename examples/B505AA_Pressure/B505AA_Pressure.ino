#include "Nox_Environment.h"

// Measure Parameters
int Sensor_Read_Count = 1;
int Sensor_Average_Type = 5;

// Define Library
Nox_Environment Environment;

void setup() {

// Serial Communication Start
Serial.begin(115200);

// Start I2C
Wire.begin();

// Sensor EN to LOW
pinMode(13, OUTPUT); digitalWrite(13, LOW);

}

void loop() {

// Define Sensor Variables
float _Measurement = 0;
double _Deviation = 0;
unsigned long Time;

// Sensor EN to HIGH
pinMode(13, OUTPUT); digitalWrite(13, HIGH); delay(10);

// Set Start Time
Time = millis();

// Measure
Environment.B505AA_P(Sensor_Read_Count, Sensor_Average_Type, _Measurement, _Deviation);

// Calculate Delta Time
int DT = millis() - Time;

// Sensor EN to LOW
pinMode(13, OUTPUT); digitalWrite(13, LOW);

// Serial Print Data
Serial.print("Function Version        : "); Serial.println(Environment.B505AA_P_Version);
Serial.print("Value                   : "); Serial.print(_Measurement, 3); Serial.println(" mBar");
Serial.print("Standart Deviation      : "); Serial.println(_Deviation, 5);
Serial.print("Read Count              : "); Serial.println(Sensor_Read_Count);
Serial.print("Average Type            : "); Serial.println(Sensor_Average_Type);
Serial.print("Function Time           : "); Serial.print(DT); Serial.println(" mS");
Serial.println("--------------------------");

// Loop Delay
delay(1000);

}
