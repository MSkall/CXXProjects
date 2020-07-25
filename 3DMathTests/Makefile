main: main.o Quaternion.o Vector.o ValidateProgram.o
	g++ main.o Quaternion.o Vector.o ValidateProgram.o -o main

main.o: main.cpp
	g++ -c main.cpp

Quaternion.o: Quaternion.cpp
	g++ -c Quaternion.cpp

Vector.o: Vector.cpp
	g++ -c Vector.cpp

ValidateProgram.o: ValidateProgram.cpp
	g++ -c ValidateProgram.cpp

clean:
	rm *.o main