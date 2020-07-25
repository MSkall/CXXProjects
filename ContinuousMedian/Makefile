#declare the variable
QMAKE_CXXFLAGS += -Wno-c++11-extensions
CXXFLAGS ?= -std=c++11
CC = g++
CFLAGS = -c -Wall
CFLAGG = -Wall -g

all:

#g++ -std=c++11 -o median continousmedian.cpp
median: continousmedian.o
	$(CC) $(CFLAGG) -o median continousmedian.o
continousmedian.o: continousmedian.cpp heap_template.h
	$(CC) $(CFLAGG) -c continousmedian.cpp

# g++ -std=c++11 -o airport flights_available.cpp 
flights: flights_available.o
	$(CC) flights_available.o -o flights
flights_available.o: flights_available.cpp
	$(CC) $(CXXFLAGS) $(CFLAGS) $(QMAKE_CXXFLAGS) flights_available.cpp

#g++ -std=c++11 -o notrepeat firstNonRepeatingCharacter.cpp
notrepeat: firstNonRepeatingCharacter.o
	$(CC) firstNonRepeatingCharacter.o -o notrepeat
firstNonRepeatingCharacter.o: firstNonRepeatingCharacter.cpp
	$(CC) $(CXXFLAGS) $(CFLAGS) $(QMAKE_CXXFLAGS) firstNonRepeatingCharacter.cpp

clean:
	rm -rf *o flights median notrepeat

# generic makefile
# # this target will compile all the files
# all:

# # type 'make hw8' to compile just hw8 files
# hw8:
# 	g++ hw7.cpp -o hw8

# hw7:
# 	g++ hw7.cpp -o hw7

# oral_exam:
# 	g++ oral_exam.cpp -o oral_exam

# # if you had a program that took multiple files to run the main program
# main: main.o helper1.o helper2.o
# 	g++ main.o helper1.o helper2.o -o main
# # then create .o targets for each file
# # target: dependency
# 	# commmand
# helper1.o: helper1.cpp
# 	g++ -c helper1.cpp #-c means 'compile'

# clean:
# 	rm -rf *o hw8 hw7 oral_exam
