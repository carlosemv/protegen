# commands
CXX = gcc
DEL = rm

# options
DEBUG = -g
WARNING = -Wall
#STD = -std=c99
OPTIONSCXX = $(WARNING)

# directories
DECLRDIR = -I . -I ./include
SRCDIR = ./src/
BINDIR = ./bin/

#exec
EXEC = terragen


### executable target
main: bin images main.o terrain.o heights.o image.o
	$(CXX) $(BINDIR)main.o $(BINDIR)terrain.o $(BINDIR)heights.o $(BINDIR)image.o -o $(BINDIR)$(EXEC) $(OPTIONSCXX)

bin:
	mkdir -p ./bin/

images:
	mkdir -p ./images/

%.o: $(SRCDIR)%.c
	$(CXX) -c $< -c -o $(BINDIR)$@ $(OPTIONSCXX) $(DECLRDIR)

### main
main.o: $(SRCDIR)main.c
### general terrain generation
terrain.o: $(SRCDIR)terrain.c
### height array generation
heights.o: $(SRCDIR)heights.c
### printing to image
image.o: $(SRCDIR)image.c


### clear objects & executable
clean: bin
	$(DEL) $(BINDIR)$(EXEC)
	$(DEL) $(BINDIR)*.o