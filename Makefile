hw1: main.o data.o
	g++ main.o data.o -o hw1

main.o: hw1.cpp
	g++ -c hw1.cpp -o main.o

data.o: data.cpp data.h
	g++ -c data.cpp -o data.o

clean:
	rm hw1 *.o


