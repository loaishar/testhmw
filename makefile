CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB=nodes.o edges.o
FLAGS= -Wall -g
EXE= libalgo.so .graph

#target commands
all: $(EXE)
.graph: $(OBJECTS_MAIN) libalgo.so
	$(CC) $(FLAGS) -o .graph $(OBJECTS_MAIN) ./libalgo.so  -lm
#shared libs
libalgo.so: $(OBJECTS_LIB)
	$(CC) -shared -o libalgo.so $(OBJECTS_LIB)
#objects
nodes.o: nodes.c algo.h
	$(CC) $(FLAGS) -c nodes.c
edges.o: edges.c algo.h
	$(CC) $(FLAGS) -c edges.c
main.o: main.c algo.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.so $(EXE)

