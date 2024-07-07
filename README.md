#2 Install and run
To run the program you need to 
#4 prerequisites:
Compiler: minGW32 installed from [here](https://sourceforge.net/projects/mingw-w64/)
Standard: C++11

#4 Run:
1. Open the terminal in the project path
2. Ensuring the existence of the g++ compiler with the command
```terminal
g++
```
The desired result
```terminal
g++.exe: fatal error: no input files
compilation terminated.
```
The non-display can be due to not installing correctly or not adding the compiler to the path
More information at [here](https://code.visualstudio.com/docs/cpp/config-mingw)
4. Command to compile the program with
```terminal
g++ .\main.cpp .\basic.cpp .\game.cpp -o .\run\dots_and_boxes.exe
```
By executing this command, the output file is created for us in the run folder
5. You can export the file from file explorer or with commands
```terminal
cd run
dots_and_boxes.exe
```
performed

#2 note:
[^1]: This project is related to the programming course of IUST University, 7/8/2024
