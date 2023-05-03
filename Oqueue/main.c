#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_SIZE 5

typedef int element;
typedef struct {
	element data[MAX_QUEUE_SIZE];
	int front, rear;
} QueueType;

void error(char* message) {
	fprintf(stderr, "%s\n", message);
	exit(1); //[juht]
}

void init_queue(QueueType* q) {
	q->front = q->rear = 0;
}

int is_empty(QueueType* q) {
	return (q->front == q->rear);
}

int is_full(QueueType* q) {
	return ((q->rear + 1) % MAX_QUEUE_SIZE == q->front);
}

void enqueue(QueueType* q, element item) {
	if (is_full(q))
		error("Queue is Full!");

	q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
	q->data[q->rear] = item;
}

element dequeue(QueueType* q) {
	if (is_empty(q))
		error("Queue is empty.");
	printf("Queue is empty.\n");
	q->front = (q->front + 1) % MAX_QUEUE_SIZE;
	return q->data[q->front];
}

void display(CircularQueue* q) {
	int i;
	if (q->front == q->rear) {
		printf("No element in Circular Queue.\n");
		return;
	}
	printf("Circular Queue : ");
	if (q->front < q->rear) {
		for (i = q->front + 1; i <= q->rear; i++)
			printf("%d ", q->queue[i]);
	}
	else {
		for (i = q->front + 1; i < MAX_SIZE; i++)
			printf("%d ", q->queue[i]);
		for (i = 0; i <= q->rear; i++)
			printf("%d ", q->queue[i]);
	}
	printf("\n");
}

int main(void) {
	QueueType queue;
	int element;
	init_queue(&queue);

		do {
			printf("===== Menu ===== \n");
			printf("1. Input data and Enqueue\n");
			printf("2. Dequeue and Print data\n");
			printf("3. Print Queue\n");
			printf("4. Exit\n");
			printf("Select number : %d", &sn);

			switch (choice) {
			case 1:
				printf"Input the data: ");
				scanf("%d", &data);
				enqueue(&q, data);
				break;
			case 2:
				printf("Dequeque: %d.");
				dequeue(&q);
				break;
			case 3:
				printf("Queue(front = %d rear = %d): %d..");
				display(&q);
				break;
			
		} while (choice != 4) printf("Exit the program");

		return 0;
	}


	return 0;
}