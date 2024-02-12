https://youtu.be/F9-yqoS7b8w
# Hexadecimal
Brief explanation of what is hexadecimal system
# Memory
- Memory address is using hexadecimal system.
- Not to mess up things hexadecimal numbers prefixed with `0x`.
```c
#include <stdio.h>

int main(void)
{
	int n = 50;
	printf("%i\n", n);
}
```
Integer in the listing above will take up some 4 bytes in our memory. To use and access that address we are using `&` and `*` operators.
```c
#include <stdio.h>

int main(void)
{
	int n = 50;
	printf("%p\n", &n);
}
```
- C supports **pointers**.

```c
int n = 50;
int *p = &n;
```
*Give me an address of a variable where I've stored 50*.

```c
int main(void)
{
	int n = 50;
	int *p = &n;
	printf("%i\n", *p);
}
```
An example where we just take the information that is stored in the pointer. Result will be `50`.
- Pointers take 8 bytes.
- We usually do not care about actual addresses, we care about values that are stored within those addresses.
# Strings
```c
string s = "HI!";
```
`s` is a pointer to a string beginning. The end of the string is known automagically by using terminating character `\0`.
Each character is located on the next memory cell.
What we were calling `string` was actually is `char *`.
```c
int main(void)
{
	char *s = "HI!";
	printf("%s\n", s);
}
```
Above is a native code that does not need a `cs50.h` library since it no longer uses `string` keyword.

# Pointer Arithmetic
```c
int main(void)
{
	char *s = "HI!";
	printf("%c", *s);
	printf("%c", *(s + 1);
	printf("%c", *(s + 2);
}
```

Accessing array by index is basically telling to compiler to go to the next pointer and get a value from it: `*(s + 1)`.
# String Comparison
Strings contain address of the first element that is why they cannot be compared by ` == `

# Malloc and Free
```c
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    char *s = get_string("s: ");
    if (s == NULL)
    {
        return 1;
    }

    char *t = malloc(strlen(s) + 1);
    if (t == NULL)
    {
        return 1;
    }

    strcpy(s, t);

    if (strlen(t) > 0)
    {
        t[0] = toupper(t[0]);
    }

    printf("%s\n", s);
    printf("%s\n", t);

    free(t);
    return 0;
}
```

We are using `malloc` and `free` to allocate and free memory that we handles. cs50 functions are managing memory by themselves thus they don't need to use `free`.
We always need to check if `malloc` does not return `NULL`. If it did it means we run out of memory and should not continue application execution.

# Valgrind
`sizeof(int)` will return size of integer no matter what platform was used.
Valgrind app helps us to detect any incorrect memory usages as well as any memory leaks.

# Swapping
Variables are passed by value into functions

Memory structure:

Machine Code
-
Globals
-
Heap ⬇️

Stack ⬆️

Stack takes frames for each function, 1 by 1 from the bottom.
Each frame takes variables.
To swap 2 variables you need to pass pointers to swap function
stack overflow or heap overflow happens when we use too much of memory whether from stack or heap.

# Scanf
Scanf helps to get input in C, but CS50 libraries do it in more safer mode.

# File I/O
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    FILE *file = fopen("phonebook.csv", "a");

    if (file == NULL)
    {
        return 1;
    }

    char *name = get_string("Name: \n");
    char *number = get_string("Number: \n");

    fprintf(file, "%s,%s\n", name, number);

    fclose(file);
}

```

```c
#include <stdio.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
	FILE *src = fopen(argv[1], "rb");
	FILE *dst = fopen(argv[2], "wb");

	BYTE b;

	while (fread(&b, sizeof(b), 1, src) != 0)
	{
		fwrite(&b, sizeof(b), 1, dst);
	}

	fclose(dst);
	fclose(src);
}
```

# Problem Set 4
## Volume
The problem was provided almost with solution. It still feels hard for me to track the idea of managing file pointers. Still submitted with my attempt to fully grasp all of its aspects. A bit scare to check the more complex problem 😄 

[[Learning CS50X]]