
#include <Arduino.h>
#include "FreeRTOS.h"
#include "task.h"

#ifndef ERROR_HOOKS_H
#define ERROR_HOOKS_H

#ifdef __cplusplus
extern "C"
{
#endif

	//**************************************************
	// defines
	//**************************************************


	//**************************************************
	// function prototypes
	//**************************************************

	// remove a linux or windows path from a file path
	// will leave file name remaining
	const char* removePath(const char* path);

	// called on fatal error (interrupts disabled already)
	void rtosFatalError(void);

	// fatal error print out what file assert failed
	void rtosFatalErrorSerial(unsigned long ulLine, const char *pcFileName);

	// called on full heap or malloc failure
	void vApplicationMallocFailedHook(void);

	// called on full stack
	void vApplicationStackOverflowHook( TaskHandle_t xTask, char *pcTaskName );


	// set the error led to use by the rtos
	void vSetErrorLed(uint8_t pin, uint8_t activeState);

	// blink an error code out the default led when the rtos has crashed
	void errorBlink(int errorNumber);

	// will delay the processors using nops
	// this is used when the rtos has crashed and we cannot use more advanced timing
	void vNopDelayMS(unsigned long millis);

#ifdef __cplusplus
}
#endif

#endif
