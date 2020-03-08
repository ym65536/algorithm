# graph

TARGET=main

all: $(TARGET)

main: main.cc graph.cc
	g++ -std=c++0x -g -O0 -o $@ $?

#topsort: graph.c topsort.c
#	g++ -g -O0 -o $@ $?

clean:
	rm -rf $(TARGET) a.out

