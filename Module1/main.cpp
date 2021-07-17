// C++ code
int pirSensor = 0;

void setup()
{
  	// PIR sensor
  	pinMode(3, INPUT);
  	// Red LED
  	pinMode(12, OUTPUT);
  	Serial.begin(9600);
}

void loop()
{
	pirSensor = digitalRead(3);
  
  	// Check if the PIR sensor reads a HIGH value.
  	// If true, turn the LED on.
  	if (pirSensor == HIGH)
    {
     	digitalWrite(12, HIGH);
      	Serial.println("Movement detected");
    }
  	else
    {
     	digitalWrite(12, LOW);
      	Serial.println("No movement detected");
    }
  
  	// Delay a bit to improve simulation
  	delay(20);
}
