# Name: Mark Redekopp
# email: redekopp@usc.edu

CC = g++
CFLAGS = -g -Wall
LDFLAGS =
SRCS =  lab-draw.cpp bmplib.cpp
OBJ = $(SRCS:.cpp=.o)
DEMOSRC = demo.cpp bmplib.cpp
DEMOOBJ = $(DEMOSRC:.cpp=.o)



all: lab-draw demo

demo: $(DEMOOBJ)
	$(CC) $(CFLAGS) $(DEMOOBJ) -o demo
lab-draw: $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o lab-draw

.cpp.o:
	$(CC) $(CFLAGS) -c $<

bmplib.o : bmplib.h

clean:
	rm -f *.o lab-draw *~

