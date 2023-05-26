#include <stdio.h>
#include <stdlib.h>

struct node
{
    /* data */
    int data;
    struct node *next;
};

struct node *tail;

void create_list();
void display_list();
void delete_at_pos();
void delete_beginning();    
void delete_after_pos();
void insert_at_beginning();
void insert_at_pos();
void insert_after_pos();
void insert_at_end();
void reverse_list();
void calculate_len();


void main(){
    create_list();
    display_list();
    // insert_at_pos();
    // insert_at_beginning();
    // insert_at_end();
    calculate_len();
}


void create_list(){
    struct node *newnode, *temp;
    int choice = 1;
    tail = 0;

    while (choice)
    {
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data: \n");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        if (tail == 0)
        {
            tail = newnode;
            tail->next = newnode;
        }
        else
        {
            newnode->next = tail->next;
            tail->next = newnode;
            tail = newnode;
        }
        printf("1 for continue, 0 for exit \n");
        scanf("%d", &choice);
    }
    printf("\nTail next: %d\n", tail->next->data);
}

void display_list(){
    struct node *temp;
    int len;
    temp = tail->next;
    if (temp == 0)
    {
        printf("List is empty");
    }
    else
    { 
        do
        {
            printf("node at %u:\n", temp);
            printf("\tData: %d\n", temp->data);
            printf("\tNext: %u\n", temp->next);
            temp = temp->next;
        } while (temp != tail->next);
    }

    // len = calculate_len();
    // printf("\nLength of the list is: %d\n", len);
}

void insert_at_pos(){
    struct node *temp, *newnode;
    int pos, i=1;
    printf("Enter position to insert: ");
    scanf("%d", &pos);
    if (pos < 0)
    {
        printf("Invalid position");
    }
    else
    {
        temp = tail->next;
        newnode = (struct node *)malloc(sizeof(struct node));
        printf("Enter data for new node: ");
        scanf("%d", &newnode->data);
        newnode->next = 0;
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        newnode->next = temp->next;
        temp->next = newnode;
        temp = newnode;
    }
    printf("New list after insert\n");
    display_list();
}

void insert_at_beginning(){
    struct node *newnode;
    
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (tail->next == 0)
    {
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
    }
    printf("New list after insert at 0\n");
    display_list();
}

void insert_at_end(){
    struct node *newnode;
    newnode = (struct node *)malloc(sizeof(struct node));
    printf("Enter data for new node: ");
    scanf("%d", &newnode->data);
    newnode->next = 0;

    if (tail->next == 0)
    {
        tail = newnode;
        newnode->next = newnode;
    }
    else
    {
        newnode->next = tail->next;
        tail->next = newnode;
        tail = newnode;
    }
    printf("New list after insert at the end\n");
    display_list();
}

void calculate_len(){
    struct node *temp;
    int len = 0;
    temp = tail->next;
    if(temp == 0){
        printf("List is empty");
    }
    else 
    {
        printf("\ncounting ...\n");
        do
        {
            len ++;
            temp = temp->next;
        }while (temp != tail);
    }
    printf("\nThe list len is: %d\n", len);
}

void delete_beginning(){

}
