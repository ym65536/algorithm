# binary search tree

TARGET=dfs bfs

all: $(TARGET)

dfs: graph.c dfs.c
	g++ -g -O0 -o $@ $?

bfs: graph.c bfs.c
	g++ -g -O0 -o $@ $?

clean:
	rm -rf $(TARGET) a.out

