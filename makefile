# the compiler: gcc for C program, define as g++ for C++
CC = g++

# compiler flags:
#  -g  adds debugging information to the executable file
#  -Wall turns on most, but not all, compiler warnings
CFLAGS = -g -Wall -Weffc++

# the build target executable:
TARGET = Assignment1

all: $(TARGET)

# Tool invocations
# Executable "Assignment1" depends on the files roadStress.o and Assignment1.o.
$(TARGET): bin/roadStress.o bin/Assignment1.o
	@echo 'Building target: Assignment1'
	@echo 'Invoking: C++ Linker'
	$(CC) -o bin/Assignment1 bin/roadStress.o bin/Assignment1.o
	@echo 'Finished building target: Assignment1'
	@echo ' '

#Depends on the source and header files
bin/roadStress.o: src/roadStress.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/roadStress.o src/roadStress.cpp

# Depends on the source and header files 
bin/Assignment1.o: src/Assignment1.cpp
	$(CC) $(CFLAGS) -c -Linclude -o bin/Assignment1.o src/Assignment1.cpp

#Clean the build directory
clean: 
	rm -f bin/*
	rm -f RoadStress.out
