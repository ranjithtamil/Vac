//Insert element in linked list
//Traverse linked list
//Delete element from linked list
//Search for elements

/* Test cases to take care of:
  1. Zero Element cases (Empty linkedlist)
  2. One element cases (1 Node linked list)
  3. General Case
*/

/*
Any program that changes head pointer should be passed as double pointer
While traversing, dont traverse by changing head pointer... Then we would
lose the elements in the list. So, use another pointer variable of same
data type as that of head.
*/

/*
Insert into linkedlist:
  - At beginning
  - At end
  - At particular position
  - In sorted list (in order <ascending/descending>)
*/
#include<stdio.h>
#include<stdlib.h>
typedef struct Node Node;
struct Node{
  int value;
  Node *next;
};
typedef Node* NodePtr;
#define SUCCESS 1
#define FAIL -1

//Function to display list - compress
void displaylist(NodePtr head)
{
  printf("\nDisplay List:\n");
  while(head!=NULL)
  {
    printf("%d",head->value);
    printf(" -> ");
    head=head->next;
  }
  printf(" NULL ");
  printf("\nCompleted printing list\n\n");
}

//1. Insertion at beginning
//#define Insertion_beginning
//2. Insertion at end(given only head pointer)
//#define Insertion_end
//3. Insertion at end(given head & tail pointer)
//#define Insertion_end_tail
//4. Insert at particular position (ToDo)
//5. Insert in Sorted List (ToDo)

//Code to insert at beginning of linkedlist - compress
#ifdef Insertion_beginning
int InsertNode(NodePtr* head,int val)
{
  NodePtr temp=malloc(1 * sizeof(Node));
  if(!temp)
  {
    printf("\nNode Creation (malloc) Failure");
    return FAIL;
  }

  //zero condition
  if(*head==NULL)
  {
    temp->value=val;
    temp->next=NULL;
  }//general case
  else
  {
    temp->value=val;
    temp->next=*head;
  }
  *head=temp;
  return SUCCESS;
}

int main()
{
  int arr[5]={1,2,3,4,5};
  NodePtr headPtr=NULL;
  int ret=FAIL;
// INSERT arr[0]
  ret=InsertNode(&(headPtr),arr[0]);

  if(ret==SUCCESS)
  {
    printf("\nInsertion of %d succeeded",arr[0]);
  }

  //display list
    displaylist(headPtr);



// INSERT arr[1]

  ret=FAIL;

  ret=InsertNode(&(headPtr),arr[1]);

  if(ret==SUCCESS)
  {
    printf("\nInsertion of %d succeeded",arr[1]);
  }

//display list
  displaylist(headPtr);


  // INSERT arr[2]

    ret=FAIL;

    ret=InsertNode(&(headPtr),arr[2]);

    if(ret==SUCCESS)
    {
      printf("\nInsertion of %d succeeded",arr[2]);
    }

  //display list
    displaylist(headPtr);

    return 0;
}
#endif //Insertion_beginning


//Code to insert at end of linkedlist(given only head pointer) - compress
#ifdef Insertion_end
int Insertend(NodePtr* head,int val)
{
    NodePtr temp=malloc(1* sizeof(Node));
    if(!temp)
    {
      printf("\nNode Creation (malloc) Failure");
      return FAIL;
    }

    if(*head==NULL) //empty list
    {
      temp->value=val;
      temp->next=NULL;
      *head=temp;
      return SUCCESS;
    }
    else //non-empty list
    {
      NodePtr currptr=*head;
      while((currptr->next)!=NULL) //loop until you reach last element
      {
        currptr=currptr->next;
      }
      if(currptr->next==NULL) //make sure lastelement->next is NULL
      {
        temp->value=val;
        temp->next=NULL;
        currptr->next=temp;
        return SUCCESS;
      }
      else
      {
        printf("\nError: Didnt reach last NULL element\n");
      }
    }
}

int main()
{
int arr[5]={1,2,3,4,5};
int ret=FAIL;
NodePtr headPtr=NULL;
ret=Insertend(&(headPtr),arr[0]);

if(ret==SUCCESS)
{
  printf("\nInsertion of %d succeeded",arr[0]);
}

//display list
displaylist(headPtr);


  ret=FAIL;

  ret=Insertend(&(headPtr),arr[1]);

  if(ret==SUCCESS)
  {
    printf("\nInsertion of %d succeeded",arr[1]);
  }

//display list
  displaylist(headPtr);


  // INSERT arr[2]

    ret=FAIL;

    ret=Insertend(&(headPtr),arr[2]);

    if(ret==SUCCESS)
    {
      printf("\nInsertion of %d succeeded",arr[2]);
    }

  //display list
    displaylist(headPtr);



return 0;
}
#endif //Insertion_end

#ifdef Insertion_end_tail
int Insert_end_tail(NodePtr* head, NodePtr* tail, int val)
{
  NodePtr temp=malloc(1*sizeof(Node));
  if(!temp)
  {
    printf("\nNode Creation (malloc) Failure");
    return FAIL;
  }
  if(*head==NULL && *tail==NULL)
  {
    temp->value=val;
    temp->next=NULL;
    *head=temp;
    *tail=temp;
    return SUCCESS;
  }
  else
  {
    temp->value=val;
    temp->next=NULL;
    (*tail)->next=temp;
    *tail=temp;
    return SUCCESS;
  }
}
int main()
{
  int arr[5]={1,2,3,4,5};
  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;
  int ret=FAIL;
  ret=Insert_end_tail(&(headPtr),&(tailPtr),arr[0]);

  if(ret==SUCCESS)
  {
    printf("\nInsertion of %d succeeded",arr[0]);
  }

  //display list
  displaylist(headPtr);

  ret=FAIL;
  ret=Insert_end_tail(&(headPtr),&(tailPtr),arr[1]);
  if(ret==SUCCESS)
  {
    printf("\nInsertion of %d succeeded",arr[1]);
  }

  //display list
  displaylist(headPtr);

  ret=FAIL;
  ret=Insert_end_tail(&(headPtr),&(tailPtr),arr[2]);
  if(ret==SUCCESS)
  {
    printf("\nInsertion of %d succeeded",arr[2]);
  }

  //display list
  displaylist(headPtr);


return 0;
}

#endif
