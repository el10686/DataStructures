#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct node {
	int data;
	struct node *next;
} Node;

typedef struct {
	Node *root;
} Stack;

Stack *new_stack() {
	Stack *stack = malloc(sizeof(Stack));
	stack->root = NULL;
	return stack;
}

void delete_stack(Stack *stack) {
	Node *node = stack->root;

	while (node) {
		Node *tmp = node->next;
		free(node);
		node = tmp;
	}
	free(stack);
}

void stack_push(Stack *stack, int data) {
	Node *new = malloc(sizeof(Node));
	new->next = stack->root;
	new->data = data;
	stack->root = new;
}

int stack_pop(Stack *stack) {
	Node *temp = stack->root;
	int data = temp->data;
	stack->root = temp->next;
	free(temp);
	return data;
}

int stack_is_empty(const Stack *stack) {
	return !(stack->root);
}

int stack_peek(const Stack *stack){
	return stack->root->data;
}

int main() {

	int n, val;
	scanf("%d", &n);

	Stack *stack = new_stack();

	for(int i = 0; i < n; i++) {
		scanf("%d", &val);
		stack_push(stack, val);
	}

	printf("%d\n", stack_peek(stack));

	while(!stack_is_empty(stack))
		printf("%d\n",stack_pop(stack));

	delete_stack(stack);

	return 0;
}
