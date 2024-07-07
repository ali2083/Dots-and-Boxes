Install and run
prerequisites:
Compiler: minGW32 installed from https://sourceforge.net/projects/mingw-w64/
Standard: C++11

Run:
1- Open the terminal in the project path
2- Ensuring the existence of the g++ compiler with the command
g++
The desired result
g++.exe: fatal error: no input files
compilation terminated.
The non-display can be due to not installing correctly or not adding the compiler to the path
More information at https://code.visualstudio.com/docs/cpp/config-mingw
3- Command to compile the program with
g++ .\main.cpp .\basic.cpp .\game.cpp -o .\run\dots_and_boxes.exe
By executing this command, the output file is created for us in the run folder
4- You can export the file from file explorer or with commands
cd run
dots_and_boxes.exe
performed