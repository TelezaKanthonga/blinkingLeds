// Initialize variables for LED pins
int blueLed = 1;
int redLed = 2;
int greenLed = 3;
int yellowLed = 4;

// Initialize variables for switch pins
int switch1 = 5;
int switch2 = 6;

// Variable to keep track of the current count
int count = 0;

// Function to control the LED states based on the count
void lights();

// Variable to store the state of the button press
int buttonpress;

// Variables to store the state of switch1 and switch2
int switch1_state;
int switch2_state;

void setup() {
  // Set switch pins as inputs with internal pull-up resistors enabled
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);

  // Set LED pins as outputs
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  
  // Initialize the serial communication
  Serial.begin(9600);
}

// Function to control the LED states based on the count
void lights() {
  // Turn off all LEDs if the count is 0
  if (count == 0) {
    digitalWrite(blueLed, LOW);
    digitalWrite(redLed, LOW);
    digitalWrite(greenLed, LOW);
    digitalWrite(yellowLed, LOW);
  }

  // Determine which LEDs to turn on based on the count value
  // ...

  // Add more conditions for different count values
  // ...
}

void loop() {
  // Call the lights() function to update the LED states
  lights();
  
  // Read the states of switch1 and switch2
  switch1_state = digitalRead(switch1);
  switch2_state = digitalRead(switch2);

  // Increment the count when switch1 is pressed
  if (switch1_state == HIGH && buttonpress == 0) {
    // Debounce the switch by adding a delay
    buttonpress = 1;
    delay(1000);

    // Increment the count
    count++;

    // Reset the count if it exceeds 15
    if (count > 15) {
      count = 0;
    }
  }

  // Decrement the count when switch2 is pressed
  if (switch2_state == HIGH && buttonpress == 0) {
    // Debounce the switch by adding a delay
    buttonpress = 1;
    delay(1000);

    // Decrement the count
    count--;

    // Reset the count to 0 if it becomes negative
    if (count < 0) {
      count = 0;
    }

    // Reset the buttonpress variable
    buttonpress = 0;
  }
}

