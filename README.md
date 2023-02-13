# Brainfuck
Brainfuck interpreter

# Version history
## Version 1.0
* February 10 2023

The default brainfuck program given prints out "HELLO WORLD". If you want to use another program, change the value of bf to the code of your program.
When run it simply executes the brainfuck program and does nothing else.

## Version 1.1
* February 12 2023

Info on running program same as 1.0

Changes:
* Added comments to code
* Increased memory size to standard value of 30,000
* Added segmentation fault code for when it tries to access memory out of bounds

## Version 1.1.1
* February 12 2023

Changes:
* Cleaned up code
* Removed the outputting of the current memory value in the out of bounds checker
* Removed redundant end-of-file check because there's already one in the switch statement
