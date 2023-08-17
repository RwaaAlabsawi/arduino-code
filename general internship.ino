const int buzzer = 9;
#define LED_1_PIN 4
#define LED_2_PIN 5
#define LED_3_PIN 6
#define BUTTON_PIN 2
#define LED_NUMBER 3
byte LEDPinArray[LED_NUMBER] = { LED_1_PIN,
                                 LED_2_PIN,
                                 LED_3_PIN };     // the number of the LED pin

// variables will change:
int buttonState = 0;         // variable for reading the pushbutton status
int count_value =0;
int prestate =0;


void setup() {
  // initialize the LED pin as an output:
  pinMode(LED_1_PIN, OUTPUT);
  // initialize the pushbutton pin as an input:
  pinMode(BUTTON_PIN, INPUT);
  Serial.begin(9600);
  pinMode(buzzer, OUTPUT);
}

void loop() {
  // read the state of the pushbutton value:
  buttonState = digitalRead(BUTTON_PIN);

  // check if the pushbutton is pressed. If it is, then the buttonState is HIGH:
  if (buttonState == HIGH && prestate == 0) {
    count_value++;
    Serial.println(count_value);
    delay(100);
    prestate = 1;
  } else if(buttonState == LOW) {
    prestate = 0;
  }

  for (int i = 0; i < count_value; i++) {
    digitalWrite(LEDPinArray[i], HIGH);
  }

  if (count_value == 3){
    delay(1000);
    tone(buzzer, 1000); // Send 1KHz sound signal...
    delay(1000);        // ...for 1 sec
    noTone(buzzer);     // Stop sound...
    delay(1000); 
    for (int i = 0; i < 4; i++) {
    digitalWrite(LEDPinArray[i], LOW);
    }
    count_value = 0;
  }
}
