#include <stdio.h>
#define size 10

void insert(int ele, int queue[], int *r, int *f) {
	if ((*r == size - 1 && *f == 0) || (*f == *r + 1)) {
		printf("Queue Overflow \n");
		return;
	}
	if (*f == -1) *f = 0;
	*r = (*r + 1) % size;
	queue[*r] = ele;
}

int delete(int queue[],int *f, int *r) {
	int ele;
	if (*f == -1) {
		printf("Queue Underflow \n");
		return -999;
	} else {
		ele = queue[*f];
		if (*f == *r) {
			*f = -1;
			*r = -1;
		} else {
			*f = (*f + 1) % size;
			return ele;
		}
	}
}

void display(int queue[], int f, int r) {
	int i;
	if (f == -1) printf("Queue Underflow\n");
	else { 
		for (i = f; i != r; i = (i + 1) % size) printf("%d \n", queue[i]);
		printf("%d", queue[i]);
	}
}

int main() {
	int queue[10];
	int f = -1, r = -1, option, ele, ch;
	do {
		printf(" 1.Insert \n 2.Deletion \n 3.Display \n");
		printf("Enter option\n");
		scanf("%d", &option);

		switch (option) {
			case 1: printf("Enter Element to be Inserted \n");
				scanf("%d", &ele);
				insert(ele, queue, &r, &f);
				break;

			case 2: ele = delete(queue, &f, &r);
				if (ele == -999) break;
				printf("The Deleted Element is : %d \n", ele);
				break;

			case 3: display(queue, f, r);
		        	break;

			default: printf("Invalid Input \n");
		}

	printf("Try Again (1 For Yes/2 For No)? \n");
	scanf("%d", &ch);
	} while (ch == 1);

    return 0;
}
