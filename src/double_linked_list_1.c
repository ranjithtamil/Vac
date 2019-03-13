#include<stdio.h>
#include<stdlib.h>
#define FALSE -1
#define SUCCESS 1
typedef struct Node Node;
typedef struct Node* NodePtr;
struct Node {
  int value;
  Node* prev;
  Node* next;
};

#define Reverse_list

#ifdef Reverse_list
int insert_beginning(NodePtr* head,NodePtr* tail,int val)
{
  NodePtr temp=malloc(sizeof(Node));

  if(!temp)
  {
    printf("\nCannot malloc node to be inserted\n");
    return FALSE;
  }


  temp->value=val;
  temp->next=NULL;

  if(*head==NULL)
  {
    temp->next=NULL;
    temp->prev=NULL;
    (*head)=temp;
    (*tail)=temp;
    return SUCCESS;
  }
  else
  {
    temp->next=*head;
    (*head)->prev=temp;
    temp->prev=NULL;
    (*head)=temp;
    return SUCCESS;
  }

}


int delete_beginning_element(NodePtr *head,NodePtr *tail)
{
  if(*head==NULL || *tail==NULL)
  {
    printf("\nList to be deleted is empty!");
    return FALSE;
  }

  if(*head==*tail && (*head)->next==NULL && (*tail)->next==NULL) //only one element. No need of so many conditions (Only *head==*tail is sufficient)
  {
    NodePtr temp=*head;
    (*head)->next=NULL;
    (*tail)->prev=NULL;
    //*head->prev is always NULL && *tail->next is always NULL
    *head=NULL;
    *tail=NULL;

    int deleted_value=temp->value;
    free(temp);
    return deleted_value;
  }

  NodePtr temp=*head;
  if((*head)->next !=NULL) //Actually, it will always be NON-NULL, It will only be NULL if there is no element (or) there is only one element. Both these conditions are handled by previous conditional blocks.
  {
    *head=(*head)->next;
  }
  int deleted_value=temp->value;
  free(temp);
  return deleted_value;
}

void display_list(NodePtr head)
{
  printf("\nDisplay List:\n");
  while(head!=NULL)
  {
    printf("%d -> ",head->value);
    head=head->next;
  }
  printf("NULL\n");
}


int insert_sorted_ascending(NodePtr* head,NodePtr* tail,int val)
{

  NodePtr temp=malloc(sizeof(Node));

  if(!temp)
  {
    printf("\nCannot malloc node to be inserted\n");
    return FALSE;
  }


  temp->value=val;
  temp->next=NULL;

  if(*head==NULL)
  {
    temp->next=NULL;
    temp->prev=NULL;
    (*head)=temp;
    (*tail)=temp;
    return SUCCESS;
  }

  if((*head)->value >= temp->value)
  {
    temp->next=*head;
    (*head)->prev=temp;
    temp->prev=NULL;
    *head=temp;
    return SUCCESS;
  }
  NodePtr currptr=*head;
  while((currptr)->next && ((currptr)->next)->value < (temp->value))
  {
    currptr=currptr->next;
  }
  if((currptr->next)!=NULL)
  {
    temp->next=currptr->next;
    (currptr->next)->prev=temp;
    currptr->next=temp;
    temp->prev=currptr;
    return SUCCESS;
  }
  else
  {
    temp->next=currptr->next; //mostly NULL
    currptr->next=temp;
    temp->prev=currptr;
    *tail=temp;
    return SUCCESS;
  }
}

int main()
{
  printf("\nEntering Double Linked List:\n");
  int ret;
  int arr[]={4,3,2,5,6,4,3,2,1,9};
  int deleted_ele;
//Display List
  printf("\nActual List:\n");
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    printf("%d -> ",arr[i]);
  }
  printf("NULL\n");


  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;

  NodePtr headPtr2=NULL;
  NodePtr tailPtr2=NULL;

  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    ret=insert_sorted_ascending(&headPtr,&tailPtr,arr[i]);

  }
  printf("\nList in sorted ascending order:\n");
  display_list(headPtr);

  NodePtr currPtr=headPtr;

  while(currPtr!=NULL)
  {

    //Inserting each element of the array
    deleted_ele=delete_beginning_element(&headPtr,&tailPtr);
    currPtr=headPtr;
    ret=insert_beginning(&headPtr2,&tailPtr2,deleted_ele);

  }
  headPtr=headPtr2;
  tailPtr=tailPtr2;
  printf("\nReversed_list:\n");
  display_list(headPtr);
  return 0;
}
#endif
