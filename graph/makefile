# binary search tree

TARGET=dfs bfs topsort

all: $(TARGET)

dfs: graph.c dfs.c
	g++ -g -O0 -o $@ $?

bfs: graph.c bfs.c
	g++ -g -O0 -o $@ $?

topsort: graph.c topsort.c
	g++ -g -O0 -o $@ $?

clean:
	rm -rf $(TARGET) a.out

