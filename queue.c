#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct {
	Node *front, *back;
} Queue;

Queue *new_queue() {
	Queue *queue = malloc(sizeof(Queue));
	queue->back = queue->front = NULL;
	return queue;
}

void delete_queue(Queue *queue) {
	Node *node = queue->front;

	while (node) {
		Node *temp = node->next;
		free(node);
		node = temp;
	}
	free(queue);
}

void queue_enqueue(Queue *queue, int data) {
	Node *new = malloc(sizeof(Node));
	new->data = data;
	new->next = NULL;

	if (!queue->back) {
		queue->back = queue->front = new;
		return;
	}

	queue->back->next = new;
	queue->back = new;
}

int queue_dequeue(Queue *queue) {
	Node *new = queue->front;
	int data = new->data;
	queue->front = queue->front->next;
	free(new);

	if (!queue->front)
		queue->back = queue->front;

	return data;
}

int peek_back(Queue *queue) {
	return queue->back->data;
}

int peek_front(Queue *queue) {
	return queue->front->data;
}

int queue_is_empty(Queue *queue) {
	return !queue->front;
}

int main() {

	int n, *nodes;

	scanf("%d", &n);

	nodes = malloc(sizeof(int) * n);

	for(int i = 0; i < n; i++)
		scanf("%d", &nodes[i]);

	Queue *queue = new_queue();

	for(int i = 0; i < n; i++) {
		printf("Is queue empty? : " );
		printf(queue_is_empty(queue) ? "yes\n" : "no\n");
		queue_enqueue(queue, nodes[i]);
		printf("%d entered queue\n", nodes[i]);
		printf("Queue front : %d\n", peek_front(queue));
		printf("Queue back : %d\n", peek_back(queue));
	}

	while (!queue_is_empty(queue)) {
		printf("Is queue empty? : " );
		printf(queue_is_empty(queue) ? "yes\n" : "no\n");
		printf("Queue front : %d\n", peek_front(queue));
		printf("Queue back : %d\n", peek_back(queue));
		printf("%d dequeued\n", queue_dequeue(queue));
	}

	printf("Is queue empty? : " );
	printf(queue_is_empty(queue) ? "yes\n" : "no\n");

	delete_queue(queue);

	return 0;
}
