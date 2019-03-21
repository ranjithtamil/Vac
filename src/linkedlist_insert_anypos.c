

#include  <stdio.h>

typedef struct Node Node;
typedef struct Node* NodePtr;
struct Node
{
    int val;
    Node* next;
};


int insert(NodePtr* head, int val, int pos)
{
    NodePtr temp=(NodePtr)malloc(sizeof(Node));
    temp->val=val;

    if(pos==1)
    {
        temp->next=*head;
        *head=temp;
        return 1;
    }
    else
    {
        int i=1;
        NodePtr currptr=*head;
        NodePtr prevptr;
        while(currptr!=NULL && i<pos)
        {
            i++;
            prevptr=currptr;
            currptr=currptr->next;
        }
        //temp->next=currptr->next;
        //currptr->next=temp;
        temp->next=currptr;
        prevptr->next=temp;
        return 1;
    }
    
    return 0;
}
void display(NodePtr head)
{
 printf("\n");
    while(head!=NULL)
    {
        printf("%d",*head);
        printf("->");
        head=head->next;
    }
    printf("NULL\n");
    
}
int main()
{
    
    int arr[]={5,4,3,2,1,5,6,7,8,4};
    NodePtr head=NULL;
    int pos=1;
    for(int i=0;i<10;i++)
    {
        int ret=insert(&head,arr[i],pos);
        printf("\nreturnval=%d",ret);
    }
    display(head);
    
    int ret=insert(&head,10,3);
    display(head);
    
    ret=insert(&head,11,1);
    display(head);
    ret=insert(&head,99,13);
    
    display(head);
    ret=insert(&head,199,15);
    display(head);
    
    ret=insert(&head,399,14);
    display(head);
    
    return 0;
}
