#include "main.h"

int main(void)
{
	int a;


    printf("The first char is: %c\n", 'a');
    _printf("The first char is: %c\n", 'b');
    _printf("The first char is: %%\n", 'b');

a = _printf("The first char is _p: %s\n", "im good.");
    printf("%d\n", a);

a = printf("The first char is p: %s\n", "im good.");
    printf("%d\n", a);
    return (0);
}
