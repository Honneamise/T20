# TEDDY

Teddy is a single header utility to print and read strings on a rendered Opengl window.
___
## void TeddyInit(int rows, int cols, int color, char *font_file)

Initialization function

**rows** : number of rows\
**cols** : number of cols\
**color** : characters color in RGB format (ex: 0XAABBFF)\
**font_file** : optional font file, if NULL the builtin font will be used

---
## void TeddyClose()

Closing function

---
## int TeddyRun()

Return 0 if user requested quit (ESC key or closing window), 1 otherwise

---
## void TeddyClear()

Clear the current content area (NOT the prompt)

---
## void TeddyAddLine(char *str)

Add a line to the current content area, all previous lines will be moved up by one line.
If the length of str is > number of cols, str will be truncated.

**str** : string to add

---
## void TeddyAddMultiLine(char *str)

Add a line to the current content area, all previous lines will be moved up by one
If the length of str is > number of cols, str will be splitted to multiple lines.

**str** : string to add

---
## char *TeddyReadLine()

Returns a pointer to a copy of the prompt and clear it

**Note** : This function will not return until ENTER is pressed.\
If the user has requested to exit, this function will return NULL.

<br>

---
# Examples

Program to read from the prompt and mirror in the content area until the user has requested the exit.

```
//std
#include "stdio.h"

//stuff
#define TEDDY
#include "teddy.h"

//main
int main()
{
    TeddyInit(40, 80, 0x00FF00, NULL);

    while(1)
    {
        char *str = TeddyReadLine();
        
        if(str==NULL) { break; }

        TeddyAddLine(str);

        free(str);
    }

    TeddyClose();

    return 0;
}
```

Program to continuously print on the content area until the user has requested the exit.

```
//std
#include "stdlib.h"
#include "unistd.h"

//stuff
#define TEDDY
#include "teddy.h"

//main
int main(void)
{
    TeddyInit(40, 80, 0x00FF00, NULL);

    while(TeddyRun())
    {
        sleep(1);

        TeddyAddLine("test");
    }

    TeddyClose();

    return 0;
}
```

---
**Note on fonts :**

Teddy supports all the 1760 fonts availables here :

https://github.com/viler-int10h/vga-text-mode-fonts

---
**Note on tests :**

Teddy has been tested with the following flags on Valgrind :

valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes

---
**TSIL ODOT :**

- remove assert and use an error function


