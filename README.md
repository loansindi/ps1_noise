Noise-O-Tron
==========
![Image of assembled unit](https://raw.githubusercontent.com/loansindi/ps1_noise/master/images/recent_revision.jpg)

A small, cheap (~$5/piece if you build 100 at a time) optical theremin that can be assembled with no soldering.

The idea is to fabricate a custom perfboard from acrylic, heavy cardstock or other suitable material.
Components are pushed through the top of this perfboard and the leads are twisted together to form a circuit.

I've been using laser-cut acrylic, but anything from CNC routing to an inkjet printer should be sufficient (I think heavy cardstock + hole punch would be very cool)

Making the Boards
=========

There are several SVG files in this repository. laser_cut_board_paths.svg has had all objects converted to paths and should be ready to import into whatever vector graphics program you use.

laser_cut_board_source.svg is an inkscape SVG with text as text objects - use this one to spin your own version of the board.

![Board Art](https://raw.githubusercontent.com/loansindi/ps1_noise/master/laser_cut_board.png)

I cut my boards on an Epilog Mini30 laser engraver. Any similar CO2 laser would work just as well. This SVG is set up for correct cut/raster behavior in the Epilog print driver - tweaks may be required for other machines.

Other methods that might be worth investigating are CNC routers and even inkjet printers (Cardstock + hole punch!).

Prep work
=========

One of the first obvious problems is how to get the legs of the IC through the board so they can be twisted. This is currently solved with a wire-wrap DIP socket. There are three unused pins on the IC (pins 1, 4 and 5) and these pins should be trimmed on the sockets so they're not in the way. Wear your eye protection!

Programming the microcontrollers benefits from a ZIF socket - I like to have the circuit built on a breadboard/protoboard around the socket, so as each chip is programmed the functionality is instantly verified. I program the microcontrollers by calling avrdude directly and uploading the compiled hex file. This is much faster than using the Arduino IDE, which compiles each time you press upload.

ToDo
=========

1. Create info card
    * Page with information on 'how to' noisemaker 
    * github link
    * Materials - costs, sourcing, prep work
    * photos or diagrams of process?
    * hand these mofos out at every event to get other people using the noisemaker
2. Create assembly photo series
    * Just a photo of each step - to live in the repo to simplify assembly for others using the project
