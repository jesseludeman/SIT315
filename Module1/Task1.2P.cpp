// Jesse Ludeman - SIT315

// PINs on the board.
int pirSensor = 3;
int BTN_PIN = 2;
const int led_PIN = 12;

// Global variables.
//volatile uint8_t led_state = 0;
volatile uint8_t led_state = 0;
volatile uint8_t motion_state = LOW;

void setup()
{
  	// PIR sensor.
  	pinMode(pirSensor, INPUT);
  	// Red LED.
  	pinMode(led_PIN, OUTPUT);
    // Button PIN.
    pinMode(BTN_PIN, INPUT_PULLUP);
    // Attach the interrupt here.
    attachInterrupt(digitalPinToInterrupt(pirSensor), pin_ISR, HIGH);
  	attachInterrupt(digitalPinToInterrupt(BTN_PIN), alert, HIGH);
    Serial.begin(9600);
}

void loop()
{
    
}
void alert()
{
    // Logic for the interrupt goes here.
    led_state = !led_state;
    digitalWrite(led_PIN, led_state);
    Serial.println("Interrupt Occurred!");
}

void pin_ISR() 
{
    // Logic for the interrupt goes here.
    motion_state = !motion_state;
    digitalWrite(led_PIN, motion_state);
    Serial.println("Interrupt Occurred!");
}
