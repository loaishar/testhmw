CC=gcc
AR=ar
OBJECTS_MAIN=main.o
OBJECTS_LIB_REC=basicClassification.o advancedClassificationRecursion.o
OBJECTS_LIB_LOOP=basicClassification.o advancedClassificationLoop.o
FLAGS= -Wall -g
EXE=mainsrec mainsloop maindloop maindrec

#target commands
all: $(EXE)
mainsrec: $(OBJECTS_MAIN) libclassrec.a 
	$(CC) $(FLAGS) -o mainsrec $(OBJECTS_MAIN) libclassrec.a -lm
mainsloop: $(OBJECTS_MAIN) libclassloop.a 
	$(CC) $(FLAGS) -o mainsloop $(OBJECTS_MAIN) libclassloop.a -lm
maindloop: $(OBJECTS_MAIN) libclassloop.so
	$(CC) $(FLAGS) -o maindloop $(OBJECTS_MAIN) ./libclassloop.so -lm
maindrec: $(OBJECTS_MAIN) libclassrec.so
	$(CC) $(FLAGS) -o maindrec $(OBJECTS_MAIN) ./libclassrec.so  -lm
loops: libclassloop.a
loopd: libclassloop.so
recursives: libclassrec.a
recursived: libclassrec.so
#shared libs
libclassrec.so: $(OBJECTS_LIB_REC)
	$(CC) -shared -o libclassrec.so $(OBJECTS_LIB_REC)
libclassloop.so: $(OBJECTS_LIB_LOOP)
	$(CC) -shared -o libclassloop.so $(OBJECTS_LIB_LOOP)
#static libs
libclassrec.a: $(OBJECTS_LIB_REC)
	$(AR) -rcs libclassrec.a $(OBJECTS_LIB_REC)
libclassloop.a: $(OBJECTS_LIB_LOOP)
	$(AR) -rcs libclassloop.a $(OBJECTS_LIB_LOOP)
#objects
advancedClassificationRecursion.o: advancedClassificationRecursion.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationRecursion.c
advancedClassificationLoop.o: advancedClassificationLoop.c NumClass.h
	$(CC) $(FLAGS) -c advancedClassificationLoop.c
basicClassification.o: basicClassification.c NumClass.h
	$(CC) $(FLAGS) -c basicClassification.c
main.o: main.c NumClass.h  
	$(CC) $(FLAGS) -c main.c 

.PHONY: clean all

clean:
	rm -f *.o *.a *.so $(EXE)