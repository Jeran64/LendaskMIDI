//LendaskMIDI by Jeran Halfpap 6/10/19
//A simplified project for building a MIDI controller as simple as possible.
//using a teensy 3.2, Arduino 1.8.9, and teensyduino/Teensy Loader 1.46
//TODO include a note about the sketch settings in here.

//Libraries needed. (support your local public libraries!)
#include <Bounce.h> // used for button smoooothing. (i dont really use buttons as much as i use knobs)

//Plastic Constants. feel free to change these to suit your needs

const int knobCount=16;
const int buttonCount=0; //buttons and toggles.
const int MIDI_Channel=1;
const int averageSmoothing=8;//how many values to keep in, to smooth things out. the higher, the smoother/slower the response of the knob.
const int bouncey=5;//how much the bounce time wait is. 5 is good.
const int sensitivity=1;//how big of a change we need to write data.

//crystal constants. dont change these! these are points of data based on the MIDI standard and the teensy pin layout.

const int CCOutChannel[]={20,21,22,23,24,25,26,27,28,29,30,31,52,53,54,55,56,57,58,59,60,61,62,63,102,103,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119}; // all these are undefined spots on the MIDI standard's CC list. i use the undefined ones becuase most programs worth thier salt will let you assign them whereever.
const int teensyAPins[21]={A0,A1,A2,A3,A4,A5,A6,A7,A8,A9,A10,A11,A12,A13,A14,A15,A16,A17,A18,A19,A20}; //all the analog pins on the teensy. in this program, we will for the most part, reserve ALL of them. on the teensy, these are pins 14 thru 23, and then 26 to 31. (a0 being on pin 14)
const int teensyDPins[]={0,1,2,3,4,5,6,7,8,9,10,11,12,24,25,32,33};//these are the digital pins that are not also analog pins. pay attention to that. 13 is missing as it is our debug pin.

//variables.
int previousAnalogValues[knobCount];// a list of what the values are.
int previousDigitalValues[buttonCount];
int dataGet;
bool change;

  
  
void setup() 
{
  analogReadResolution(7);//sets the scale of the pots down the to resolution we want of 0 to 127.
  analogReadAveraging(averageSmoothing*2);//sets the number of values we check and then average on the analog pins. 

  ///lastly, lets configure the digital pins to but in the correct mode.
  for(int a=0;a<buttonCount;a++)
  {
    pinMode(teensyDPins[a], INPUT_PULLUP);//turn the pin mode to the correct setting on the correct pin.
  }
  pinMode(13,OUTPUT);//get ready to make this LED blink.
}

void loop() 
{
  digitalWrite(13,LOW);//turn off.
  //handle ANALOG inputs.
  
  for(int a=0;a<knobCount;a++) //go through our list of knobby objects.
  {
    dataGet=analogRead(teensyAPins[a]);//save the pins current value.
    if(abs(previousAnalogValues[a]-dataGet)>sensitivity)//check to see if that value has changed by at least our sensitivity.
    {
      previousAnalogValues[a]=dataGet;//if it has, we need to save the new value.
      usbMIDI.sendControlChange(CCOutChannel[a],(127-dataGet), MIDI_Channel); //and then send it out if its different. we subtract becuase the knobs values are backwards.
      change=true;
    }
  }
 
  //handle DIGITAL inputs.
  for(int a=0;a<buttonCount;a++)
  {
    dataGet=digitalRead(teensyDPins[a]);//get the value of the associated pin.
    if(dataGet!=previousDigitalValues[a])//if the values dont match, theres an edge.
    {
      usbMIDI.sendNoteOn(CCOutChannel[a+knobCount], dataGet, MIDI_Channel); //send that info.
      previousDigitalValues[a]=dataGet;//save that for later.
      change=true;
    }
  }
  if(change) //we handle the LED seperately at the end, becuase if we simplify it and put the LED on in the for loop, then it causes a hardware bug where knobs later on in the for loop are dimmer than earlier ones.
  {
    digitalWrite(13,HIGH);//turn on our debug light. 
    change=false;
    //delay(5);//adding this delay will cause the led to be brighter. i like the greater range of brightness without this.
  }
}
