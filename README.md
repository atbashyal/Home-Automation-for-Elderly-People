# Home Automation for Elderly People

## COMPONENTS USED
### Sensors and Actuators:
#### Software Requirements
1. Arduino IDE <br>
2. MIT Application Inventor <br>

#### Hardware Requirements
1. Arduino UNO R3
2. Smoke and Air Quality Sensor (MQ-135)
3. Rain Sensor Module
4. Reed Magnetic Sensor
5. Temperature Sensor (LM-35)
6. Heard Pulse Sensor
7. HC05 Bluetooth Module
8. Smartphone

## ARCHITECTURE
![image](https://user-images.githubusercontent.com/68748665/222452392-9144a40a-11a4-4574-bd5e-aea9719de005.png)

## ALGORITHM
<b> Step 1: </b>Declare variables and initialize pin assignments for sensors and other devices.<br><br>
<b> Step 2: </b>Initialize serial communication at a baud rate of 9600.<br><br>
<b> Step 3: </b>Set pin mode for door switch as input.<br><br>
<b> Step 4: </b>Initialize DHT11 temperature and humidity sensor.<br><br>
<b> Step 5: </b>Create a loop that runs continuously.<br><br>
<b> Step 6: </b>Call the gaslevel() function to read the analog output of the gas sensor.<br><br>
<b> Step 7: </b>Call the doorstatus() function to check the status of the door using a reed magnetic sensor and store the status as a string.<br><br>
<b> Step 8: </b>Call the rainstatus() function to check the status of the rain using an analog rain sensor and store the status as a string.<br><br>
<b> Step 9: </b>Call the temperaturee() function to read the temperature from the DHT11 sensor and store the value as a float.<br><br>
<b> Step 10: </b>Call the heartbeat() function to read the output from the BPM sensor and store the value as a float.<br><br>
<b> Step 11: </b>Call the btprint() function to concatenate all the sensor outputs into a single string and send it over the serial port for Bluetooth to receive.<br><br>
<b> Step 12: </b>Delay the program for 3 seconds before repeating the loop.<br><br>
<b> Step 13: </b>The gaslevel() function reads the analog output from the gas sensor and stores the value as an integer.<br><br>
<b> Step 14: </b>The doorstatus() function reads the input from the door switch and checks whether the door is open or closed. It stores the status as a string.<br><br>
<b> Step 15: </b>The rainstatus() function reads the analog output from the rain sensor and maps the value to one of three possible states: RAINING, RAIN WARNING, or NOT RAINING. It stores the status as a string.<br><br>
<b> Step 16: </b>The temperaturee() function reads the temperature value from the DHT11 sensor and stores it as a float.<br><br>
<b> Step 17: </b>The heartbeat() function reads the output from the BPM sensor and stores the value as a float.<br><br>
<b> Step 18: </b>The btprint() function concatenates all the sensor outputs into a single string separated by "|" and sends it over the serial port for Bluetooth to receive.<br><br>

## RESULT
![image](https://user-images.githubusercontent.com/68748665/222454155-0c125879-87f1-4337-b437-486ae381d23f.png)

## CONCLUSION
The project was designed, developed, and tested successfully, and it served its intended purpose. We are able to demonstrate the use of a microcontroller for the elderly in various use cases. This project has allowed us to learn about various controllers, sensors, application development platforms, and technologies. We encountered numerous challenges while developing the project, but we were able to overcome them one by one by referring to the references. The project's goal has been accomplished.
