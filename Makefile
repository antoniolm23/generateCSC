CFLAGS 	:= -ggdb -Wall
CC := g++
DEBUG ?= 

OBJS := generateCSC.o Random.o advertiserList.o

all: modify_csc

modify_csc: 		$(OBJS) main.cpp
			$(CC) $(CFLAGS) $(DEBUG) $^ -o $@ 
generateCSC.o:		generateCSC.cpp
			g++ -c $(CFLAGS) $(DEBUG) generateCSC.cpp
advertiserList.o:	advertiserList.cpp
			g++ -c $(CFLAGS) $(DEBUG) advertiserList.cpp

Random.o: 		Random.cpp
			g++ -c $(CFLAGS) $(DEBUG) Random.cpp
			
clean:
	rm *.o
	rm modify_csc
clean_obj:
	rm *.o
 
