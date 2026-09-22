/*
 * C Program to Find 2 Elements in the Array such that Difference between them is Largest
 */
 #include <stdio.h>
 
int maximum_difference(int array[], int arr_size)
{
    int max_diff =  0;
    int max=array[0], min=array[0];
    int i, j;

    for (i = 1; i < arr_size; i++)
    {
        if (array[i] > max) {
            max = array[i];
        } else if (array[i] < min) {
            min = array[i];
        }
    }
    return (max_diff = max - min);
}
 
int main()
{
    int array[] = {1000, 115, 20, 20, 130};
    printf("Maximum difference is %d",  maximum_difference(array, 5));
    getchar();
    return 0;
}
