#include <stdio.h>
#include <stdlib.h>

/* linked list node */
struct Node
{
    int data;
    struct Node *next;
};

/* function to reverse the linked list */
void reverse(struct Node **head_ref)
{
    struct Node *prev = NULL;
    struct Node *current = *head_ref;
    struct Node *next;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    *head_ref = prev;
}

void push(struct Node **head_ref, int new_data)
{
    /* allocate node */
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    /* put in the data  */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = (*head_ref);

    /* move the head to point to the new node */
    (*head_ref) = new_node;
}

void printList(struct Node *node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}

int main(int argc, char const *argv[])
{
    /* build the linked list */
    struct Node *head = NULL;

    push(&head, 9);
    push(&head, 2);
    push(&head, 5);
    push(&head, 10);
    push(&head, 8);

    /* print the linked list */
    printList(head);

    /* reverse the linked list */
    reverse(&head);

    /* print the linked list */
    printf("\n");
    printList(head);

    return 0;
}
