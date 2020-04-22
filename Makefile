CC = g++
OP = Rasterizer
CFLAGS = -c

all: main.o Cartesian2.o vector2.o ppmgenerator.o
	$(CC) main.o Cartesian2.o vector2.o ppmgenerator.o -o $(OP)

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

Cartesian2.o: Cartesian2.cpp
	$(CC) $(CFLAGS) Cartesian2.cpp Cartesian2.h

vector2.o:
	$(CC) $(CFLAGS) vector2.cpp vector2.h

ppmgenerator.o:
	$(CC) $(CFLAGS) ppmgenerator.cpp ppmgenerator.h

clean:
	rm -rf *o $(OP)
