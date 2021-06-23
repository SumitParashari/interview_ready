// For ascending order slection sort: O(n*n) - time complexity
// Find the minimum element in unsorted array and swap it with element at the begining.


#include <stdio.h>

#define MAX_SIZE 10
int time_complexity =0;

void selection_sort(int data[], int size)
{
     int i,j, min_index,tmp;
     for(i=0; i< size-1; i++)
     {
	     min_index = i;
	     time_complexity++;
	     for(j=i+1; j<size; j++)
	     {
		     time_complexity++;
		     if(data[j]<data[min_index])
		         min_index = j;
	     }
	     if(min_index != i)
	     {
		     tmp = data[i];
		     data[i] = data[min_index];
		     data[min_index] = tmp;
	     }
     }


     for(i=0; i < size; i++)
     {
            printf("%d ", data[i]);
     }
     printf("\n time_complexity %d\n",time_complexity);
}

int main()
{
	int i,data[MAX_SIZE];
        int size = sizeof(data)/sizeof(data[0]);
        
        printf("Enter %d number:\n", MAX_SIZE);	
	for(i=0; i < size; i++)
	{
	    scanf("%d", &data[i]);
	}
	selection_sort(data, size); 
}
