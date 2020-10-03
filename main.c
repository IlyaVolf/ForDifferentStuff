#include <stdio.h>

#include <stdlib.h>

#include <string.h>

typedef struct Node_s {
	const char* str;
	const struct Node_s* next;
} Node;

const Node* head = NULL;
Node* tail = NULL;

const Node* createNode(const char* string, const int stringLength) {
	Node* newNode = (const Node*)malloc(sizeof(const Node));

	newNode->str = (const char*)malloc(stringLength);
	strcpy(newNode->str, string);
	newNode->next = NULL;

	return newNode;
}

const void appendNode(const char* string, const int stringLength) {
	const Node* newElem = createNode(string, stringLength);

	tail->next = newElem;
	tail = newElem;
}

const void printList() {
	printf("The result is:\n");

	const Node* current = head;

	while (current != NULL) {
		printf("%s", current->str);
		current = current->next;
	}
}

const void deleteList() {
		const Node* current = head;
		const Node* previous;

		while (current != NULL) {
			free(current->str);
			previous = current;
			current = current->next;
			free(previous);
		}
	}

const int main() {
	const char string[10000];
	int stringLength;

	fgets(string, 10000, stdin);
	stringLength = strlen(string) + 1;

	while (string[0] != '.') {
		if (head == NULL) {
			const Node* newElem = createNode(string, stringLength);
			head = newElem;
			tail = newElem;
		}
		else {
			appendNode(string, stringLength);
		}

		fgets(string, 10000, stdin);
		stringLength = strlen(string) + 1;
	}

	printList();
	deleteList();

	return 0;
}
