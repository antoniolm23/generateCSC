CFLAGS 	:= -ggdb -Wall
CC := g++
DEBUG ?= 

OBJS := generateCSC.o Random.o motes.o

all: modify_csc

modify_csc: 		$(OBJS) main.cpp
			$(CC) $(CFLAGS) $(DEBUG) $^ -o $@ 
generateCSC.o:		generateCSC.cpp
			g++ -c $(CFLAGS) $(DEBUG) generateCSC.cpp
motes.o:		motes.cpp
			g++ -c $(CFLAGS) $(DEBUG) motes.cpp

Random.o: 		Random.cpp
			g++ -c $(CFLAGS) $(DEBUG) Random.cpp
			
clean:
	rm *.o
	rm modify_csc
	rm advertising.csc
clean_obj:
	rm *.o
 
