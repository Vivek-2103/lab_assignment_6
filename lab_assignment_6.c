#include <stdio.h>
#include <stdlib.h>

// This function takes a sorted array of numbers, two integers representing indexes into the array, and another integer to search for.
// It returns the index in the array where the search value is found between the indexes low and high (inclusive), or -1 if the value is not found.
int search(int numbers[], int low, int high, int value) 
{
	// If the low index is greater than the high index, then the search value is not present in the array between the given indexes.
	if (low > high) {
		return -1;
	}

	// Calculate the middle index of the array between the given indexes.
	int mid = (low + high) / 2;

	// If the middle element is equal to the search value, then we have found the value and can return its index.
	if (numbers[mid] == value) {
		return mid;
	}
	// If the middle element is greater than the search value, then the value must be in the left half of the array between the given indexes.
	else if (numbers[mid] > value) {
		return search(numbers, low, mid - 1, value);
	}
	// Otherwise, the middle element is less than the search value, so the value must be in the right half of the array between the given indexes.
	else {
		return search(numbers, mid + 1, high, value);
	}
}

void printArray(int numbers[], int sz)
{
	int i;
	printf("Number array : ");
	for (i = 0;i<sz;++i)
	{
		printf("%d ",numbers[i]);
	}
	printf("\n");
}

int main(void)
{
	int i, numInputs;
	char* str;
	float average;
	int value;
	int index;
	int* numArray = NULL;
	int countOfNums;
	FILE* inFile = fopen("input.txt","r");

	fscanf(inFile, " %d\n", &numInputs);
	
	while (numInputs-- > 0)
	{
		fscanf(inFile, " %d\n", &countOfNums);
		numArray = (int *) malloc(countOfNums * sizeof(int));
		average = 0;
		for (i = 0; i < countOfNums; i++)
		{
			fscanf(inFile," %d", &value);
			numArray[i] = value;
			average += numArray[i];
		}

		printArray(numArray, countOfNums);
		value = average / countOfNums;
		index = search(numArray, 0, countOfNums - 1, value);
		if (index >= 0)
		{
			printf("Item %d exists in the number array at index %d!\n",value, index);
		}
		else
		{
			printf("Item %d does not exist in the number array!\n", value);
		}

		free(numArray);
	}

	fclose(inFile);
}
