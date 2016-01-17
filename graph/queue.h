#ifndef __ALGORITHM_QUEUE_H
#define __ALGORITHM_QUEUE_H

struct queue
{
	unsigned int data[MAX_NODE];
	int front;
	int rear;
};

static void queue_init(struct queue* q)
{
	memset(q->data, 0, sizeof(q->data));
	q->front = q->rear = 0;
}

static int queue_empty(struct queue* q)
{
	return (q->rear == q->front);
}

static int queue_in(struct queue* q, unsigned int* x)
{
	if ((q->rear + 1) % MAX_NODE == q->front)
	{
		printf("queue is full!\n");
		return -1;
	}
	q->data[q->rear] = *x;
	q->rear = (q->rear + 1) % MAX_NODE;
	return 0;
}

static int queue_out(struct queue* q, unsigned int* x)
{
	if (q->rear == q->front)
	{
		printf("queue is empty!\n");
		return -1;
	}
	*x = q->data[q->front];
	q->front = (q->front + 1) % MAX_NODE;
	return 0;
}

#endif

