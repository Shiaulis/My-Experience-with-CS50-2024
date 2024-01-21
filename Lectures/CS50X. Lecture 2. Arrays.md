``` c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
string words[2];

words[0] = "HI!";
words[1] = "BYE!"; 

printf("%c%c%c\n", words[0][0], words[0][1], words[0][2]);
printf("%c%c%c%c\n", words[1][0], words[1][1], words[1][2], words[1][3]);

}
```

# String Length
We are iterating over characters with knowledge that there is a `NUL` symbol at the end. It is in single quotes by convention.
```c
#include <cs50.h>
#include <stdio.h>

int main(void)
{
	string name = get_string("Name: ");
	int n = 0;
	
	while (name[n] != '\0')
	{
		n++;
	}
	
	printf("%i\n", n);
}
```

We can also use a helper function for calculation
```c
#include <cs50.h>
#include <stdio.h>

int string_length(string s);

int main(void)
{

	string name = get_string("Name: ");
	int length = string_length(name);
	printf("%i\n", length);
} 

int string_length(string name)
{
	int n = 0;
	while (name[n] != '\0')
	{
		n++;
	}

	return n;
}
```
Alternatively we can use function from `string.h`
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h> 

int main(void)
{
	string name = get_string("Name: ");
	int length = strlen(name);
	printf("%i\n", length);
}
```

There is a canonical way to initialise variable based on string length within loop, but outside of condition:
```c
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
	string s = get_string("Input: ");
	printf("Output: ");
	for (int i = 0, n = strlen(s); i < n; i++)
	{
		printf("%c", s[i]);
	}
	printf("\n");
}
```

# Command-Line Arguments
Second word that is passed to a command/program

# Return Code
`echo $?` helps to detect of return code of the most recent command/program.

# Cryptography
Cypher - algorithm for crypting/scrambling information in a reversible way

# Problem Set 2
## Scrabble
![[scrabble.c]]
## Readability
![[readability.c]]
## Substitution
