# LendaskMIDI
Lendask MIDI is a tutorial that reflect my own journey for a simple and elegant way of making my own USB MIDI controller. 

Lendask is intended to be flexible, cheap, and easy to make.

###################

Lendask uses:

teensy 3.2

Arduino IDE 1.8.9

teensyduino/Teensy Loader 1.46

up to 21 knobs/faders 

up to 16 buttons


###################

Additional Materials:

Wires (solid core is great)

PCB Female Pin Headers

Solder and Soldering Iron

Wire Stripper

Sturdy Case

Drill with Bits

microUSB cable

To give you an estimate on price, if you also have to buy the tools, you are looking at around 70$

#############################

First thing is first, make sure that you can upload code to your teensy. a common problem is that the micro USB cable you are using is actually a charging only cable, not a data cable. I too encountered this common problem.


You will need to solder pin headers to the teensy in order to use them correctly. I chose the following configurating of my headers, to ensure that I had easy access to all the relevant pins.

The standard pins first.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_115436.jpg)

Then to access a important number fo the analog pins, I chose to solder the headers at an angle.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_115647.jpg)

And for the other side.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_120131.jpg)

Do the pins at the bottom.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_121621.jpg)

as you add these headers, if you are not using pre sized headers, it may be nessicary to trim the sides before you solder to ensure a correct fit. you can see where I didnt trim them in the back, and some warping from not trimming enough.

And might as well do the last interior pins.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_121627.jpg)

Once you have the headers soldered on, it will be signifigantly easier to attach wires to it. I chose to use pin headers rather than than soldering directly to the teensy so that i could potentially reconfigure the midi controller to my needs in the future.
