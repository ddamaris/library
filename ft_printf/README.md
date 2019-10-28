# ft_printf
42 School Project | Representation of printf function

## Subject
The task was to rebuild the printf function with basic functionality called "ft_printf".
At 42, students are not allowed to use standard library functions. We can only submit wholly self-written functions.

ft_printf must achieve the following mandatory requirements:  
  
* Manage the following conversions: `s`, `p`, `d`, `i`, `o`, `u`, `x`, `X`, `c`
* Manage `%%`
* Manage the flags `#`, `0`, `-`, `+` & `space`
* Manage the minimum field-width
* Manage the precision
* Manage the flags `hh`, `h`, `l`, `ll`

## How to use
##### 1. Clone repo
##### 2. Run `make`. 
This will compile **libftprintf.a**. 
##### 3. To use, include `ft_printf.h` and use just like `printf`:
```c
#include "ft_printf.h"

int				main(void)
{
	ft_printf("%s, %d", "Hello", 42);
	return (0);
}
```
##### 4. Compile
```console
gcc -o main main.c libftprintf.a
```
##### 5. Run
```console
./main
```

##### 6. Output
```
Hello, 42
```
