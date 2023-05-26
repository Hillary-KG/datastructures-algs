#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;          // stores the data
    struct node *next; // store addr for the next node in the linked list
};
struct node *head, *temp;
void create_ll();
void display_ll();
void delete_at_pos();
void delete_at_beggng();
int count_items();
void reverse_list();

    void
    main()
{
    create_ll();
    display_ll();
    delete_at_beggng();
    display_ll();
    count_items();
    delete_at_pos();
    display_ll();
    reverse_list();
    display_ll();
    // int num = count_items();
    // printf("Final count: %d", num);
}

void display_ll(){                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                       *temp;
    int choice = 1, counter = 0;
    // for traversal, point temp to the head node
    temp = head;
    while (temp != 0)
    {
        printf("Data: %d\n", temp->data);
        temp = temp->next;
        counter ++;
    }
    
    printf("Counter: %d\n", counter);
}


void create_ll(){
    // head:store  address of the first node, newnode:addr of new node, temp: addr of a temporary node to hold addr of temp node for insertion/traversal
    struct node *newnode;
    int choice = 1, counter;

    head = 0;
    while (choice)
    {
        // allocate memory for a node using malloc function ---memory allocation
        newnode = (struct node *)malloc(sizeof(struct node)); // type casting addr returned by malloc to a struct node ptr

        printf("Enter data for new node:");
        scanf("%d", &newnode->data);

        newnode->next = 0;

        if (head == 0)
        {
            head = newnode;
            temp = newnode;
        }
        else
        {
            temp->next = newnode;
            temp = newnode;
        }

        printf("Continue ?\n");
        scanf("%d", &choice);
    }
}

void delete_at_beggng(){
    if(head == 0){
        printf("List is empty");
    }else{
        temp = head;
        head = temp ->next;
        free(temp); //free the memory garbage 
    }
}

void delete_at_pos(){
    struct node *nextnode;
    int i = 1, count, pos;
    count = count_items();
    temp = head;
    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // sanity check here
    if (pos > count)
        printf("Invalid Position");
    else
    {
        while (i < pos-1)
        {
            temp = temp->next;
            i++;
        }
        nextnode = temp->next;
        temp->next = nextnode->next;
        free(nextnode);
    }
}


int count_items(){
    int count = 0;
    temp = head;
    while (temp != 0){
        count ++;
        temp = temp -> next;
    }
    printf("Size >>> %d\n", count);

    return count;
}

void reverse_list(){
    struct node *prev_node, *next_node;
    prev_node = 0;
    temp = head;

    while(next_node != 0){
        next_node = temp -> next;
        temp -> next = prev_node;
        prev_node = temp;
        temp = next_node;
    }
}