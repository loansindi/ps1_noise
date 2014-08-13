Building
=======

This sketch is built with [inotool](http://inotool.org/) - you could build and upload it using the Arduino IDE (and indeed, will have to if you're on Windows) but it will complain about the directory structure.

You will also need the [High-Low Tech](http://highlowtech.org/?p=1695) ATTiny arduino cores - these will need to go in your Arduino sketchbook according to the directions on that page.

To confirm that the cores are installed, you can type 

    $ ino list-models

Included in the output should be listings for attiny class microcontrollers.

Once you have the requirements satisfied, in /ps1_noise/noisemaker_sketch simply type:

    $ ino build -m attiny45-8

I program the microcontrollers with an Arduino loaded with ArduinoISP, typically running the avrdude command manually (you'll need to be in /noisemaker_sketch/.build/attiny45):

    $ sudo avrdude -c arduino -p t45 -P /dev/ttyACM0 -b 19200 -U flash:w:firmware.hex
