#include<stdio.h>
void insertion_sort(int arr[], int size)
{	int i,j,temp;
	for(i=1;i<size;i++)
	{
		temp=arr[i];
		j=i-1;
		while( ( temp<arr[j] ) && ( j>=0 ) )
		{
         arr[j+1] = arr[j];
         j=j-1;
    	}
      arr[j+1]=temp;
	}
}

int main()
{
	int arr[100],i,j,temp,size;
	printf("Enter the size of the array : ");					
	scanf("%d",&size);												//reading the size of the array
	printf("Type the unsorted array : ");							
	for(i=0;i<size;i++)
	{
		scanf("%d",&arr[i]);										//reading the elements of the array
	}
	insertion_sort(arr,size);
	printf("the sorted array is : ");
	for(i=0;i<size;i++)
	{
		printf("%d ",arr[i]);										//printing the elements of the array
	}
	return 0;
}

