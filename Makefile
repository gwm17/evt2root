CC=g++
CFLAGS=-std=c++11 -c -g -Wall `root-config --cflags`
LDFLAGS=`root-config --glibs`
SOURCES=$(wildcard ./*.cpp)
OBJS=$(SOURCES:%.cpp=%.o)
EXE=evt2root

.PHONY: clean all

all: $(EXE)

$(EXE): $(OBJS)
	$(CC) $(LDFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	$(RM) $(EXE) $(OBJS)
