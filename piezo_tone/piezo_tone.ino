// Crappy piezo optical theremin. Depends on attiny85 arduino hardware files.

void setup() {
	pinMode(4, OUTPUT); // We use pins 0 and 1 as differential outputs for the piezo buzzer
	pinMode(3, OUTPUT); // this offers improved loudness compared to a single pin
	pinMode(2, INPUT);  // pin 2 is our ADC input - reading the voltage divider formed by the photoresistor and regular resistor
  pinMode(1, INPUT);
}


unsigned int pitch = 40;

void loop() {
//	int pitch = 5 * analogRead(1); //the 10 bit ADC produces a number 0-1023, so our frequency range is 0-5115 in 5hz increments
	pitch = 10 * analogRead(1);
  beep (3, 4, pitch, 5);

	// This function takes four arguments, as copied from the internet
  // the first argument is the pin to generate a tone on - this should be refactored out for this purpose
  // the second argument is added by me - it's the second pin for differential buzzing
  // the third argument is the target frequency, and the 4th determines the length of the tone
  // changing the fourth argument of this function changes the 'quantization' effect of the generated tone.
  // shorter lengths produce a glissando effect, longer lengths create a distinct series of steps

}
  void beep (unsigned char speakerPin, unsigned char speakerPin2, int frequencyInHertz, long timeInMilliseconds)
{	 // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
          int x;	 
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount));
          for (x=0;x<loopTime;x++)	 
          {	 
              digitalWrite(speakerPin,HIGH);
	      digitalWrite(speakerPin2, LOW);
              delayMicroseconds(delayAmount);
              digitalWrite(speakerPin,LOW);
	      digitalWrite(speakerPin2, HIGH);
              delayMicroseconds(delayAmount);
          }	   
}
