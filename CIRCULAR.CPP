#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

struct Node{
	int data;
	struct Node *prev;
	struct Node *next;
};

struct Node* head = NULL;

void create(int n){
	struct Node *temp, *last;
	int i, value;

	head = NULL;
	last = NULL;

	for(i = 0; i < n; i++){
		temp = (struct Node*)malloc(sizeof(stroct Node));
		printf("Enter data: ");
		scanf("%d", &value);
		temp->data = value;

		if(head == NULL){
			temp->next = temp;
			temp->prev = temp;
			head = temp;
			last = temp;
		}else{
			temp->next = head;
			temp->prev = last;
			last->next = temp;
			head->prev = temp;
			last = temp;
		}
	}
}

void display(){
	struct Node* p = head;
	if(head == NULL){
		printf("List is empty\n");
		return;
	}
	do{
		printf("%d<-> ",p ->data);
		p = p->next;
	}while(p != head);
	printf("(HEAD)\n");
}

void insert(int pos, int val){
	struct Node *temp, *p;
	int i;

	temp = (struct Node*)malloc(sizeof(struct Node));
	temp->data = val;

	if(head == NULL){
		temp->next = temp;
		temp->prev = temp;
		head = temp;
		return;

	}

	if(pos == 1){
		temp->next = head;
		temp->prev = head->prev