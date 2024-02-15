URL https://youtu.be/0euvEdPwQnQ
- Stacks
- Queues
```c
const int CAPACITY = 50;
typedef struct
{
	person people[CAPACITY];
	int size;
} queue;
```

```c
const int CAPACITY = 50;
typedef struct
{
	person people[CAPACITY];
	int size;
} stack;

```

# Array Resizing
Let's have a code that just makes array
```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *list = malloc(3 * sizeof(int));
	// let's do this check each time after malloc
	// to ensure we have memory allocated
	if (list == NULL)
	{
		return 1;
	}

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	for(int i = 0; i < 3; i++)
	{
		printf("%i\n", list[i]);
	}
}
```

Now let's improve this array so it would be possible dynamically allocate memory

```c
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int *list = malloc(3 * sizeof(int));
	// let's do this check each time after malloc
	// to ensure we have memory allocated
	if (list == NULL)
	{
		return 1;
	}

	list[0] = 1;
	list[1] = 2;
	list[2] = 3;

	int *tmp = malloc(4 * sizeof(int));
	if (tmp == NULL)
	{
		free(list);
		return 1;
	}

	for(int i = 0; i < 4; i++)
	{
		tmp[i] = list[i];
	}
	tmp[3] = 4;

	free(list);
	list = tmp;

	for(int i = 0; i < 3; i++)
	{
		printf("%i\n", list[i]);
	}

	free(list);
	return 0;
}
```

# Linked Lists
# Trees
Each tree contains of leaf nodes as well as root node. Each nodes have 2 pointers, specifically for binary trees. Each node has bigger values on the right and smaller on the left.
# Hash Tables
Help to find data in big list that can be split into array of hash values
# Tries
Tree of arrays. Usually arrays of letters.

# Problem Set 5
https://cs50.harvard.edu/x/2024/psets/5/
This problem set I started to do earlier not to procrastinate as much as I did previously. I like to solve my problems while watching lecture. Otherwise I have a big gap between listening and solving in time
## Inheritance
https://cs50.harvard.edu/x/2024/psets/5/inheritance/
Seems an easy task, but needed some checks from hints to ensure I did it in a right way
## Speller
https://cs50.harvard.edu/x/2024/psets/5/speller/#speller
Decided not to implement improved solution but rather make just a working one