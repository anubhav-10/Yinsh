IDIR =./include 
CXX=g++ 
CC=gcc
CXXFLAGS= -I$(IDIR) -g -std=c++11 -w

SRCDIR=./src
ODIR=./obj
TARGET=./main

_DEPS = game.h

DEPS = $(patsubst %,$(IDIR)/%,$(_DEPS))

_OBJ = game.o main.o
OBJ = $(patsubst %,$(ODIR)/%,$(_OBJ))


$(ODIR)/%.o: $(SRCDIR)/%.cpp 
	@mkdir -p $(ODIR)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

$(TARGET): $(OBJ)
	@echo "\n Linking ...." 
	g++ -o $@ $^ $(CXXFLAGS)


.PHONY: clean

clean:
	@echo "Cleaning ....";
	rm -rf $(ODIR) 