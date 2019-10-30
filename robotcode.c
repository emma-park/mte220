#include "mte220.c"

void main(void) {

	Initialization();

    // both servos are turned on
    UseServos         // (syntax of "call" is correct without () or ;)


    while (1)
    {
        WaitForButton();  // wait until the button is pushed

        // turn on the servos
        BothServosOn

		//motion depends on line following lab
		//while( not at end of line... condition??)
			//line following algorithm
			//if detect magnet, delay for 7 seconds, blink LED according to polarity
		//
		
       
    }
}

void magnetSensor() {
	uns8 analog_value;  // current ADC value

    while (1)  // loop forever
    {
        // get analog value from the Hall effect sensor
        analog_value = AnalogConvert(ADC_HALL_EFFECT);

		//check if magnetic is nearby and what polarity. 0x93 based on 2.9V opamp output
		//TODO: Figure out what range the opamp will output when there is no magnet or a magnet is too far away
		if (analog_value < 0x93) {// negative polarity
			int i = 0;
			while(i<56) {// TODO check that Delay() is in milliseconds
				OnLED
				LongDelay(2);
				OffLED
				LongDelay(2);
				i += 4;
			}
			OffLED
		}
		else if (analog_value > 0x93) {
			//turn on LED for 7 seconds
			OnLED
			LongDelay(56);
			OffLED
		}
    }
	//Add a delay after you find a magnet to ensure that you are far enough away that you dont detect the same one
}