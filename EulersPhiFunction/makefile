#Compilador:
CC=g++
CDEBUGGER=gdb
CFLAGS=-Wall -Wextra
COPTFLAG=-O2
DEBUGFLAG=-g
SOURCE=funcPhiEuler.cpp
EXEC=funcPhiEuler

all: $(EXEC)

$(EXEC):
	$(CC) $(SOURCE) $(CFLAGS) $(COPTFLAG) -o $(EXEC)

debug:
	$(CC) $(SOURCE) $(CFLAGS) $(COPTFLAG) $(DEBUGFLAG) -o $(EXEC)
	$(CDEBUGGER) $(EXEC)
	make clean
run:
	$(CC) $(SOURCE) $(CFLAGS) $(COPTFLAG) -o $(EXEC)
	./$(EXEC)
	make clean	
clean:
	rm $(EXEC)
