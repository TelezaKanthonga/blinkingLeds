//an Arduino program that utilizes the Arduino FreeRTOS library to create and manage multiple tasks. 
//The program controls a set of 8 LEDs connected to different pins of the Arduino board.

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <semphr.h>
#define led1 13
#define led2 12
#define led3 11
#define led4 10
#define led5 9
#define led6 8
#define led7 7
#define led8 6

void vTask1(void *pvParameter);
void vTask2(void *pvParameter);
void vTask3(void *pvParameter);
uint8_t ledValue;
int i;

SemaphoreHandle_t xSemaphore;
QueueHandle_t xQueue;

void setup() {
  // put your setup code here, to run once:
  xTaskCreate(vTask1, "Task one", 128, NULL, 1, NULL);
  xTaskCreate(vTask2, "Task two", 128, NULL, 1, NULL);
  xTaskCreate(vTask3, "Task three", 128, NULL, 1, NULL);
xQueue=xQueueCreate(1,sizeof(uint8_t));
xSemaphore=xSemaphoreCreateBinary();

  vTaskStartScheduler();
  Serial.begin(9600);
}



void loop() {
  // put your main code here, to run repeatedly:
}

void vTask1(void *pvParameter){
 (void) pvParameter;
 for(;;){
   
 xQueuePeek( xQueue, &ledValue, 0 );
       if(ledValue > 255) {
          xSemaphoreGive(xSemaphore);
        }
  
 vTaskDelay(10);
 }
}
  

 void vTask2(void *pvParameter){
 (void) pvParameter;
 for(;;){
  if(xSemaphoreTake(xSemaphore, 0)== pdTRUE){
    ledValue = 0;
    xQueueReset(xQueue);
  }
 ledValue = ledValue << 1;//appending /shifting 1 to ledValue
  if (ledValue == 0){
    ledValue = 1;
  }
  xQueueSend(xQueue, &ledValue, 0);
  vTaskDelay(100);
 }
 }
void vTask3(void *pvParameter){
 (void) pvParameter;
 for(;;){
   xQueueReceive(xQueue, &ledValue, 0);
   pinMode(led1, OUTPUT);
   pinMode(led2, OUTPUT);
   pinMode(led3, OUTPUT);
   pinMode(led4, OUTPUT);
   pinMode(led5, OUTPUT);
   pinMode(led6, OUTPUT);
   pinMode(led7, OUTPUT);
   pinMode(led8, OUTPUT);


int leds[]={led1,led2,led3,led4,led5,led6,led7,led8};
   
for (int i = 0; i < 8; i++) {  
    // turns the i ON:  
    digitalWrite(leds[i], HIGH);  
    vTaskDelay(10);
    // turnS the i OFF:  
    digitalWrite(leds[i], LOW);  
 
 
 }

vTaskDelay(20);
}
}

