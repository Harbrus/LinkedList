# Instructions

Files:   LinkedList.cpp, test.cpp and linked_list
Author: Andrea Silvestro Ortino
Last modified 24/03/2017
Implements the LinkedList class.
Tools Used: Microsoft Visual Studio 2015 and Developer Command Prompt VS2015.

A makefile is provided in the archive as a support in the compiling of the programme. 
It has different command to be used in the  as showed below:

"nmake clean" - deletes every obj, lib and exe file from the directory.
"nmake cl" - creates obj files of test.cpp and LinkedList.cpp.
"nmake lib" - transforms the LinkedList.cpp file into a lib file.
"nmake link" - links together test.obj and LinkedList.lib, creating test.exe ready to be executed by typing "test" on the command prompt.
"nmake all" - can be used for skipping the creation of the library and building everything together at once.

In order to run the programme, it is possible either to use nmake all or to first run the "nmake cl", then creates the library with "nmake lib", then
links together the obj file and the lib with "nmake link", and finally run the tool with "test" or "test.exe" (calls to be made without the quotes " ").
