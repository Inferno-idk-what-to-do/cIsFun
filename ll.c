#include <stdio.h>
#include <stdlib.h>

#define PRINTMENU 1
#define PRINTLIST 2
#define INSERTTAIL 3
#define INSERTHEAD 4
#define DELETE 5
#define QUIT 6

struct ListNode {
	int data;
	struct ListNode* next;
};

struct ListNode* head = NULL;

void printMenu() {
	printf("%d -> print this menu\n", PRINTMENU);
	printf("%d -> print list\n", PRINTLIST);
	printf("%d -> insert node at tail\n", INSERTTAIL);
	printf("%d -> insert node at head\n", INSERTHEAD);
	printf("%d -> delete node at n\n", DELETE);
	printf("%d -> quit\n", QUIT);
}

void printList() {
	if (head == NULL) {
		printf("list is empty\n");
	} else {
		struct ListNode* current;
		current = head;
		while (current != NULL) {
			printf("%d -> ", current->data);
			current = current->next;
		}
		printf("NULL\n");
	}
}

void insertTail(int* data) {
	struct ListNode* new = malloc(sizeof(struct ListNode));
	new->data = *data;
	new->next = NULL;

	if (head == NULL) {
		head = new;
	} else {
		struct ListNode* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = new;
	}
}

void insertHead(int* data) {
	struct ListNode* oldHead = head;
	struct ListNode* new = malloc(sizeof(struct ListNode));
	new->data = *data;
	new->next = oldHead;
	head = new;
}

void delete(int* pos) {
	int counter = *pos;

	if(counter == 0) {
		struct ListNode* oldHead = head;
		head = head->next;
		free(oldHead);
		return;
	}

	struct ListNode* prev = NULL;
	struct ListNode* current = head;

	while(counter > 0) {
		if (current == NULL) {
			printf("node not in list\n");
			return;
		} else {
			counter--;
			prev = current;
			current = current->next;
		}
	}

	if (current == NULL) {
		printf("node not in list\n");
		return;
	}

	prev->next = current->next;
	free(current);
}

int main() {
	printMenu();

	int userChoice = -1;

	while (userChoice != QUIT) {
		printf("=> ");
		int error = scanf("%d", &userChoice);

		if(error == 0) {
			printf("invalid entry: enter 1 for help\n");
			continue;
		}

		switch(userChoice) {
			case PRINTMENU:
				printMenu();
				break;
			case PRINTLIST:
				printList();
				break;
			case INSERTTAIL:
				printf("enter data to be inserted => ");
				scanf("%d", &userChoice);
				insertTail(&userChoice);
				userChoice = -1;
				break;
			case INSERTHEAD:
				printf("enter data to be inserted => ");
				scanf("%d", &userChoice);
				insertHead(&userChoice);
				userChoice = -1;
				break;
			case DELETE:
				printf("enter position (0 indexed) to be deleted => ");
				scanf("%d", &userChoice);
				delete(&userChoice);
				userChoice = -1;
				break;
			case QUIT:
				return 0;
			default:
				printf("invalid entry: enter 1 for help\n");
				break;
		}
	}

	return 0;
}
