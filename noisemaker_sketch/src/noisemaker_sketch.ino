/* This is a project by Derek Bever with the goal of creating a small, inexpensive electronic widget
   that is easy to assemble for someone with limited electronics experience. The physical form of the 
   project as a whole is a 2"x2" laser-cut acrylic/wood/cardstock perfboard. Components are inserted
   through the holes in the board and the leads are twisted together
   
   This firmware drives the project on an ATTiny 25/45/85 (compiled size is approximately 1.3k, so it
   will run handily on any of these. The 45 was cheapest at the time I first buil these.
   
   https://github.com/loansindi/ps1_noise
   
   Arduino cores here: http://highlowtech.org/?p=1695
   
   All assets of this project are licensed under Creative Commons BY-SA 4.0
*/
   


// Crappy piezo optical theremin. Depends on attiny85 arduino hardware files.

#include <math.h>

void setup() {
        pinMode(4, OUTPUT); // We use pins 0 and 1 as differential outputs for the piezo buzzer
        pinMode(3, OUTPUT); // this offers improved loudness compared to a single pin
        pinMode(1, INPUT);  // pin 1 is our ADC input - reading the voltage divider formed by the photoresistor and regular resistor
}


unsigned int pitch;

void loop() {
        pitch = analogRead(1)/10;
        beep (3, 4, pitch, 5);

        // This function takes three arguments, as copied from the internet
        // the first argument is the pin to generate a tone on - this should be refactored out for this purpose
        // the second argument is added by me - it's the second pin for differential switching to increase volume
        // the third argument is the target frequency, and the 4th determines the length of the tone
        // changing the fourth argument of this function changes the 'quantization' effect of the generated tone.
        // shorter lengths produce a glissando effect, longer lengths create a distinct series of steps
}

void beep (unsigned char speakerPin, unsigned char speakerPin2, int frequency, long timeInMilliseconds) {
        // http://web.media.mit.edu/~leah/LilyPad/07_sound_code.html

        int frequencyNumerator = 4000; //this variable determines the general range of noise - higher numbers result in a lower frequency range
        int delayMultiplier = 100; //this variable determines how long beep() runs before returning to loop(). higher values produce more audibly 'stepped' noise - set just right you can get some cool glissando effects

        int x;	 
        long delayAmount = (long)(frequencyNumerator/frequency);
        long loopTime = (long)((timeInMilliseconds*delayMultiplier)/(delayAmount));
        
        for (x=0;x<loopTime;x++) {	 
                digitalWrite(speakerPin,HIGH);
                digitalWrite(speakerPin2, LOW);
                delayMicroseconds(delayAmount);
                digitalWrite(speakerPin,LOW);
                digitalWrite(speakerPin2, HIGH);
                delayMicroseconds(delayAmount);
        }	   
}
