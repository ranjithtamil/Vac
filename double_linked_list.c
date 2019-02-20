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

//Code to insert element at beginning of double linked list
//#define Insert_beginning

//Code to insert element at end of double linked list
//#define Insertion_end

//Code to insert element in sorted linked list (Descending order)
//#define Insert_descending

//Code to insert element in sorted linked list (Ascending order)
//#define Insert_ascending

//Code to reverse double linked List
//#define Reverse_list

//Code to delete element from beginning
//#define delete_beginning

//Code to delete element from end
#define delete_end

//Code to delete element from end
//#define delete_end

//Code to Delete all occurrences in double linked List
//#define delete_occurrences

#ifdef Insert_beginning

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
int main()
{
  printf("\nEntering Double Linked List:\n");
  int ret;
  int arr[]={4,3,2,5,6,4,3,2,1,9};

//Display List
  printf("\nActual List:\n");
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    printf("%d -> ",arr[i]);
  }
  printf("NULL\n");


  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;


  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    ret=insert_beginning(&headPtr,&tailPtr,arr[i]);

  }

  display_list(headPtr);
  return 0;
}
#endif

#ifdef Insertion_end

int insert_end(NodePtr* head,NodePtr* tail,int val)
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
    temp->prev=(*tail);
    temp->next=(*tail)->next; //mostly tail->next is NULL. So its as good as saying temp->next=NULL
    (*tail)->next=temp;
    (*tail)=temp;
    return SUCCESS;
  }
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
int main()
{
  printf("\nEntering Double Linked List:\n");
  int ret;
  int arr[]={4,3,2,5,6,4,3,2,1,9};

//Display List
  printf("\nActual List:\n");
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    printf("%d -> ",arr[i]);
  }
  printf("NULL\n");


  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;


  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    ret=insert_end(&headPtr,&tailPtr,arr[i]);

  }

  display_list(headPtr);
  return 0;
}
#endif

#ifdef Insert_descending
int insert_sorted_descending(NodePtr* head,NodePtr* tail,int val)
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

  if((*head)->value <= temp->value)
  {
    temp->next=*head;
    (*head)->prev=temp;
    temp->prev=NULL;
    *head=temp;
    return SUCCESS;
  }
  NodePtr currptr=*head;
  while((currptr)->next && ((currptr)->next)->value > (temp->value))
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
int main()
{
  printf("\nEntering Double Linked List:\n");
  int ret;
  int arr[]={4,3,2,5,6,4,3,2,1,9};

//Display List
  printf("\nActual List:\n");
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    printf("%d -> ",arr[i]);
  }
  printf("NULL\n");


  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;


  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    ret=insert_sorted_descending(&headPtr,&tailPtr,arr[i]);

  }

  display_list(headPtr);
  return 0;
}
#endif

#ifdef Insert_ascending
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
int main()
{
  printf("\nEntering Double Linked List:\n");
  int ret;
  int arr[]={4,3,2,5,6,4,3,2,1,9};

//Display List
  printf("\nActual List:\n");
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    printf("%d -> ",arr[i]);
  }
  printf("NULL\n");


  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;


  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    ret=insert_sorted_ascending(&headPtr,&tailPtr,arr[i]);

  }

  display_list(headPtr);
  return 0;
}
#endif


//TODO: Delete occurrences
#ifdef delete_occurrences
#endif

#ifdef delete_beginning
//TODO
//Returns the deleted element value
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
int main()
{
  printf("\nEntering Double Linked List:\n");
  int ret;
  int arr[]={4,3,2,5,6,4,3,2,1,9};

//Display List
  printf("\nActual List:\n");
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    printf("%d -> ",arr[i]);
  }
  printf("NULL\n");


  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;


  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    ret=insert_sorted_ascending(&headPtr,&tailPtr,arr[i]);

  }
  printf("\nList in sorted ascending order:\n");
  display_list(headPtr);

  //Going to delete elements one by one
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    printf("\nDelete:PASS %d\n",i);
    ret=delete_beginning_element(&headPtr,&tailPtr);

    display_list(headPtr);

  }
  printf("\nAfter Deleting all elements one by one\n");
  display_list(headPtr);
  return 0;
}
#endif

#ifdef delete_end
int delete_end_element(NodePtr *head,NodePtr *tail)
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

  NodePtr temp=*tail;
  ((*tail)->prev)->next=(*tail)->next;  //Mostly *tail->next is NULL.
  *tail=(*tail)->prev;
  temp->next=NULL;  //TODO: Not sure if this is needed. It would have been null anyway
  temp->prev=NULL;  //TODO: Not sure if this is needed.This was previously pointing to second but last element(which is tail once this element is removed from end)
  int deleted_value=temp->value;
  free(temp);
  return deleted_value;
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
int main()
{
  printf("\nEntering Double Linked List:\n");
  int ret;
  int arr[]={4,3,2,5,6,4,3,2,1,9};

//Display List
  printf("\nActual List:\n");
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    printf("%d -> ",arr[i]);
  }
  printf("NULL\n");


  NodePtr headPtr=NULL;
  NodePtr tailPtr=NULL;


  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    ret=insert_sorted_ascending(&headPtr,&tailPtr,arr[i]);

  }
  printf("\nList in sorted ascending order:\n");
  display_list(headPtr);

  //Going to delete elements one by one
  for(int i=0;i<((sizeof(arr))/(sizeof(int)));i++)
  {
    ret=FALSE;
    //Inserting each element of the array
    printf("\nDelete:PASS %d\n",i);
    ret=delete_end_element(&headPtr,&tailPtr);

    display_list(headPtr);

  }
  printf("\nAfter Deleting all elements one by one\n");
  display_list(headPtr);
  return 0;
}
#endif
