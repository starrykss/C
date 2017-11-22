/*
// C program to sort elements of array in descending order

#include <stdio.h>

int main()
{
	int arr[100];
	int size, i, j, temp;

	// Read size of array and elements in array

	printf("Enter size of array: ");
	scanf("%d", &size);

	printf("Enter elements in array: ");
	for (i = 0; i<size; i++)
	{
		scanf("%d", &arr[i]);
	}

	// Array sorting code

	for (i = 0; i<size; i++)
	{
		for (j = i + 1; j<size; j++)
		{

			// If there is a smaller element towards left of the array then swap it.

			if (arr[i] < arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}


	// Prints the sorted array

	printf("\nElements of array in sorted descending order: ");
	for (i = 0; i<size; i++)
	{
		printf("%d\t", arr[i]);
	}

	return 0;
}
*/