# Guitar-Pickup-Winder-with-Arduino
A prototype Arduino code for winding the coil bobbin

Requirements:
- ULN2003 stepper motor with 28BYJ-48 gear
- Potentiometer
- Arduino UNO

The stepper motor has 8 modes for rotating clockwise and counter-clockwise. Firing positions for the rotations are similarly given as:
- 1,0,0,0 (North) 
- 1,1,0,0 (North-East)
- 0,1,0,0 (East)
- 0,1,1,0 (South-East)
- 0,0,1,0 (South)
- 0,0,1,1 (South-West)
- 0,0,0,1 (West)
- 1,0,0,1 (North-west)

The motor excutes the firing procedure forward until reached desired rotation, then changes its direction to wind the bobbin backwards. 
Rotations are predefined by calculating the the diameter of the wire and the length of the bobbin.

Potentiometer controls the speed of the rotation in real-time.

EEPROM library is added to write in the memory of Arduino UNO. Rotation number and the direction is saved in the memory to continue the wiring. 
This will helps in such cases as, ability to stop it and adjust wires by hand and continue wiring autonomously.
