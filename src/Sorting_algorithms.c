#include<stdio.h>
#include<stdlib.h>
#define TRUE 1
#define FALSE 0
#define SUCCESS 1
//1. Selection_Sort - iterates over list, finds smallest element of unsorted side of list, and adds it to sorted subarray of list.
//#define Selection_Sort

//2. Insertion Sort -
//#define Insertion_Sort

//3. Merge Sort -
#define Merge_Sort

//Selection_Sort
#ifdef Selection_Sort
int selsort(int *arra, int len)
{
  printf("\nBefore Sorting:\n");
  for(int i=0;i<len;i++)
  {
    printf("\n%d",arra[i]);

  }
int min_index;
int n=len;
for(int i=0;i<=n-2;i++)
{
  int min_index=i;
  for(int j=i+1;j<=n-1;j++)
  {
    if(arra[j]<arra[min_index])
    {
      min_index=j;
    }
  }
  //Swap arr[i] & arr[min_index]

  int temp=arra[i];
  arra[i]=arra[min_index];
  arra[min_index]=temp;

}

  return SUCCESS;
}

int main()
{
int arr[]={5,4,3,2,5,4,3,0,1,10};

int arr_length=((sizeof(arr))/(sizeof(int)));
int ret=FALSE;
ret=selsort(arr,arr_length);


  printf("\nAfter Sorting:\n");
  for(int i=0;i<arr_length;i++)
  {
    printf("\n%d",arr[i]);

  }
  printf("\n");
}



#if 0
//  4_a 5 3 2 4_b 1

//=>1 5 3 2 4_b 4_a

//=>1 2 3 5 4_b 4_a

//=>1 2 3 4_b 5 4_a

//=>1 2 3 4_b 4_a 5

//=> Sorted. But instead of 4_a and then 4_b as in input, it is sorted to 4_b and then 4_a. This is called unstable Sorting. Thus to solve it, Insertion sort is used.
#endif
#endif
//Selection_Sort is unstable algorithm..

//Insertion_Sort
//Insertion_Sort is stable algorithm
#ifdef Insertion_Sort
int more(int a,int b)
{
  if(a>b)
  {
    return 1;
  }
  else
  {
    return 0;
  }
}
int insertion_sort(int *arra, int len)
{
  int n=len;
  for(int i=1;i<=n-1;i++)
  {
    int temp=arra[i];
    int j;
    for(j=i;j>=1 && more(arra[j-1],temp);j--)
    {
      arra[j]=arra[j-1];
    }
    arra[j]=temp;
  }

  return SUCCESS;
}
int main()
{
  int arr[]={5,4,3,2,5,4,3,0,1,10};

  int arr_length=((sizeof(arr))/(sizeof(int)));
  int ret=FALSE;
  ret=insertion_sort(arr,arr_length);


    printf("\nAfter Sorting:\n");
    for(int i=0;i<arr_length;i++)
    {
      printf("\n%d",arr[i]);

    }
    printf("\n");
}
#endif
//Insertion_Sort is stable algorithm


//Merge_Sort
//https://www.geeksforgeeks.org/merge-sort/
#ifdef Merge_Sort

void Merge(int *arra,int l,int m,int r)
{
  int n1=m - l + 1; //no of elements in first half (l ... m)
  int n2=r - m; //no of elements in second half (m+1 ... r), i.e. (r - (m+1) +1)

  int L[n1];
  int R[n2];
int i,j,k;
  for(i=0;i<n1;i++)
  {
    L[i]=arra[l+i];
  }

  for(j=0;j<n2;j++)
  {
    R[j]=arra[m+1+j];
  }
i=0;
j=0;
  for(k=l;i<n1 && j<n2;)   //very important that k = l. If k were 0 it wil start with k = 0 for even subarrays.Also important that limits are i<n1 && j<n2.
  {
    if(L[i] <= R[j])
    {
      arra[k]=L[i];
      i++;
    }
    else
    {
      arra[k]=R[j];
      j++;
    }
    k++;
  }
  while(i < n1)
  {
    arra[k]=L[i];
    i++;
    k++;
  }
  while(j < n2)
  {
    arra[k]=R[j];
    j++;
    k++;
  }

}
void Merge_sort(int *arra,int l,int r)
{

  if(l<r)
  {
    int m=l+(r-l)/2; //very important :- mid element = left + ((right-left)/2 );
    Merge_sort(arra,l,m);
    Merge_sort(arra,m+1,r);

    Merge(arra,l,m,r);

  }
}
int main()
{

  int arr[]={5,4,3,2,5,4,3,0,1,10};

  int arr_length=((sizeof(arr))/(sizeof(int)));
  int ret=FALSE;
  int l=0,r=arr_length - 1;
  Merge_sort(arr,l,r);


    printf("\nAfter Sorting:\n");
    for(int i=0;i<arr_length;i++)
    {
      printf("\n%d",arr[i]);

    }
    printf("\n");
}

#endif
