#include <stdlib.h>
#include <stdio.h>	
typedef struct Node
{
    int data;
    struct Node* next;
}Node;
//kaynak:
//https://www.log2base2.com/data-structures/linked-list/inserting-a-node-at-the-end-of-a-linked-list.html
Node* insert(Node *head,int data)
{
    //Create a new node
    struct Node *newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    
    //if head is NULL, it is an empty list
    if(head == NULL)
    {
        head = newNode;
    }
    //Otherwise, find the last node and add the newNode
    else {
        struct Node *lastNode = head;
        
        //last node's next address will be NULL.
        while(lastNode->next != NULL)
        {
            lastNode = lastNode->next;
        }
        
        //add the newNode at the end of the linked list
        lastNode->next = newNode;
    }
    // return head value to print values
    return head;
}

void display(Node *head)
{
	Node *start=head;
	while(start)
	{
		printf("%d ",start->data);
		start=start->next;
	}
}
int main()
{
	int T,data;
    scanf("%d",&T);
    Node *head=NULL;	
    while(T-->0){
        scanf("%d",&data);
        head=insert(head,data);
    }
  display(head);
		
}

