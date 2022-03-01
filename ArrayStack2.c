#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_STRING 100

typedef struct {
	int student_no;
	char name[MAX_STRING];
	char address[MAX_STRING];
}element;

element stack[MAX_STACK_SIZE];

int top = -1;

int is_empty() {
	return (top == -1);
}

int is_full() {
	return (
		top == (MAX_STACK_SIZE - 1));
}

void push(element item) {
	if (is_full()) {
		fprintf(stderr, "스택 포화 에러\n");
		return;
	}
	else {
		stack[++top] = item;
	}
}

element pop() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return stack[top--];
	}

}

element peek() {
	if (is_empty()) {
		fprintf(stderr, "스택 공백 에러\n");
		exit(1);
	}
	else {
		return stack[top];
	}
}

void main() {

	element ie, oe;
	strcpy(ie.name, "킹우현");
	strcpy(ie.address, "동탄신도시");

	ie.student_no = 201820734;

	push(ie);

	oe = pop();

	printf("name: %s\n", oe.name);
	printf("address: %s\n", oe.address);
	printf("student number: %d\n", oe.student_no);

}