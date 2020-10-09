#include<stdio.h>
#include<math.h>
#include<stdlib.h>
int partition(int a[],int lb,int ub);
void quicksort(int a[],int lb,int ub);
void main()
{
 int arr[1000],n,i,lb,ub;
 printf("Array Size \n");
 scanf("%d",&n);
 printf("Enter elements in array \n");
 for(i=0;i<n;i++)
 {
    scanf("%d",&arr[i]);
 }
 lb = 0;
 ub = n-1;
 quicksort(arr,lb,ub);
 printf("Sorted array \n");
 for(i=0;i<n;i++)
 {
   printf("%d \n",arr[i]);
 }
}

int partition(int a[],int lb,int ub)
{
 int pivot,start,end,temp;
 pivot = a[lb];
 start = lb;
 end = ub;
 while(start<end)
 {
    while(a[start]<=pivot && start<ub)
    {
      start++;
    }
    while(a[end]>pivot && end>lb)
    {
      end--;
    }
    if(start<end)
    {
    temp = a[start];
    a[start] = a[end];
    a[end] = temp;
    }
 }
 temp = a[lb];
 a[lb] = a[end];
 a[end] = temp;
 return end;
}

void quicksort(int a[],int lb,int ub)
{
  if(lb<ub)
  {
    int loc = partition(a,lb,ub);
    quicksort(a,lb,loc-1);
    quicksort(a,loc-1,ub);
  }
}
