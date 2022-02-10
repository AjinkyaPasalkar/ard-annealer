# ard-annealer
Arduino based annealer


# Code flow
1. Initialise all the modules in setup()
2. Run task for each module after specific interval.
3. Interval for each task is defined in annealer.ino. **These intervals and offsets need to be adujsted after testing**
e.g. task\_ir will be executed after every TASK\_INTV\_IR ms interval with an offset of TASK\_OFST\_IR ms

# Code details
1. Each module is divided into High Level code (aa\_modulename.ino) and Low Level Code (bb\_modulename.ino)
2. Each screen has its own struct to keep track of stae. e.g. SC1\_STATE or SC2\_STATE.
3. Pin configurations can be done by updating Pin.h file
4. To draw a screen, use tft\_draw\_scX() function, where X is screen id. e.g. tft\_draw\_sc1().
5. To draw keyboard screen use function tft\_draw\_sckey()
6. Case details like case ID, name, Time are stored in EEPROM. 1 byte for ID, 1 byte for Seconds, 1 byte for milliseconds and 20 bytes for Name so total 23 bytes per case. And details of maximum 20 cases can be stored.
7. Total cases currently in the memory is defined at location SC1\_MAX\_CASES\_ADDR
8. All screen coordinates, text, shapes etc are defined in the screen folder
9. Update TS\_MINX, TS\_MINY, TS\_MAXX, TS\_MAXY calibration values after testing

# File description
1. Annealer.ino - main file
2. PIN.h - pin configuration file
3. aa_ed.ino - Easy driver/stepper motor/motor code
4. aa_ir.ino - IR sensir code
5. aa_servo.ino - Servo motor code
6. aa_ssr.ino - Solid State Relay driving code
7. aa_task.ino - High Level code of tasks
8. aa_tft.ino - Screen printing code
9. aa_touch.ino - Touch sensor code
10. bb_tasks.ino - Low level task functions for support 
11. bb_tft.ino - Low level tft funcitons for support
12. screen.h - For including all files in screen/