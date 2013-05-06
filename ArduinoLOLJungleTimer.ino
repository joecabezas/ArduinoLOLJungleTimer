//Include Metro library
#include <Metro.h>

//DEBUG
#define DEBUG 1

//PINS
#define PIN_LED_BLUE_0	8
#define PIN_LED_BLUE_1	9
#define PIN_LED_RED_0	10
#define PIN_LED_RED_1	11
#define PIN_LED_BARON	12
#define PIN_LED_DRAGON	13

#define PIN_BUTTON_BLUE_0	2
#define PIN_BUTTON_BLUE_1	3
#define PIN_BUTTON_RED_0	4
#define PIN_BUTTON_RED_1	5
#define PIN_BUTTON_BARON	6
#define PIN_BUTTON_DRAGON	7

//METRO INSTANCES
Metro timer_blue_0	= Metro(3000);
Metro timer_blue_1	= Metro(3000);
Metro timer_red_0	= Metro(3000);
Metro timer_red_1	= Metro(3000);
Metro timer_baron	= Metro(3000);
Metro timer_dragon	= Metro(3000);

void setup()
{
	#if DEBUG
		//DEBUG
		Serial.begin(9600);
	#endif

	//OUTPUTS
	pinMode(PIN_LED_BLUE_0, OUTPUT);
	pinMode(PIN_LED_BLUE_1, OUTPUT);
	pinMode(PIN_LED_RED_0, OUTPUT);
	pinMode(PIN_LED_RED_1, OUTPUT);
	pinMode(PIN_LED_BARON, OUTPUT);
	pinMode(PIN_LED_DRAGON, OUTPUT);

	//INPUTS
	pinMode(PIN_BUTTON_BLUE_0, INPUT);
	pinMode(PIN_BUTTON_BLUE_1, INPUT);
	pinMode(PIN_BUTTON_RED_0, INPUT);
	pinMode(PIN_BUTTON_RED_1, INPUT);
	pinMode(PIN_BUTTON_BARON, INPUT);
	pinMode(PIN_BUTTON_DRAGON, INPUT);

	//INITIAL STATES 
	digitalWrite(PIN_LED_BLUE_0, HIGH);
	digitalWrite(PIN_LED_BLUE_1, HIGH);
	digitalWrite(PIN_LED_RED_0, HIGH);
	digitalWrite(PIN_LED_RED_1, HIGH);
	digitalWrite(PIN_LED_BARON, HIGH);
	digitalWrite(PIN_LED_DRAGON, HIGH);
}

void loop()
{
	checkJungle(PIN_BUTTON_BLUE_0, PIN_LED_BLUE_0, timer_blue_0);
	//checkJungle(PIN_BUTTON_BLUE_1, PIN_LED_BLUE_1, timer_blue_1);
	//checkJungle(PIN_BUTTON_RED_0, PIN_LED_RED_0, timer_red_0);
	//checkJungle(PIN_BUTTON_RED_1, PIN_LED_RED_1, timer_red_1);
	//checkJungle(PIN_BUTTON_BARON, PIN_LED_BARON, timer_baron);
	//checkJungle(PIN_BUTTON_DRAGON, PIN_LED_DRAGON, timer_dragon);
}

void checkJungle(int pin_button, int pin_led, Metro timer)
{
	
	#if DEBUG
		Serial.write("pin_button: ");
		Serial.print(pin_button);
		Serial.write(" pin_led: ");
		Serial.print(pin_led);
		Serial.write(" digitalRead(pin_led): ");
		Serial.print(digitalRead(pin_led));
		Serial.write(" digitalRead(pin_button): ");
		Serial.println(digitalRead(pin_button));
	#endif
	
	if( !digitalRead(pin_led) )
	{
		if(timer.check() == 1)
		{
			Serial.write("CHECK!");
			digitalWrite(pin_led, HIGH);
		}
	}
	else if( digitalRead(pin_button) )
	{
		timer.reset();
		digitalWrite(pin_led, LOW);
	}
}