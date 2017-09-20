clean :
	del *.obj
	del *.exe
	del *.lib
	
cl:
	cl /c LinkedList.cpp test.cpp
	
lib: 
	lib LinkedList.obj

link:
	link test.obj LinkedList.lib
	
all:
	cl test.cpp LinkedList.cpp 
	
