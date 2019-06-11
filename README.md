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

About the code:

Make sure that you set the parameters of the code 


You will need to solder pin headers to the teensy in order to use them correctly. I chose the following configurating of my headers, to ensure that I had easy access to all the relevant pins. Since we are using female pinheaders, I reccomend using solid core wire, as it is signifigantly easier to plug into the headers, by simply stripping the ends of the wire.

The standard pins first.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_115436.jpg)

Since we must access a important number of the analog pins that are not thru-hole, I chose to solder the headers at an angle.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_115647.jpg)

And for the other side.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_120131.jpg)

Do the pins at the end. (you can see them under the teensy at the bottom)
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_121621.jpg)

As you add these headers, if you are not using pre sized headers, it may be nessicary to trim the sides before you solder to ensure a correct fit. you can see where I didnt trim them in the back, and some warping from not trimming enough.

And might as well do the last interior pins.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_121627.jpg)

Once you have the headers soldered on, it will be signifigantly easier to attach wires to it. I chose to use pin headers rather than than soldering directly to the teensy so that I could potentially reconfigure the midi controller to my needs in the future.

Now for the potentiometer bank. We are using sixteen 10k potentiometers. This board is just the test fit board. After drilling the holes with a 1/4" drill bit (and slightly widening it to allow for the screw threads) the potentiometers can be mounted in place by screwing thier nut down. This helps keep them in place while we solder them down. It helps to make sure that they are all aligned in the same direction. Once aligned, connect all your ground wires.

![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_181120.jpg)
PLEASE NOTE: I soldered mine on backwards. But that's okay, I fixed that after-the-fact in code.

Now we connect all the red wires to carry the 3.3v. You can connect them all together. Note that I forgot to solder the red columns together before taking this picture.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_184025.jpg)

Now to attach the data wires to the middle pins of the potentiometers. I used a different color for each column for clairty.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_185205.jpg)

Now its as simple as plutting the wires in. Make sure that you plug your analog device ground into the AGND pin, not the GND. It will provide a less noisy experience. Plug your hot wire into the 3.3v, and then start plugging your knobs into the teensy. Start plugging the analog inputs in at A0, and go in order. Plugging in the digital pins involves doing them in this order: 0,1,2,3,4,5,6,7,8,9,10,11,12,24,25,32,33
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190604_192729.jpg)

Once that the code is uploaded, and tested to be working, I moved the setup to a final housing. a simple box I found at a local craft store for 4$. Using a compass and straight edge, I found the exact points to drill the holes in the center.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190610_185350.jpg)

I chose not to sand or stain my box, because I didnt feel like it. Painting, sealing, or varnishing the box will go a long way for its visual longevity, so I do reccomend it, even if I didnt do it.

After reinstalling the potentiometer array, 2 more holes were drilled. One with the box closed on the seam, to allow space for the USB cord to exit the box. Then an LED was added to the middle at the top as an indicator. This LED is connected to ground and pin 13. I did not include a resistor because it's already only 3.3 volts.
![My image](https://github.com/Jeran64/LendaskMIDI/blob/master/Photos/IMG_20190610_202011.jpg)

It's done. I like to use this device with FLStudio.

