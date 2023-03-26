#include "main.h"

int main(void)
{
int a;
    _printf("The first %% char is: %c. Here is the string: %s\n the third string: %s and %%\n", 'k', "HELLO", "WORLD");
a = _printf("hey string: %c\n", 2000);    
printf("_pf a is: %d\n", a);
a = printf("hey string: %c\n", 2000);    
printf("pf a is: %d\n", a);
    return (0);
}
