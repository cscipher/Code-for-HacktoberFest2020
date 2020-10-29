// Github Username: CRJain

// C Program to detect and remove loop in linked list.
#include <stdio.h>
#include <stdlib.h>

// Creating structure for linked list
struct node
{
    int data;
    struct node* next;
};

// Function to create new node in linked list
struct node* createNewNode(int data)
{
    struct node* newNode = (struct node*) malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;    
    return newNode;
}

// Function to Detect and Remove loop from linked list
void detectAndRemoveLoop(struct node* head)
{
    if(head == NULL || head->next == NULL)
        return;

    struct node* slowPtr=head;
    struct node* fastPtr=head;

    slowPtr = slowPtr->next;
    fastPtr = fastPtr->next->next;

    // Detecting the loop
    while(fastPtr && fastPtr->next)
    {
        if(slowPtr == fastPtr)
            break;
        slowPtr = slowPtr->next;
        fastPtr = fastPtr->next->next;
    }

    // If loop is detected
    if(slowPtr == fastPtr)
    {
        slowPtr = head;
        while(slowPtr->next != fastPtr->next)
        {
            slowPtr = slowPtr->next;
            fastPtr = fastPtr->next;
        }
        // Breaking the loop in linked list
        fastPtr->next = NULL;
    }
}

// Function to print the linked list
void printLinkedList(struct node* head)
{
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main()
{
    struct node* head = createNewNode(1);
    head->next = createNewNode(2);
    head->next->next = createNewNode(3);
    head->next->next->next = createNewNode(4);
    head->next->next->next->next = createNewNode(5);

    // Creating a loop for testing
    head->next->next->next->next->next = head->next;
    
    // Detecting and Removing the loop
    detectAndRemoveLoop(head);

    printf("Linked List after removing the loop:\n");
    printLinkedList(head);

    return 0;
}