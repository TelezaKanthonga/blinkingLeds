int blueLed=1;
int redLed=2;
int greenLed=3;
int yellowLed=4;
int switch1=5;
int switch2=6;
int count=0;
void lights();
int buttonpress;


int switch1_state;
int switch2_state;
void setup() {
  // put your setup code here, to run once:
  //Inputs
  pinMode(switch1, INPUT_PULLUP);
  pinMode(switch2, INPUT_PULLUP);

// outputs
  pinMode(blueLed, OUTPUT);
  pinMode(redLed, OUTPUT);
  pinMode(greenLed, OUTPUT);
  pinMode(yellowLed, OUTPUT);
  
 
  Serial.begin(9600);

}

 void lights(){
  if (count == 0){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,LOW);
  }

  if (count == 1){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,HIGH);
  }
  if (count == 2){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,LOW);
  }
  if (count == 3){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,HIGH);
  }
  if (count == 4){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,LOW);
  }
  if (count == 5){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,HIGH);
  }
  if (count == 6){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,LOW);
  }
  if (count == 7){
  digitalWrite(blueLed,LOW);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,HIGH);
  }
   if (count == 8){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,LOW);
   }
  if (count == 9){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,HIGH);
  }
  if (count == 10){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,LOW);
  }
  if (count == 11){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,LOW);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,HIGH);
  }
  if (count == 12){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,LOW);
  }
  if (count == 13){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,LOW);
  digitalWrite(yellowLed,HIGH);
  }
  if (count == 14){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,LOW);
  }
  if (count == 15){
  digitalWrite(blueLed,HIGH);
  digitalWrite(redLed,HIGH);
  digitalWrite(greenLed,HIGH);
  digitalWrite(yellowLed,HIGH);
  }
  
  }

void loop() {
lights();
  // put your main code here, to run repeatedly:
//  if (count == 0){
//  digitalWrite(blueLed,LOW);
//  digitalWrite(redLed,LOW);
//  digitalWrite(greenLed,LOW);
//  digitalWrite(yellowLed,LOW);
//  }

  
 switch1_state= digitalRead(switch1);
 switch2_state=digitalRead(switch2);

 //count increment after pressing switch1
 if (switch1_state == HIGH && buttonpress==0) {
    buttonpress=1;
    delay(1000);
    count++;
    buttonpress=1;
    if (count > 15){
      count=0;
    }
 }
 //decrement count after pressing switch2
 
 if (switch2_state == HIGH && buttonpress == 0) {
    
    buttonpress=1;
    delay(1000);
    count--;
    buttonpress=0;
     if (count < 0){
      count=0;
    }
    
 

  } 

 } 

 
   

