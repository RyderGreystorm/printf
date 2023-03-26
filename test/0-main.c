#include "main.h"

int main(void)
{
    _printf("The first %% char is: %c. Here is the string: %s\n the third string: %s and %%\n", 'k', "HELLO", "WORLD");
_printf("hey _p: %c%c\n", 'o', 'm');    
printf("hey p: %c%c\n", 'o', 'm');    
_printf("hey _p: %c%c\n");    
printf("hey p: %c%c\n");    
_printf(NULL);
printf(NULL);
printf("The first char is p: %c\n", "hello");
    _printf("The first char is _p: %c\n", "hello");
    return (0);
}
