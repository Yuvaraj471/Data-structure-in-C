#include <stdio.h>
#include <conio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *prev;
    struct Node *next;
};

struct Node* head = NULL;

void create(int n) {
    struct Node *temp, *last;
    int i, value;

    head = NULL;
    last = NULL;

    for (i = 0; i < n; i++) {
        temp = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data: ");
        scanf("%d", &value);
        temp->data = value;

        if (head == NULL) {
            temp->next = temp;
            temp->prev = temp;
            head = temp;
            last = temp;
        } else {
            temp->next = head;
            temp->prev = last;
            last->next = temp;
            head->prev = temp;
            last = temp;
        }
    }
}

void display() {
    struct Node* p = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        printf("%d <-> ", p->data);
        p = p->next;
    } while (p != head);
    printf("(HEAD)\n");
}

void insert(int pos, int val) {
    struct Node *temp, *p;
    int i;

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = val;

    if (head == NULL) {
        temp->next = temp;
        temp->prev = temp;
        head = temp;
        return;
    }

    if (pos == 1) {
        temp->next = head;
        temp->prev = head->prev;
        head->prev->next = temp;
        head->prev = temp;
        head = temp;
    } else {
        p = head;
        for (i = 1; i < pos - 1 && p->next != head; i++)
            p = p->next;

        temp->next = p->next;
        temp->prev = p;
        p->next->prev = temp;
        p->next = temp;
    }
}

void find(int key) {
    struct Node* p = head;
    if (head == NULL) {
        printf("List is empty\n");
        return;
    }
    do {
        if (p->data == key) {
            printf("Element found\n");
            return;
        }
        p = p->next;
    } while (p != head);
    printf("Element not found\n");
}

void deleteNode(int key) {
    struct Node *p = head;

    if (head == NULL) {
        printf("List is empty\n");
        return;
    }

    do {
        if (p->data == key) {
            if (p->next == p && p->prev == p) {  // only one node
                free(p);
                head = NULL;
                return;
            }

            p->prev->next = p->next;
            p->next->prev = p->prev;

            if (p == head)
                head = p->next;

            free(p);
            return;
        }
        p = p->next;
    } while (p != head);

    printf("Element not found\n");
}

void main() {
    int choice, val, pos, n;
    clrscr();

    do {
	printf("\n1. Create\n2. Display\n3. Insert\n4. Find\n5. Delete\n6. Exit\n-->>Choice<<--: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("How many nodes? ");
                scanf("%d", &n);
                create(n);
                break;
            case 2:
                display();
                break;
            case 3:
                printf("Enter position and value: ");
                scanf("%d%d", &pos, &val);
                insert(pos, val);
                break;
            case 4:
                printf("Enter value to find: ");
                scanf("%d", &val);
                find(val);
                break;
            case 5:
                printf("Enter value to delete: ");
                scanf("%d", &val);
                deleteNode(val);
                break;
        }
    } while (choice != 6);

    getch();
}