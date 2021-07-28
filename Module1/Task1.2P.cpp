// Jesse Ludeman - SIT315 - Task M1.T2P - Interrupt-driven board

// PINs on the board.
int pirSensor = 3;
int push_button = 2;
const int led_PIN = 12;

// Global variables.
volatile uint8_t led_state = 0;
volatile uint8_t motion_state = LOW;

void setup()
{
  	// PIR sensor.
  	pinMode(pirSensor, INPUT);
  	// Red LED.
  	pinMode(led_PIN, OUTPUT);
    // Push button.
    pinMode(push_button, INPUT_PULLUP);
    // Attach the interrupts.
    attachInterrupt(digitalPinToInterrupt(pirSensor), motion_alert, HIGH);
  	attachInterrupt(digitalPinToInterrupt(push_button), led_alert, HIGH);
    Serial.begin(9600);
}

void loop()
{
    // Nothing here!
}
void led_alert()
{
    // Red LED interrupt.
    led_state = !led_state;
    digitalWrite(led_PIN, led_state);
    Serial.println("Red LED Interrupt Detected!");
}

void motion_alert()
{
    // PIR sensor interrupt.
    motion_state = !motion_state;
    digitalWrite(led_PIN, motion_state);
    Serial.println("Motion Detected!");
}
