/*
 This code will blink an LED attached to pin 13 on and off. 
 It will stay on for 0.25 seconds.
 It will stay off for 1 second.
 */
#include <Metro.h> //Include Metro library

//PINS
#define LED_BARON_0 13 // Define the led's pin
#define BUTTON_BARON_0 2

//Create a variable to hold theled's current state
int state = HIGH;

//METRO INSTANCES
Metro timer_baron_0 = Metro(3000);

//LED STATES
int led_state_baron_0 = HIGH;

//BUTTON VALUES
int button_baron_0 = LOW;

void setup()
{
	//OUTPUTS
	pinMode(LED_BARON_0,OUTPUT);

	//INPUTS
	pinMode(BUTTON_BARON_0, INPUT);

	//INITIAL STATES 
	digitalWrite(LED_BARON_0, led_state_baron_0);
}

void loop()
{
	if( led_state_baron_0 == LOW )
	{
		//CHECK OWN BARON
		if (timer_baron_0.check() == 1) { // check if the metro has passed its interval
		led_state_baron_0 = HIGH;
		digitalWrite(LED_BARON_0, led_state_baron_0);
	}
  }
  else if( digitalRead(BUTTON_BARON_0) )
  {
	led_state_baron_0 = LOW;
	digitalWrite(LED_BARON_0, led_state_baron_0);
	timer_baron_0.reset();
  }

  
}