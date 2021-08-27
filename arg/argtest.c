// Argtest
// Displays the arguments passed to a program

#include <stdlib.h>
#include <stdio.h>

// usage: argtest arg0 arg1 ... argN-1
// argv is an array of pointers to characters
// argv[0] has the address of the first character in the 0th argument
// argv[1] has the address of the first character in the 1st argument
// ...
int main(int argc, char* argv[])
{
    int i;
    printf("Number of arguments = %d\n", argc);
    for (i = 0; i < argc; i++)
        printf("Argument %d = %s\n", i, argv[i]);
    for (i = 0; i < argc; i++)
        printf("Address of argument %d = %p\n", i, argv[i]); //&argv[i] operate the same thing
    return EXIT_SUCCESS;
}
