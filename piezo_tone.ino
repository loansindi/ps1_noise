// Crappy piezo optical theremin. Depends on attiny85 arduino hardware files.

void setup() {
	pinMode(0, OUTPUT);
	pinMode(1, OUTPUT);
	pinMode(2, INPUT);
}


unsigned int pitch = 40;

void loop() {
	int pitch = 5 * analogRead(1);
	beep (0, 1, pitch, 50); // piezo is connected to two outputs that switch differentially for greater volume
	//changing the fourth argument of this function changes the 'quantization' effect of the generated tone.


}
  void beep (unsigned char speakerPin, unsigned char speakerPin2, int frequencyInHertz, long timeInMilliseconds)
{	 // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html
          int x;	 
          long delayAmount = (long)(1000000/frequencyInHertz);
          long loopTime = (long)((timeInMilliseconds*1000)/(delayAmount*2));
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
