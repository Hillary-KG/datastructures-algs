#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *prev;
    struct node *next;  
};

struct node *head, *temp, *tail;

void create_dll();
void insert_beginning();
void insert_at_end();
void insert_at_pos();
void insert_after_pos();
void display_dll();
void delete_beginning();
void delete_at_end();
void delete_at_pos();
int calculate_len();
void reverse_dll();


void main(){
    create_dll();
    // insert_after_pos();
    // delete_beginning();
    // delete_at_pos();
    reverse_dll();
}

void create_dll(){
    struct node *newnode;
    int choice = 1;
    head = 0;
    while(choice){
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d", &newnode->data);

        newnode->prev = newnode -> next = 0;
        if(head == 0){
            head = tail = newnode;
        }else{
            tail -> next = newnode; //update the next of the last node
            newnode -> prev = tail; //uodate the prev link for new node
            tail = newnode; //move tail(temp node) ptr to point to the new node
        }
        printf("Continue?: ");
        scanf("%d", &choice);
    }
    printf("Newly created DLL\n");
    display_dll();
}

void display_dll()
{
    int counter = 0;
    // for traversal, point temp to the head node
    temp = head;
    while (temp != 0){
        printf("\nPosition %d\n", counter+1);
        printf("\tData: %d\n", temp->data);
        printf("\tPrev: %u\n", temp->prev);
        printf("\tNext: %u\n", temp->next);
        temp = temp->next;
        counter++;
    }
}

int calculate_len()
{
    int len = 0;
    // for traversal, point temp to the head node
    temp = head;
    while (temp != 0){
        temp = temp->next;
        len++;
    }

    printf("\nDll Len: %d\n", len);
    return len;
}

void insert_beginning(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter Data: \n");
    scanf("%d", &newnode->data);
    if (head == 0){
        head = newnode;
        tail = newnode;
    }else{
        newnode->prev = 0;
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
    printf("\nInsertion at beginning success\n");
    display_dll();
}

void insert_at_end(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data: \n");
    scanf("%d\n", &newnode->data);
    tail->next = newnode;
    newnode->prev = tail;
    newnode -> next = 0; //update the next ptr to 0 
    tail = newnode; //move tail to point to the newly inserted node
    printf("\nInsertion at end success\n");
    display_dll();
}

void insert_at_pos(){
    int pos, i=0;
    struct node *newnode, *temp;
    temp = head;

    printf("Enter posision to insert: \n");
    scanf("%d", &pos);
    // sanity check
    if(pos < 0){
        printf("Invalid position!");
        // exit(0);
    }
    else if(pos == 1){
        insert_beginning();
    }else{
        while(i <= pos-1){
            temp = temp->next;
            i ++;
        }
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data to insert:\n");
        scanf("%d", &newnode->data);
        
        newnode->next = temp;
        newnode->prev = temp->prev;
        temp->prev->next = newnode;
        temp->prev = newnode;
    }
    printf("\nInsertion at pos success\n");
    display_dll();
}

void insert_after_pos(){
    int pos, i=0;
    struct node *newnode, *temp;
    temp = head;

    printf("Enter pos : \n ");
    scanf("%d", &pos);

    if (pos < 0){
        printf("Invalid Position!");
    }else if (pos == 1){
        insert_beginning();
    }else{
        while (i < pos){
            temp = temp -> next;
            i++;
        }

        newnode = (struct node *)(malloc(sizeof(struct node)));
        printf("Insert new node data: ");
        scanf("%d", &newnode->data);

        newnode->prev = temp;
        newnode->next = temp->next;
        temp->next->prev = newnode;
        temp->next = newnode;
        temp = newnode;
    }
    printf("\nInsertion after pos success\n");
    display_dll();
}

void delete_at_end(){
    struct node *temp;
    // sanity check
    if (tail == 0){
        printf("List is empty");
    }else{
        temp = tail;
        tail->prev->next = 0;
        tail = tail->prev;

        free(temp);
    }
    printf("\nDeletion at end successful\n");
    display_dll();
}

void delete_at_pos(){
    struct node *temp;
    int pos, i=1;
    printf("Enter pos : \n ");
    scanf("%d", &pos);

    if(pos < 0){
        printf("Invalid position");
    }else if(pos == 1){
        delete_beginning();
    }else{
        temp = head;
        // traverse the list
        while(i < pos){
            temp = temp->next;
            i ++;
        }
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        free(temp);
    }
    printf("\nDeletion at Position successful\n");
    display_dll();
}

void delete_beginning(){
    struct node *temp;
    if(head == 0){
        printf("List is empty");
    }else{
        temp = head;
        head = temp->next;
        free(temp);
    }
    printf("\nDeletion at Beginning successful\n");
    display_dll();
}


void reverse_dll(){
    struct node *currentNode, *nextNode;
    currentNode = head;
    while(currentNode != 0){
        nextNode = currentNode->next;
        currentNode->next = currentNode->prev;
        currentNode->prev = nextNode;
        currentNode = nextNode;
    }
    currentNode = head;
    head = tail;
    tail = currentNode;
    printf("\nReversedDLL done!\n");
    display_dll();
}