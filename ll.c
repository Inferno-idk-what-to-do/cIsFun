#include <stdio.h>

#define PRINTMENU 1
#define PRINTLIST 2
#define INSERTTAIL 3
#define INSERTHEAD 4
#define INSERTN 5
#define DELETE 6
#define QUIT 7

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
	printf("%d -> insert node at n\n", INSERTN);
	printf("%d -> delete node at n\n", DELETE);
	printf("%d -> quit\n", QUIT);
	return;
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
	return;
}

void insertTail(int* data) {
	struct ListNode new;
	new.data = *data;
	new.next = NULL;

	if (head == NULL) {
		head = &new;
	} else {
		struct ListNode* current = head;

		while (current->next != NULL) {
			current = current->next;
		}

		current->next = &new;
	}
	return;
}

void insertHead(int* data) {
	struct ListNode* oldHead = head;
	struct ListNode new;
	new.data = *data;
	new.next = oldHead;
	head = &new;
}

int main() {
	printMenu();

	int userChoice = -1;

	while (userChoice != QUIT) {
		printf("=> ");
		scanf("%d", &userChoice);

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
			case QUIT:
				return 0;
		}
	}

	return 0;
}
