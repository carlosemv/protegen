# commands
CXX = gcc
DEL = rm

# options
DEBUG = -g
WARNING = -Wall
#STD = -std=c99
OPTIONSCXX = $(WARNING)
# $(STD)

# directories
DECLRDIR = -I . -I ./include
SRCDIR = ./src/
BINDIR = ./bin/

#exec
EXEC = main


### executable target
main: main.o terrain.o heights.o image.o
	$(CXX) $(BINDIR)main.o $(BINDIR)terrain.o $(BINDIR)heights.o $(BINDIR)image.o -o $(EXEC) $(OPTIONSCXX)

### main
main.o: $(SRCDIR)main.c
	$(CXX) $(SRCDIR)main.c -c -o $(BINDIR)main.o $(OPTIONSCXX) $(DECLRDIR)

### general terrain generation
terrain.o: $(SRCDIR)terrain.c
	$(CXX) $(SRCDIR)terrain.c -c -o $(BINDIR)terrain.o $(OPTIONSCXX) $(DECLRDIR)

### height vector generation
heights.o: $(SRCDIR)heights.c
	$(CXX) $(SRCDIR)heights.c -c -o $(BINDIR)heights.o $(OPTIONSCXX) $(DECLRDIR)

### image
image.o: $(SRCDIR)image.c
	$(CXX) $(SRCDIR)image.c -c -o $(BINDIR)image.o $(OPTIONSCXX) $(DECLRDIR)


### clear objects & executable
clean:
	$(DEL) ./main
	$(DEL) $(BINDIR)*.o