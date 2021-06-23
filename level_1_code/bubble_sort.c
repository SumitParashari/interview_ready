// For bubble sort - O(n*n) - Worst case 
// repeatedly swap two adjacent elements if they are in wrong order

#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 10
int time_complexity = 0;
void bubble_sort(int data[], int count)
{
	int i,j,tmp = 0;
	bool swapped;
        
	for(i=0; i<count-1; i++)
	{
		time_complexity++;
		swapped = false;
		for(j=0; j<count-i-1; j++)
		{
			time_complexity++;
			if(data[j]>data[j+1])
			{
				tmp = data[j];
				data[j] = data[j+1];
				data[j+1] = tmp;
				swapped = true;
			}
		}
		if(swapped == false)
		{
			printf("Sorting done!\n");
			break;
		}
	}
	for(i=0; i<count; i++)
	{
		printf("%d ", data[i]);
	}
	printf("\n time complexity %d\n", time_complexity);
}

int main()
{
	int i,data[MAX_SIZE];
	printf("Enter %d numbers:\n", MAX_SIZE);
	for(i=0; i< MAX_SIZE; i++)
	{
		scanf("%d",&data[i]);
	}
	bubble_sort(data, MAX_SIZE);

}
