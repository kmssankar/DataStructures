#include <stdio.h>
#include <malloc.h>
struct Node
{
	int data;
	struct Node *Left;
	struct Node *Right;
};

void addtotree(struct Node** root,int data);
void showtree(struct Node* root);

int main()
{
    int Arrinp[9] ={0,7,15,17,25,6,8,12,1},i=0,SearchInp[9] ={10,15,11,25,16,8,12,1},srchout;
    struct Node* Root = NULL;
    for (i=0;i<9;i++)
    {
      addtotree(&Root,Arrinp[i]);
      printf("\nAfter adding %d",Arrinp[i]);
      showtree(Root);
    }
    printf("\n Final tree ");
    showtree(Root);
    for(i=0;i<7;i++)
    {
    srchout= Searchtree(Root, SearchInp[i]);
      if(srchout)
      {
         printf("\n %d Element found !", SearchInp[i]);
      }
      else
      {
         printf("\n %d Element Not found !", SearchInp[i]);
      }
    }
    return 0;
}

void addtotree(struct Node** root,int data)
{
    struct Node* Newnode = (struct Node*) malloc(sizeof(struct Node));
    struct Node* Parent;
    struct Node* Current;
    Newnode->data  = data;
    Newnode->Right = NULL;
    Newnode->Left  = NULL;
    if (*root == NULL)
    {
        printf("\n Adding node to empty tree %d ",data);
        (*root) = Newnode;
    }
    else
    {
        Current = *root;
        Parent = Current;
        while(1)
        {
          if (data < Current->data)
           {
            printf("\n Data less than parent %d",Current->data);
           Current = Current->Left;
           if(Current == NULL )
           {
               Parent->Left = Newnode;
               printf("\nAdded the data at left %d ",data);
               return;
           }
           Parent = Current;
           }
           else
           {
               printf("\nData greater than Parent %d " , Current->data);
               Current = Current->Right;
           if(Current == NULL)
           {
               Parent-> Right = Newnode;
               printf("\nAdded the data at right %d ",data);
               return;
           }
           Parent = Current;
           }
        }

    }
}

// Search
int Searchtree(struct Node* root,int search)
{
    while(root != NULL)
    {
        if (search == root->data)
        {
            return 1;
        }
        else if(search > root->data)
        {
            root = root->Right;
        }
        else if(search < root->data)
        {
            root = root->Left;
        }
    }
    return 0;
}
//Show the Tree !
void showtree(struct Node* root)
{
    if(root!=NULL)
    {
      showtree(root->Left);
      printf(" \n %d ",root->data);
      showtree(root->Right);
    }
}
