#include <iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;

//typedef struct node node;
//
//struct node{
//int data;
//node* next;
//} ;
typedef struct node_t{
int data;
struct node_t* next;
} node;

void printList(node* head);
void push(node** head_ref, int new_data);
void insertAfter(node* prev_node, int new_data);
void append(node** head_ref, int new_data);
void deleteNode(node** head_ref, int key);
void deleteNodePos(node** head_ref, int pos);

int main()
{
 /* Start with the empty list */
    node* head = NULL;

   push(&head, 7);
    push(&head, 1);
    push(&head, 3);
    push(&head, 2);
    push(&head, 8);

    puts("Created Linked List: ");
    printList(head);
    deleteNodePos(&head, 4);
    puts("\nLinked List after Deletion at position 4: ");
    printList(head);
    return 0;
}

void printList(node* head)
{
    node* list = head;
   cout<< "printing.." <<endl;
    while(list != NULL)
    {
        cout << list->data << " --> ";
        list = list->next;
    }
}

void push(node** head_ref, int new_data)
{
    //create a new node
    node* new_node = (node*)malloc(sizeof(node));
    new_node->data = new_data;
    new_node->next = (*head_ref);

    (*head_ref) = new_node;
}

void insertAfter(node* prev_node, int new_data)
{
    node* new_node = new node;
    new_node->data = new_data;

    new_node->next = prev_node->next;
    prev_node->next = new_node;
}

void append(node** head_ref, int new_data)
{


    node* head = (*head_ref);

    node* last_node = head;
    node* new_node = new node;

    while(head != NULL)
    {
        last_node = head;
        head = head->next ;
    }

    new_node->data = new_data;

  //  cout<<"appending..."<<endl;
    if(last_node == NULL)
    {
        *head_ref = new_node;
    }
    else{
        last_node->next = new_node;
    }

//    cout<<"appending..."<<(*head_ref)->data<<endl;
}

void deleteNode(node** head_ref, int key)
{
    if(*(head_ref) == NULL)
    {
        cout<< "list is empty"<<endl;
        return;
    }

    node* head = *(head_ref);
    while((head != NULL)&&(head->data != key))
    {
        head = head->next;
    }

    if(head == NULL)
    {
        cout<< "list is empty"<<endl;
    }
    else
    {
        if(head->next != NULL)
        {
            head->data = (head->next)->data;
            head->next = (head->next)->next;
        }
        else
            free(head);
    }

}

void deleteNodePos(node** head_ref, int pos)
{
    node* head = *head_ref;
    node* prev = NULL;

    int countp = 0;
    while(head != NULL && countp != pos)
    {
        prev = head;
        head = head->next;
        countp++;
    }

    if(head == NULL)
    {
        cout<< "list is empty"<<endl;
    }
    else if(pos == countp)
    {
        if(head->next != NULL)
        {
            cout<<"head->data "<<head->data<<"(head->next)->data "<<(head->next)->data ;
            head->data = (head->next)->data;
            head->next = (head->next)->next;
        }
        else
        {
            prev->next = NULL;
            free(head);//if not taken prev dangling pointer will be left for the case of last node deletion

        }
    }
}

getCountIter(node* head)
{}

getCountRec(node* head)
{}
