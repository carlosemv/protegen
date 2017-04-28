# commands
CXX = g++
DEL = rm

# options
DEBUG = -g
WARNING = -Wall
OPTMIZE = -O3
STD = -std=c++11
OPTIONSCXX = $(STD) $(WARNING)


# directories
DECLRDIR = -I . -I ./include
SRCDIR = ./src/
BINDIR = ./bin/

# executable
EXEC = protegen


### executable target
main: bin main.o HeightMap.o
	$(CXX) $(BINDIR)main.o $(BINDIR)HeightMap.o -o $(EXEC) $(OPTIONSCXX)

bin:
	mkdir -p ./bin/

### (main)
main.o: $(SRCDIR)main.cpp
	$(CXX) $(SRCDIR)main.cpp -c -o $(BINDIR)main.o $(OPTIONSCXX) $(DECLRDIR)

### HeightMap
HeightMap.o: $(SRCDIR)HeightMap.cpp
	$(CXX) $(SRCDIR)HeightMap.cpp -c -o $(BINDIR)HeightMap.o $(OPTIONSCXX) $(DECLRDIR)

### clear objects & executable
clean:
	$(DEL) $(EXEC)
	$(DEL) $(BINDIR)*.o
