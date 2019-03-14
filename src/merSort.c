#include<stdio.h>

void mergeSort(int arr[],int l,int r);
void merge(int arr[],int l,int m,int r);
void printArray(int arr[], int arr_size);
void mergeSort(int arr[],int l,int r)
{
  if(l<r)
  {
    int m=l + (r-l)/2;
    mergeSort(arr,l,m);
    mergeSort(arr,m+1,r);
    merge(arr,l,m,r);
  }
}
int main()
{

  int arr[]={25,50,43,23,54,34,90,23};

  int arr_size=sizeof(arr)/sizeof(arr[0]);

  printArray(arr, arr_size);
  mergeSort(arr,0,arr_size-1);
  printArray(arr, arr_size);
  return 0;
}
void merge(int arr[],int l,int m,int r)
{
  int n1=m-l+1;
  int n2=r-m;

  int L[n1];
  int R[n2];

  for(int i=0;i<n1;i++)
  {
    L[i]=arr[i+l];
  }

  for(int j=0;j<n2;j++)
  {
    R[j]=arr[m+1+j];
  }

  int i=0;
  int j=0;
  int k=l;
  while(i<n1 && j<n2)
  {
    if(L[i]<=R[j])
    {
      arr[k]=L[i];
      k++;
      i++;
    }
    else
    {
      arr[k]=R[j];
      k++;
      j++;
    }

  }

  while(i<n1)
  {
    arr[k]=L[i];
    i++;
    k++;
  }

  while(j<n2)
  {
    arr[k]=R[j];
    j++;
    k++;
  }

}


void printArray(int A[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}
