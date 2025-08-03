#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node* perv;
	struct Node* next;

};

struct Node *head = NULL;

void create(int n){
	struct Node *temp, *last;
	int i, value;

	head = NULL;
	last = NULL;

	for(i = 0;i < n;i++){
		temp = (struct Node*)malloc(sizeof(struct Node));
		printf("Enter data: ");
		scanf("%d", &value);
		temp->data = value;
		temp->perv = NULL;
		temp->next = NULL;

		if (head == NULL){
			head = temp;
		}else{
			last->next = temp;
			temp->perv = last;
		}
		last = temp;
	}
}

void display(){
	struct Node* p =head;
	while (p != NULL){
		printf("%d<->", p->data);
		p = p->next;
	}
	printf("NULL\n");
}

void insert(int pos, int val){
	struct Node *temp, *p;
	int i;

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = val;
	temp->perv =NULL;
	temp->next =NULL;

	if(pos == 1){
		temp->next = head;
		if (head != NULL)
			head->perv = temp;
		head = temp;
	}else{
		p = head;
		for(i = 1;i < pos - 1 && p != NULL;i++){
			p = p->next;
		}
		if(p != NULL){
			temp->next = p->next;
			temp->perv = p;
			if(p->next != NULL)
			   p->next->perv = temp;
			p->next = temp;
		}else{
			printf("Invalid Position\n");
		}
	}
}

void find(int key){
	struct Node* p = head;
	while(p != NULL){
		if(p->data == key){
			printf("Element founded\n");
			return;
		}
		p = p->next;
	 }
	 printf("Element not found\n");
}

void deleteNode(int key){
	struct Node *p;

	p = head;
	while(p != NULL && p->data != key){
		p = p->next;
	}
	if(p == NULL){
		printf("Elements not found\n");
		return;
	}

	if(p->perv != NULL)
		p->perv->next = p->next;
	else
		head = p->next;
	if(p->next != NULL)
		p->next->perv = p->perv;

	free(p);
}

void main(){
	int choice, val, pos, n;
	clrscr();

	do{
	   printf("\n1. Create\n2.Display\n3.Insert\n4.Find\n5.Delete\n6.Exit\n-->CHOICE<--:");
	   scanf("%d",&choice);
	   switch(choice){
		case 1:
			printf("How many nodes?");
			scanf("%d", &n);
			create(n);
			break;
		case 2:
			display();
			break;
		case 3:
			printf("Enter poistion and value: ");
			scanf("%d%d",&pos, &val);
			insert(pos,val);
			break;
		case 4:
			printf("Enter the value to Find: ");
			scanf("%d", &val);
			find(val);
			break;
		case 5:
			printf("Enter value to delete: ");
			scanf("%d", &val);
			deleteNode(val);
			break;
		}
	   }while(choice != 6);

	   getch();
}