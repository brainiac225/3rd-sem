#include <stdio.h>
#include <stdlib.h>

struct node {
	int val;
	struct node *next;
};

typedef struct node* NODE;
//create our list
NODE getNode() {
	NODE n = malloc(sizeof(struct node));
	n->val = 0;
	n->next = NULL;
	return n;
}

//to insert node
NODE insert(NODE head, int val) { 
	NODE temp = head, n = getNode();
	n->val = val;
	if (head == NULL) 
	    return n;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = n;
	return head;
}


//to delete at front
NODE delete_front(NODE head) {
	if (head == NULL) {
		printf("list is empty\n");
		return NULL;
	}
	printf("deleted element: %d\n", head->val);
	NODE curr = head;
	head = head->next;
	free(curr);
	return head;
}
//to delete at rear
NODE delete_rear(NODE head) {
	if (head == NULL) {
		printf("list is empty\n");
		return NULL;
	}
	if (head->next == NULL) {
		printf("deleted element: %d\n", head->val);
		return NULL;
	}
	NODE curr = head->next, prev = head;
	while (curr->next != NULL) { 
		prev = curr;
		curr = curr->next;
	}
	printf("deleted element: %d\n", curr->val);
	prev->next = NULL;
	free(curr);
	return head;
}
//to delete a specified element
NODE delete(NODE head, int ele) {
	if (head == NULL) {
		printf("list is empty\n");
		return NULL;
	}
	else if (head->val == ele) {
		printf("deleted element: %d\n", head->val);
		free(head);
		return NULL;
	}
	else {
		NODE curr = head->next, prev = head;
		while (curr->val != ele) {
			prev = curr;
			curr = curr->next;
			if (curr == NULL) {
				printf("element %d not found\n", ele);
				return head;
			}
		}
		printf("deleted element: %d\n", curr->val);
		prev->next = curr->next;
		free(curr);
		return head;
	}
	
}
//to display the list
void display(NODE head) {
	if (head == NULL) {
		printf("list is empty\n");
		return;
	}
	printf("The contents of the list are:\n");
	NODE temp = head;
	while (temp != NULL) {
		printf("%d\n", temp->val);
		temp = temp->next;
	}
	printf("\n");
}

int main() {
	NODE head = NULL;
	int ele;
	do {
		int choice, val;
		printf("PRESS 1: to insert\nPRESS 2: to delete at front\nPRESS 3: to delete element\nPRESS 4: to delete at end\nPRESS 5: display \nPRESS 6: to stop\n");
	    scanf("%d", &choice);
		switch (choice) {
			case 1: printf("Enter the value: ");
				scanf("%d", &val);
				head = insert(head, val);
				break;

			case 2:head = delete_front(head);
				break;
				
			case 3:printf("Enter the element to delete: ");
				scanf("%d", &ele);
				head = delete(head, ele);
				break;
				
			case 4:head = delete_rear(head);
				break;

			case 5:display(head);
				break;

			case 6: return 0;
		}	
	} while (1);
}
