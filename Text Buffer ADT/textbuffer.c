#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "textbuffer.h"
#define   MAX_SIZE 20

int main(void) {

	char * test = "Line 10\nLine 11\nLine 12\nLine 13\nLine 14\nLine 15\n";
	TB buffer = CreateTBList(test);
	PrintBuffer(buffer);

	int lineNo;
	printf("Enter line number to insert after: ");
	scanf("%d" , &lineNo);

	buffer = AddLine(buffer , lineNo);
	PrintBuffer(buffer);
	FreeBuffer(buffer);
}

TB NewTBNode (char * text) {
	
	TB TBNode = malloc(sizeof(TB));
	
	TBNode->next = NULL;
	TBNode->prev = NULL;
	
	int size = strlen(text);
	TBNode->text = malloc(size * sizeof(char));
	strcpy(TBNode->text , text);
	
	return TBNode;
}

TB CreateTBList (char * text) {
	
	char * my_string = strdup(text);
	char * ss = strsep(&my_string , "\n");
	TB new_node = NewTBNode(ss);

	while((ss = strsep(&my_string , "\n")) != NULL) {
		TB next_node = NewTBNode(ss);
		next_node->next = new_node;
		new_node->prev = next_node;
		new_node = next_node;
	}
	
	free(my_string);
	return new_node;
}

void PrintBuffer(TB head) {

	TB curr = head;
	int i = 1;

	printf("\n\n");
	while(curr != NULL) {
		printf("%d. %s\n" , i , curr->text);
		curr = curr->next;
		i++;
	}
	printf("\n");
}

void BufferTraverser (TB head) {

	char action;
	
	TB curr = head;
	HelpInterface();
	
	printf("\nAction: ");
	getchar();
	while(scanf("%c" , &action) != EOF) {
		if(action == 'P') {
			printf("Printing current line...\n");
			printf("%s\n" , curr->text);
		} else if(action == 'F') {
			printf("Moving one line forward...\n");
			curr = curr->next;
		} else if(action == 'B') {
			printf("Moving one line backward...\n");
			curr = curr->prev;
		} else if(action == 'E') {
			printf("Exiting program...\n");
			break;
		} else if(action == 'H') {
			HelpInterface();
		}
	}
}

void HelpInterface() {
	printf("\n-----HELP INTERFACE-----\n");
	printf("P = Print current line\n");
	printf("F = Move one line forward\n");
	printf("B = Move one line backward\n");
	printf("H = Help Interface\n");
	printf("E = Exit program\n");
	printf("----------------------------\n");
}

void FreeBuffer(TB head) {
	TB curr = head;
	while(curr != NULL) {
		TB temp = curr;
		free(temp->text);
		free(temp);
		curr = curr->next;
	}
}

TB AddLine (TB head , int lineNo) {
	
	TB curr = head;
	int count = 1;
	
	while(count < lineNo) {
		curr = curr->next;
		count++;
	}
	
	printf("\nEnter content of line: ");
	printf("\nEnter Ctrl+D TWICE to signal end of input\n\nINPUT: ");
	
	char line[1024];
	while(fgets(line , MAX_SIZE , stdin) != NULL) {}
	
	int length = strlen(line); 
	TB new_node = NewTBNode(line);
	
	curr->next->prev = new_node;
	new_node->next = curr->next;
	new_node->prev = curr;
	curr->next = new_node;

	return head;

}
