#define _CRT_SECURE_NO_WARNINGS 1  //only need this line if using Visual Studio
#define bool int
#define false 0
#define true (!false)

#include <stdio.h>
#define SIZE 6

//function prototypes
void linearSearch(int *, int, int, int);
bool binarySearch(int *, int, int, int);

int main() {
	bool found = false;
	int target = 7;
	int theArray[] = { 4, 6, 7, 23, 32, 41 };

	printf("Linear search call, search for 61..\n");
	linearSearch(theArray, 0, SIZE - 1, 61);

	printf("\nBinary search call, search for 7..\n");
	found = binarySearch(theArray, 0, SIZE - 1, target);
	if (found)
		printf("%d has been found\n", target);
	else
		printf("%d was not found\n", target);

}


void linearSearch(int *data, int min, int max, int target)
{
	int index = min;
	bool found = false;

	while (!found && index <= max)
	{
		if (data[index] == target)
			found = true;
		index++;
	}

	if (found)
		printf("%d has been found\n", target);
	else
		printf("%d was not found\n", target);
}


bool binarySearch(int* data, int min, int max, int target)
{
	bool found = false;
	int midpoint = (min + max) / 2;  // determine the midpoint

	if (data[midpoint] == target)
		found = true;
	else if (data[midpoint] > target)
	{
		if (min <= midpoint - 1)
			found = binarySearch(data, min, midpoint - 1, target);
	}
	else //if (data[midpoint] < target)
		if (midpoint + 1 <= max)
			found = binarySearch(data, midpoint + 1, max, target);

	return found;

}
