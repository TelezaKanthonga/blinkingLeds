# blinkingLeds
blinkingleds

## multitasking_led_control.ino
This is an Arduino program that utilizes the Arduino FreeRTOS library to create and manage multiple tasks. 
The program controls a set of 8 LEDs connected to different pins of the Arduino board.

## Breakdown of the code:
- The necessary header files are included, which provide the required libraries and definitions.
- The pin numbers for the LEDs are defined using preprocessor directives.
- Function prototypes for the three tasks are declared.
- Variables for LED values and a loop counter are declared.
- Semaphore and queue handles are declared.
- In the `setup()` function, tasks are created using `xTaskCreate()`, and the semaphore and 
- queue are created using `xSemaphoreCreateBinary()` and `xQueueCreate()` functions respectively. 
- The FreeRTOS scheduler is started using `vTaskStartScheduler()`, and serial communication is initialized.
- The `loop()` function is empty since the tasks are managed by the FreeRTOS scheduler.

## Details of the tasks:

### 1. `vTask1`:
   - It continuously checks the value stored in the `ledValue` variable by peeking into the queue using `xQueuePeek()`.
   - If the `ledValue` is greater than 255, it gives the semaphore using `xSemaphoreGive()` to unlock `vTask2`.
   - It then delays for 10 milliseconds using `vTaskDelay()`.

### 2. `vTask2`:
   - It continuously runs and waits for the semaphore using `xSemaphoreTake()`.
   - When the semaphore is acquired, it sets the `ledValue` to 0 and resets the queue using `xQueueReset()`.
   - It shifts the `ledValue` left by 1 bit, effectively appending a 0 or 1 to the existing value.
   - If the `ledValue` becomes 0, it sets it to 1 to ensure at least one LED is on.
   - The updated `ledValue` is then sent to the queue using `xQueueSend()`.
   - It delays for 100 milliseconds.

### 3. `vTask3`:
   - It continuously runs and waits for a value to be received from the queue using `xQueueReceive()`.
   - The pin modes for all the LEDs are set to OUTPUT.
   - An array `leds` stores the pin numbers of the LEDs.
   - It iterates over the `leds` array and turns each LED on for a brief period using `digitalWrite()` and `vTaskDelay()`.
   - After all LEDs have been cycled through, it delays for 20 milliseconds.

This code demonstrates a simple example of multitasking using FreeRTOS on an Arduino board.
The tasks run concurrently and control the state of the LEDs based on the values passed through the queue.
