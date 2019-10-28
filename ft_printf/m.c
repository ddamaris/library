#include "ft_printf.h"
#include <stdio.h>

int main()
{
    unsigned int k;
    k = 1;
    ft_printf("%u", k);
    printf("\n");
    printf("%u", k);
    printf("\n");
    return (0);
}