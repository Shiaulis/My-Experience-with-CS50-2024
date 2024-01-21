Now we are taking break on syntax and check more algorithms. We have enough vocabulary to solve problems. We are learning how to think algorithmically. How to solve real life problems and quantize them into puzzle pieces.
Recall what is array and how it is located in memory.

# Search Problem
Input - 7 lockers
Output - bool, `true` or `false` to share if those lockers contain particular information.

## Linear search
Searching L→R or R→L
pseudocode:
```
For i in 0 to n-1
	If 50 is behind doors[i]
		Return true
Return false
```
## Binary Search
```
If no doors left
	Return false
If 50 is behind door[middle]
	Return true
Else if 50 < door[middle]
	Search doors[0] through doors[middle - 1]
Else if 50 > door[middle]
	Search doors[middle + 1] through doors[n - 1]
```

# Complexity of Algorithms
- $O(n^2)$
- $O (n*\log n)$
- $O(n)$ - quadratic
- $O(log n)$ - logarithmic
- $O(1)$ - constant
$\Omega$ - can be used in the same way as $O$ but from the opposite perspective: how few steps can be made.
$\theta$ - when both algorithms are equal.

# Linear Search Implementation in C
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{

	int numbers[] = {20, 500, 10, 5, 100, 1, 50};
	int n = get_int("Number: ");

	for (int i = 0; i < 7; i++)
	{
		if (numbers[i] == n)
		{
			printf("Found\n");
			return 0;
		}
	}

	printf("Not found\n");
	return 1;
}
```

Strings version:
```c
int main(void)
{
    string strings[] = {"battleship", "boot", "cannon", "iron", "thimble", "top hat"};

    string s = get_string("String: ");
    for (int i = 0; i < 6; i++)
    {
        if (strcmp(strings[i], s) == 0)
        {
            printf("Found\n");
            return 0;
        }
    }

    printf("Not found\n");
    return 0;
}
```
# Phonebook App
```C
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    // Arrays of strings
    string names[] = {"Carter", "David", "John"};
    string numbers[] = {"+1-617-495-1000", "+1-617-495-1000", "+1-949-468-2750"};

    // Search for name
    string name = get_string("Name: ");
    for (int i = 0; i < 3; i++)
    {
        if (strcmp(names[i], name) == 0)
        {
            printf("Found %s\n", numbers[i]);
            return 0;
        }
    }
    printf("Not found\n");
    return 1;
}
```

# Data Structures

We can use data structure to represent contact:
```C
typedef struct
{
    string name;
    string number;
}
person;
```

# Sorting
Covered several algorithms of sorting, like bubble sort, selecting sort, etc.
## Selecting Sort
$O(n^2)$ $\Omega(n^2)$ $\Theta(n^2)$
```
for i from 0 to n-1
	Find smallest number between numbers[i] and numbers[n-1]
	Swap smallest number with number [i]
```

## Bubble Sort
$O(n^2)$ $\Omega(n)$
```
Repeat n-1 time
	For i from 0 to n-2
		If numbers[i] and number [i+1] out of order
			Swap them
	If no swaps
		Quit
```

Sorting algorithm cannot take less than $n$.

## Merge Sort
$O(n \log n)$ $\Omega(n \log n)$ $\Theta(n \log n)$ 
```
If only one number
	Quit
Else
	Sort left half of number
	Sort right half of number
	merge sorted halves
```

# Problem Set 3
## Sort
| Program | Random 50k | Sorted 50k |
| ---- | ---- | ---- |
| Sort 1 | 5.814 | 0.384 |
| Sort 2 | 0.447 | 0.567 |
| Sort 3 | 2.512 | 2.423 |
## Runoff
https://cs50.harvard.edu/x/2024/psets/3/runoff/
