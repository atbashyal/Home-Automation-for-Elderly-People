#include <DHT.h>
//This program read the input from multiple sensors and send the input to mobile application over serial port over Bluetooth//
int pinSwitch = 5; //Pin Reed
int gaslvl; // integer to store gas sensor values
bool StateSwitch;
int StateRain; // integer to store rain sensor values
String SwitchWrite;
String RainWrite;
float bpm;
float temp;
float bmp;

#define gas (A0) // Analog output of gas sensor is connected to pin A5
#define rain (A5) // Analog output of rain sensor is connected to pin A0
#define DHTPIN 2 //Temperature Pin
#define DHTTYPE DHT11
#define bpmsensor (A1) //Analog output of BPM sensor is connected to pin A1
const int sensorMin = 0; // rain sensor minimum
const int sensorMax = 1024; // rain sensor maximum
DHT dht(DHTPIN,DHTTYPE);
void setup()
{
  Serial.begin(9600);
  pinMode(pinSwitch, INPUT);
  dht.begin();
  
  
}
//void loop only runs the other functions sequentially
void loop()
{
  
  gaslevel();
  doorstatus();
  rainstatus();
  temperaturee();
  heartbeat();
  btprint();
  delay (3000);
}
// function to read the gas sensor analog out put
void gaslevel()
{
  gaslvl = analogRead(gas);
}
// function to check the door status using reed magnetic sensor
void doorstatus()
{
  StateSwitch = digitalRead(pinSwitch);
  if (StateSwitch == LOW)
  {
    SwitchWrite = "CLOSED";
  }
  else
  {
    SwitchWrite = "OPEN";
  }
}
// function to check the rain status based on the anlog value from rain sensor and display appropriate strings
void rainstatus()
{
  StateRain = analogRead(rain);
  int range = map(StateRain, sensorMin, sensorMax, 0, 3);
  //Checks the measured value with pre-stored condition and displays the weather condition like RAINING, RAIN WARNING & NOT RAINING.
  switch (range)
  {
    case 0: // Sensor getting completely wet
      RainWrite = "RAIN";
      break;

    case 1: // Sensor getting partially wet
      RainWrite = "WARNING";
      break;
    case 2: // Sensor dry
      RainWrite = "NO_RAIN";
      break;
  }
}
//function to check the temperature of the person
void temperaturee(){
  temp = dht.readTemperature();
}
//function to check the heartbeat of the person
void heartbeat(){
  bpm = analogRead(bpmsensor);
}
// this function concatenate all the different outputs and send it as a single string on serial port for Bluetooth to receive
// Outputs from different sensors are separated by special character "|" so that the application can split the input using the same
void btprint()
{
  Serial.print(RainWrite);
  Serial.print("|");
  Serial.print(SwitchWrite);
  Serial.print("|");
  Serial.println(gaslvl);
  Serial.print("|");
  Serial.print(temp);
  Serial.print("°C");
  Serial.print("|");
  Serial.print(bmp);
  delay(100);
}
