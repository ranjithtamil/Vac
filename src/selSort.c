
#include <stdio.h>

int main()
{
    
   int arr[]={5,4,2,3,6,3,2,1,0,19};
   int N=10;
   int min;
   int temp;

   for(int i=0;i<N-1;i++)//N-1 passes sufficient.willbe left with last(biggest) element after N-1 passes
   {
      min=i;
      for(int j=i+1; j<N;j++) 
      {
         if(arr[min] > arr[j])
         {
            min=j;
         }      
      }
    
      //swapping operation   
      if(min!=i)//saves case when i is the minimum element-index 
      {
         temp=arr[i];
         arr[i]=arr[min];
         arr[min]=temp;
      }
   }
  
   for(int i=0;i<10;i++)
   {
      printf("%d ",arr[i]);
   }
  
   return 0;
}
  
