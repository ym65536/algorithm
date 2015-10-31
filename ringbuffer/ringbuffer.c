#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER_SIZE 0x10
#define START   -1
#define END     -2
#define EMPTY    0

struct ringbuffer
{
    unsigned int* buffer;
    unsigned int size;
    unsigned int in;
    unsigned int out;
};

int rb_init(struct ringbuffer* fifo, unsigned int size)
{
    fifo->buffer = (int* )malloc(sizeof(int) * size);
    if (fifo->buffer == NULL)
        return -1;
    memset(fifo->buffer, 0, sizeof(int) * size);
    fifo->size = size;
    fifo->in = fifo->out = 0;
    return 0;
}

int rb_full(struct ringbuffer* fifo)
{
    return ((fifo->in + 1) & (fifo->size - 1)) == ((fifo->out) & (fifo->size - 1));
}

int rb_empty(struct ringbuffer* fifo)
{
    return (fifo->in == fifo->out);
}

int rb_put(struct ringbuffer* fifo, int data)
{
    if (rb_full(fifo))
        return -1;
    fifo->buffer[fifo->in & (fifo->size - 1)] = data;
    fifo->in++;
    return 0;
}

int rb_get(struct ringbuffer* fifo, int* data)
{
    if (rb_empty(fifo))
        return -1;
    *data = fifo->buffer[fifo->out & (fifo->size - 1)];
    fifo->out++;
    return 0;
}

void rb_print(struct ringbuffer* fifo)
{
    int i = 0;
    printf("out: %u, in:%u\n", fifo->out, fifo->in);
    for (i = 0; i < fifo->size; i++)
    {
        printf("%d ", fifo->buffer[i]);
    }
    printf("\n");
}

int main(void)
{
    struct ringbuffer fifo;
    int i = 0;

    rb_init(&fifo, BUFFER_SIZE);
    for (i = 0; i <= fifo.size; i++)
    {
        if (rb_put(&fifo, i) < 0)
        {
            printf("fifo is full!\n");
        }
    }
    rb_print(&fifo);

    for (i = 0; i <= BUFFER_SIZE; i++)
    {
        int data;
        if (rb_get(&fifo, &data) < 0)
        {
            printf("fifo is empty!\n");
        }
        else
        {
            printf("get data:%d\n", data);
        }
    }
    rb_print(&fifo);

    return 0;
}
