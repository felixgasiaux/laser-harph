Hello to the cluster fuck that is this laser harph...

the .ino file is all you need to get it working as well as some device which can recieve midi notes over usb. For that I use MiniDexed[https://github.com/probonopd/MiniDexed] in theory a simple plug and play system.

Uploade the .ino file onto the Teensy lc, keep in mind you need to install the board first in arduino if it's your first time using a teensy. here are the instructions. [https://www.pjrc.com/teensy/td_download.html]

Open the .ino in arduino IDE, select the teensy-lc under boards and configure the correct port. BEFORE Flashing you need to go to tools -> USB TYPE and select MIDI ,else you will get an error.

Then FLASH !


You should now be able to simply plug the teensy via an micro USB cable (be sure that it transfers DATA !!! ) into the raspberry with the correct os on the sd and power everthing on.


The code is not final but should work to my understanding of things... 


A decent schematic will folllow as well as more details... 
Thank you to Gunstick for putting the work in when I am busy. 
