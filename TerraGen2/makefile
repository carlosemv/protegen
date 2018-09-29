# commands
UNAME := $(shell uname)
ifeq ($(UNAME),Darwin)
	CXX = g++-7
else
	CXX = g++
endif
DEL = rm

# options
DEBUG = -g
WARNING = -Wall
OPTMIZE = -O3
STD = -std=c++17
OPTIONSCXX = $(STD) $(WARNING)


# directories
DECLRDIR = -I . -I ./include
SRCDIR = ./src/
BINDIR = ./bin/

# executable
EXEC = terragen


### executable target
main: bin images main.o HeightMap.o
	$(CXX) $(BINDIR)main.o $(BINDIR)HeightMap.o -o $(BINDIR)$(EXEC) $(OPTIONSCXX)

bin:
	mkdir -p ./bin/

images:
	mkdir -p ./images/

### (main)
main.o: $(SRCDIR)main.cpp
	$(CXX) $(SRCDIR)main.cpp -c -o $(BINDIR)main.o $(OPTIONSCXX) $(DECLRDIR)

### HeightMap
HeightMap.o: $(SRCDIR)HeightMap.cpp
	$(CXX) $(SRCDIR)HeightMap.cpp -c -o $(BINDIR)HeightMap.o $(OPTIONSCXX) $(DECLRDIR)

### clear objects & executable
clean:
	$(DEL) $(BINDIR)$(EXEC)
	$(DEL) $(BINDIR)*.o
