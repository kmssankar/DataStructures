/*
 * LinkedList01.c
 *
 *  Created on: Sep 24, 2017
 *      Author: Sankar
 */
#include <stdio.h>
#include <malloc.h>

/* Linked list Structure */
struct Node
{
	int data;
	struct Node *next;
};

/*Main*/
int Addafter(struct Node** head_adr,int Dataafter,int Datinsrt)
{
  printf("\nData to added %d after %d",Datinsrt,Dataafter);
  struct Node *before = *head_adr;
         while(before->next != NULL)
         {
             if(before->data == Dataafter)
             {
                 printf("\nData Found ! Adding after");
                 struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
                 newnode->data = Datinsrt;
                 newnode->next = before->next;
                 before->next  = newnode;
                 return 0;
             }
             before = before->next;

         }
         return 1;
}
void AddtoList(struct Node** head_adr ,int Datinsrt)
	{
		printf("Data to be inserted %d \n",Datinsrt);
		if(*head_adr == NULL)
        {
         printf("Adding first data \n");
         struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
         newnode->data = Datinsrt;
         newnode->next = NULL;
         *(head_adr) = newnode;
        }
        else
        {
         struct Node *last = *head_adr;
         while(last->next != NULL)
         {
             last = last->next;
         }
         struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
         newnode->data = Datinsrt;
         newnode->next = NULL;
         last->next = newnode;
        }
	}

void displaylist(struct Node* disnode)
{
    printf("\n Node Data : ");
    while (disnode != NULL)
    {
          printf(" %d  " , disnode->data);
          disnode = disnode->next;
    }


}

int main()
{
	int loopvar1 = 0,Addafterstat;

	int list[6] = {1,2,3,31,4,5};

	struct Node* head = NULL;

	for(loopvar1=0;loopvar1<6;loopvar1++)
	{
	    printf("\n before Data insert \n");
		AddtoList(&head,list[loopvar1]);
		displaylist(head);
	}

    printf("\n Final Display \n");
    displaylist(head);
    Addafterstat = Addafter(&head,3,25);
    if(Addafterstat)
    {
        printf("\n Search Node not found!!");
    }
    displaylist(head);
    Addafterstat=Addafter(&head,13,17);
    if(Addafterstat)
    {
        printf("\n Search Node not found!!");
    }
	displaylist(head);
	return 0;
}
