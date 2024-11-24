# Makefile
```Makefile
CC=gcc

all: combined

combined: funcs.c funcs_helper.o
	$(CC) -o combined funcs.c funcs_helper.o

funcs_helper.o: funcs_helper.c
	$(CC) -c funcs_helper.c -o funcs_helper.o

clean:
	rm combined funcs_helper.o
```

# Header files

```csharp(better lint)
#include <stdio.h> // for files in system/default directory
#include "funcs.h" // for files in same directory as source file
```

**The header file**
- Provides **declarations** for functions, variables, constants, and types that can be shared across multiple source files.

```c
int add(int a, int b);
int mull(int a, int b);
int sub(int a, int b);
```