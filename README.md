# Neverest-NON-CONTACT-SWITCH
Workplan,review,bill of materials,designes,schematics,code and complete implementation of the contactless switch.

## PROJECT STATEMENT
The need for safe health practices such as using sanitizers after using public amenities like taps,doors or switches is very essential to reduce  spread of COVID-19. Therefore there is an immediate need in the innovation involving touch free triggers to facilitate actions such as activating taps, doors and switches.

##TRANSFORMERLESS POWER SUPPLY
To reduce the bulk in my circuit and solve the power supply problem to my system once on PCB,I resolved to using a transformerless power supply circuit.TYhis basically uses a capacitor and a rectifier bridge to drom the AC voltage and converty it into a DC equivalent voltage respectively.

### SYSTEM COMPONENTS
-Arduino Mega 2650(ATMEGA328P chip)
-HC-SRO4 Ultrasonic sensor
-Photocell
-Relay module
-Led
-10K and 220 ohm resistors
-Jumper wires
-Breadboard

### POWER SUPPLY COMPONENTS
-Diodes(4)
-Zener diode(5.1V)
-Capacitors
    *2.2microfarad voltage drop capacitor
    *10-1000/50V micrifad filter capacitor
-Resistors
    *470K/1W bleeder resistor
    *2-100 ohms/1W resistor
    
## SPECIFICATIONS
   ### ATMEGA328P chip
   -IC type: AVR microcontroller
   -Core size: 8-bit
   -Speed: up to 20MHz
   -Number of I/O: 23
   -Program memory size: 32Kb (16K x 16)
   -Program memory type: Flash
   -EEPROM size: 1K x 8
   -RAM size: 2K x 8
   -Package: DIP-28 (0.1" x 0.3" pin spacing)
   -Supply voltage: 1.8 V - 5.5 V

   ### HC-SRO4 Ultrasonic sensor
   -Working Voltage: DC 5V
   -Working Current: 15mA
   -Working Frequency: 40Hz
   -Min Range: 2cm, Max Range: 4m
   -Measuring Angle: 15°.

   ### Photocell
   -Photocell is ½” diameter CdS (cadmium-sulfide). 
   -Universal 120-277 AC voltage (50-60Hz) is standard.
   -Preset 3 to 10 second time-delay prevents unintended switching due to momentary flashes of light. 
   -Power consumption: 2 watts.

   ### Relay module
   -Voltage supply ranges from 3.75V – 6V.
   -Quiescent current is 2mA.
   -Once the relay is active then the current is ~70mA.
   -The highest contact voltage of a relay is 250VAC/30VDC.
   -The maximum current is 10A.
