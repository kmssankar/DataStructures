/*
 * Double_linked List.c
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
	struct Node *prev;
	struct Node *next;
};

/*Main*/
void AddtoList(struct Node** head_adr ,struct Node** tail_adr ,int Datinsrt)
	{
		printf("Data to be inserted %d \n",Datinsrt);
		if(*head_adr == NULL)
        {
         printf("Adding first data \n");
         struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
         newnode->data = Datinsrt;
         newnode->prev = NULL;
         newnode->next = NULL;
         *(head_adr) = newnode;
         *(tail_adr) = newnode;
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
         newnode->prev = last;
         last->next    = newnode;
         *(tail_adr)   = newnode;
        }
	}

void displaylist(struct Node* disnode,struct Node* Revnode)
{
    printf("\n Node Data : ");
    while (disnode != NULL)
    {
          printf(" %d  " , disnode->data);
          disnode = disnode->next;
    }
   printf("\nList in Reverse order");
    while (Revnode != NULL)
    {
          printf(" %d  " , Revnode->data);
          Revnode = Revnode->prev;
    }
}

void deletedata(struct Node** head_adr ,struct Node** tail_adr ,int Datdelete)
{
    if(head_adr == NULL)
    {
        printf("\n Input header is Null");
        return;
    }
    struct Node* temp = *head_adr;
    while(temp != NULL)
    {
        if (temp->data == Datdelete)
        {
            printf("\nDelete processing currentdata %d",temp->data);
            struct Node* prevtemp = NULL;
            struct Node* nexttemp = NULL;
            if ((temp->prev == NULL) && (temp->next != NULL))
            {
                printf("\n Deleting the header ");
                nexttemp       = temp->next;
                nexttemp->prev = NULL;
                *(head_adr)    = nexttemp;
                free(temp);
                return;
            }
            else if((temp->prev != NULL) && (temp->next == NULL))
            {
                printf("\n Deleting the Trailer Node ");
                prevtemp       = temp->prev;
                prevtemp->next = NULL;
                *(tail_adr)    = prevtemp;
                free(temp);
                return;
            }
            else
            {
                printf("\n Deleting the LAST Element");
               *(head_adr) = NULL;
               *(tail_adr) = NULL;
                free(temp);
                return;
            }
        }
      temp = temp->next;
    }
}
int main()
{
	int loopvar1 = 0;

	int list[6] = {1,2,3,31,4,5};

	struct Node* head = NULL;
	struct Node* tail = NULL;

	for(loopvar1=0;loopvar1<6;loopvar1++)
	{
		AddtoList(&head,&tail,list[loopvar1]);
		//displaylist(head);
	}

	displaylist(head,tail);
	printf("\n Deleting value 1 ");
    deletedata(&head,&tail,1);
    displaylist(head,tail);
    deletedata(&head,&tail,5);
    deletedata(&head,&tail,2);
    deletedata(&head,&tail,3);
    deletedata(&head,&tail,31);
    deletedata(&head,&tail,4);
    printf("\n Final Display \n");
	displaylist(head,tail);
	return 0;
}


