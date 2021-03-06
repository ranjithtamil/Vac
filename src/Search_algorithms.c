#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define FALSE 0
#define TRUE 1

// Linear search
// #define Linear_Search


// Binary search (Search for first occurrence).
// #define Binary_Search

//#define Binary_Search_efficient

//#define debug_bin //(Debugging for Binary Search)

//Binary Search for Multiple Occurrence.
//#define Binary_Search_multiple_occurrence

//ToDo : Jump search
#define jump_search

#ifdef Jump_Search_Theory
/*Theory of Jump search

Similar to binary search, but we jump blocks at a time. In a sorted array,
Suppose we have an sorted array of elements : 1,2,3,4,5,6,7,8,9
No. of elements (n) = 9 . Then suppose we have jump size (m) = 3.

Let's say we want to search for number 7.
First we jump to number 3. ( 7 > 3 , so jump again. )
Then we jump to number 6.  ( 7 > 6 , so jump again. )
Then we jump to number 9.  ( 7 < 9 , so dont jump again. Track back one by one until m-1 times, i.e. 3-1=2 times).
7 Found

**********************************************************

Thus in worst case, we may have to jump maximum times (in case of element size=9, jumpsize=3)
We have maximum number of jumps = (elementsize n / jumpsize m ) = 3.
Maximum no of jumps possible = 3.
Max jumps = n/m
Max Linear Traversal (Back tracking) = m-1
Also, worst case traversal in this case is for element 7 (which is Max jumps + Max Linear Traversal )
                                                      = ( n/m + (m-1))

Therefore, worst case traversal = n/m + m-1.
What should be ideal jumpblock size ?
To find this , minimise worst case traversal w.r.t jumpblock size.

i.e., minimise (n/m + m-1) w.r.t (m)

thus { d/dm (n/m + m-1) = 0 }
=>   { (-n/m^2) + 1 = 0 }
=>   { (-n/m^2) = -1 }
=>   { (n) = m^2 }
=>   { (m) = root(n) }


Thus, for best performance, Jump Block size should be selected as root of total number of elements
in sorted array

*/
#endif


typedef struct Node Node;
struct Node {
  int val;
  Node * next;
};

typedef Node* NodePtr;
int InsertNode(NodePtr* head, int value)
{
  NodePtr temp=malloc(1*sizeof(Node));
  temp->val=value;
  temp->next=NULL;
  if(*head==NULL)
  {
    *head=temp;
    return TRUE;
  }

  NodePtr currptr=*head;
  if(currptr->val > value)
  {
    temp->next=*head;
    *head=temp;
    return TRUE;
  }
  while((currptr->next) && currptr->next->val<value)
  {
    currptr=currptr->next;
  }
  temp->next=currptr->next;
  currptr->next=temp;
  return TRUE;
}
int InsertNodeEnd(NodePtr* head,int value)
{
  NodePtr temp=malloc(sizeof(Node));
  temp->val=value;
  temp->next=NULL;
  if(*head==NULL)
  {
    *head=temp;
    return TRUE;
  }
  NodePtr curr=*head;
  while(curr->next!=NULL)
  {
    curr=curr->next;
  }
  curr->next=temp;
  return TRUE;
}
void displaylist(NodePtr head)
{
  while(head!=NULL)
  {
    printf("    %d\n",head->val);
    head=head->next;
  }
}
#ifdef Binary_Search_efficient
int binsearch(int arr[],int start,int end,int num)
{
  if(end<start)
  return -1;

int mid = start+((end-start)/2);
if(arr[mid]==num)
{
  printf("\nFound");
  printf("\nPosition %d",mid);
  return 1;
}
else if(arr[mid]<num)
{
  return binsearch(arr,mid+1,end,num);
}
return binsearch(arr,start,mid-1,num);
}
#endif
int main()
{

  #ifdef Linear_Search
  NodePtr head=NULL;
  int ret;
  int numarray[]={10,9,1,2,3,4,5,6,7,8,10,10,10,10,10,10,9,2,3,4};
  int num,no_of_instances=0;

  printf("\nEnter number to be searched:   ");
  scanf("%d",&num);

  int found=FALSE;
  for(int i=0;i<20;i++)
  {
    if(numarray[i]==num)
    {
      found=TRUE;
      ret=FALSE;
      ret=InsertNode(&head,(i+1));
      if(ret==FALSE)
      {
        printf("\nInsertion_error");
        break;
      }
      else
      {
        no_of_instances++;
      }
    }
  }
  if(found==FALSE)
  {
    printf("\n  Element Not found");
  }
  else
  {
    printf("\n  Element found. No of instances=%d",no_of_instances);
    printf("\n  Positions\n");
    displaylist(head);
  }

  return 0;
  #endif

  #ifdef Binary_Search
  NodePtr head=NULL;
  int ret;
  int numarray[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
  int num_of_elements=20;
  int num,no_of_instances=0;
  #ifndef debug_bin
  printf("\nEnter number to be searched:   ");
  scanf("%d",&num);
  #endif
  #ifdef debug_bin
  num=9;
  #endif
  int found=FALSE;

  int start=0,end=num_of_elements-1,mid;

  while(start!=end)
  {

    #ifdef debug_bin
    printf("\nEnter loop start = %d,end = %d",start,end);
    #endif
    if((end-start + 1)%2 != 0) //Odd number of Elements
    {

        #ifdef debug_bin
        printf("\nOdd num ");
        #endif
      mid=start + ((end-start +1)/2);
        #ifdef debug_bin
        printf("\nMid = %d ",mid);
        #endif
      if(numarray[mid]==num)
      {
        found = TRUE;
        #ifdef debug_bin
        printf("\nFound. pos=%d ",mid);
        #endif
        ret=FALSE;

        #ifdef debug_bin
        printf("\nInserting ");
        #endif
        ret=InsertNode(&head,mid);
        #ifdef debug_bin
        printf("\nFinished");
        #endif
        //This wont find all occurrences. breaking once first occurence is found
        break;

      }
      else if(numarray[mid]>num)
      {
        #ifdef debug_bin
        printf("\nnum[mid]>num. mid=%d,num=%d,num[mid]=%d. so set end=mid-1",mid,num,numarray[mid]);
        printf("Current start = %d,end = %d",start,end);
        #endif
        end=mid-1;
      }
      else
      {
          #ifdef debug_bin
          printf("\nnum[mid]<num. mid=%d,num=%d,num[mid]=%d. so set start=mid+1",mid,num,numarray[mid]);
          printf("Current start = %d,end = %d",start,end);
          #endif
        start=mid+1;
      }
    }
    else  //Even number of elements
    {
      #ifdef debug_bin
      printf("\nEven num ");
      #endif

      mid=start + ((end-start+1)/2);
      #ifdef debug_bin
      printf("\nMid = %d ",mid);
      #endif

      if(numarray[mid]==num)
      {
        found=TRUE;

        #ifdef debug_bin
        printf("\nFound. pos=%d ",mid);
        #endif


        ret=FALSE;
        #ifdef debug_bin
        printf("\nInserting ");
        #endif
        ret=InsertNode(&head,mid);
        #ifdef debug_bin
        printf("\nFinished");
        #endif
        //This wont find all occurrences. breaking once first occurence is found
        break;

      }
      else if(numarray[mid]>num)
      {
        #ifdef debug_bin
        printf("\nnum[mid]>num. mid=%d,num=%d,num[mid]=%d. so set end=mid-1",mid,num,numarray[mid]);
        printf("Current start = %d,end = %d",start,end);
        #endif
        end=mid-1;
      }
      else
      {
        #ifdef debug_bin
        printf("\nnum[mid]<num. mid=%d,num=%d,num[mid]=%d. so set start=mid+1",mid,num,numarray[mid]);
        printf("Current start = %d,end = %d",start,end);
        #endif
        start=mid+1;
      }
    }
  }

#ifdef debug_bin
printf("Finished looping. Now start=%d end=%d",start,end);
#endif

  if(start==end)
  {
  if(numarray[start]==num)
  {
    #ifdef debug_bin
    printf("\nFound. pos=%d ",start);
    #endif

    found=TRUE;
    ret=FALSE;

    #ifdef debug_bin
    printf("\nInserting ");
    #endif
    ret=InsertNode(&head,start);
    #ifdef debug_bin
    printf("\nFinished");
    #endif
  }
  }

  if(found==FALSE)
  {
    printf("\nElement not found");
  }
  else
  {
    printf("\nElement found");
    printf("\nPositions:");
    displaylist(head);
  }
  return 0;
  #endif

  #ifdef Binary_Search_multiple_occurrence
  NodePtr head=NULL;
  int ret;
  int numarray[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,14,14,14,15,15,17};
  int num_of_elements=20;
  int num,no_of_instances=0;
  #ifndef debug_bin
  printf("\nEnter number to be searched:   ");
  scanf("%d",&num);
  #endif
  #ifdef debug_bin
  num=14;
  #endif
  int found=FALSE;

  int start=0,end=num_of_elements-1,mid;

  while(start!=end)
  {

    #ifdef debug_bin
    printf("\nEnter loop start = %d,end = %d",start,end);
    #endif
    if((end-start + 1)%2 != 0) //Odd number of Elements
    {

        #ifdef debug_bin
        printf("\nOdd num ");
        #endif
      mid=start + ((end-start +1)/2);
        #ifdef debug_bin
        printf("\nMid = %d ",mid);
        #endif
      if(numarray[mid]==num)
      {
        found = TRUE;
        #ifdef debug_bin
        printf("\nFound. pos=%d ",mid);
        #endif
        ret=FALSE;

        #ifdef debug_bin
        printf("\nInserting ");
        #endif
        ret=InsertNode(&head,mid);
        #ifdef debug_bin
        printf("\nFinished");
        #endif

        for(int j=mid+1;j<=end;j++)
        {
          if(numarray[j]==num)
          {
            found=TRUE;
            #ifdef debug_bin
            printf("\nInserting ");
            #endif
            InsertNode(&head,j);
            #ifdef debug_bin
            printf("\nFinished");
            #endif
          }
          else
          {
            break;
          }
        }
        for(int k=mid-1;k>=start;k--)
        {
          if(numarray[k]==num)
          {
            found=TRUE;
            #ifdef debug_bin
            printf("\nInserting ");
            #endif
            InsertNode(&head,k);
            #ifdef debug_bin
            printf("\nFinished");
            #endif
          }
          else
          {
            break;
          }
        }
        break;
      }
      else if(numarray[mid]>num)
      {
        #ifdef debug_bin
        printf("\nnum[mid]>num. mid=%d,num=%d,num[mid]=%d. so set end=mid-1",mid,num,numarray[mid]);
        printf("Current start = %d,end = %d",start,end);
        #endif
        end=mid-1;
      }
      else
      {
          #ifdef debug_bin
          printf("\nnum[mid]<num. mid=%d,num=%d,num[mid]=%d. so set start=mid+1",mid,num,numarray[mid]);
          printf("Current start = %d,end = %d",start,end);
          #endif
        start=mid+1;
      }
    }
    else  //Even number of elements
    {
      #ifdef debug_bin
      printf("\nEven num ");
      #endif

      mid=start + ((end-start+1)/2);
      #ifdef debug_bin
      printf("\nMid = %d ",mid);
      #endif

      if(numarray[mid]==num)
      {
        found=TRUE;

        #ifdef debug_bin
        printf("\nFound. pos=%d ",mid);
        #endif


        ret=FALSE;
        #ifdef debug_bin
        printf("\nInserting ");
        #endif
        ret=InsertNode(&head,mid);
        #ifdef debug_bin
        printf("\nFinished\n");
        #endif


                for(int j=mid+1;j<=end;j++)
                {
                  if(numarray[j]==num)
                  {
                    found=TRUE;
                    #ifdef debug_bin
                    printf("\nInserting ");
                    #endif

                    InsertNode(&head,j);
                    #ifdef debug_bin
                    printf("\nFinished\n");
                    #endif
                  }
                  else
                  {
                    break;
                  }
                }
                for(int k=mid-1;k>=start;k--)
                {
                  if(numarray[k]==num)
                  {
                    found=TRUE;
                    #ifdef debug_bin
                    printf("\nInserting ");
                    #endif
                    InsertNode(&head,k);
                    #ifdef debug_bin
                    printf("\nFinished\n");
                    #endif
                  }
                  else
                  {
                    break;
                  }
                }
                break;
      }
      else if(numarray[mid]>num)
      {
        #ifdef debug_bin
        printf("\nnum[mid]>num. mid=%d,num=%d,num[mid]=%d. so set end=mid-1",mid,num,numarray[mid]);
        printf("Current start = %d,end = %d",start,end);
        #endif
        end=mid-1;
      }
      else
      {
        #ifdef debug_bin
        printf("\nnum[mid]<num. mid=%d,num=%d,num[mid]=%d. so set start=mid+1",mid,num,numarray[mid]);
        printf("Current start = %d,end = %d",start,end);
        #endif
        start=mid+1;
      }
    }
  }

#ifdef debug_bin
printf("\nFinished looping. Now start=%d end=%d",start,end);
#endif

  if(start==end)
  {
  if(numarray[start]==num)
  {
    #ifdef debug_bin
    printf("\nFound. pos=%d ",start);
    #endif

    found=TRUE;
    ret=FALSE;

    #ifdef debug_bin
    printf("\nInserting ");
    #endif
    ret=InsertNode(&head,start);
    #ifdef debug_bin
    printf("\nFinished");
    #endif
  }
  }

  if(found==FALSE)
  {
    printf("\nElement not found");
  }
  else
  {
    printf("\nElement found");
    printf("\nPositions:\n");
    displaylist(head);
  }
  return 0;
  #endif

  #ifdef Binary_Search_efficient

NodePtr head=NULL;
int ret;
int numarray[]={1,2,3,4,5,6,7,8,9,10,11,12,13,14,14,14,14,15,15,17};
int num_of_elements=20;
int num,no_of_instances=0;
num=13; //num to search for
int fnd=-1;

fnd=binsearch(numarray,0,num_of_elements-1,num);
if(fnd==-1){printf("\nElement not found or list empty");}
  #endif

  #ifdef jump_search
  int a[]={1,2,3,4,5,6,7,8,9};
  int found=-1;
  int max = 9;
  //(sizeof(a)/sizeof(int)); // number of elements
  int num; //element to be searched
  printf("\nEnter number to be searched: ");
  scanf("%d",&num);

  int ele = sqrt(max);  //jump block size
  int curr = ele - 1; //index of initial element

  while(curr <= max)
  {
    if(a[curr] == num)
    {
      found=TRUE;
      printf("\n %d\n",curr);
      break;
    }
    else if(a[curr] < num)
    {
      curr=curr+ele;
    }
    else
    {
      for(int i = curr; i>= (curr - (ele-1)); i-- )
      {
        if(a[i] == num)
        {
          found=TRUE;
          printf("\n %d\n",i);
          break;
        }
      }
      break;
    }




  }
  if(found==-1)
  {
    printf("\nNot found\n");
  }
  #endif
}
