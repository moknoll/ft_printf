# ft_printf

`ft_printf` is a custom implementation of the C standard library function `printf`. It supports various format specifiers and provides a simple and efficient way to format and print data to the standard output.

## Features

- Supports printing integers (`d`, `i`)
- Supports printing strings (`s`)
- Supports printing characters (`c`)
- Supports printing pointers (`p`)
- Supports printing unsigned integers (`u`)
- Supports printing hexadecimal numbers (lowercase `h` and uppercase `H`)
- Handles special character `%` printing

## Installation

1. Clone the repository:
    ```bash
    git clone https://github.com/yourusername/ft_printf.git
    ```

2. Navigate to the project directory:
    ```bash
    cd ft_printf
    ```

3. Include the `ft_printf.c` and `ft_printf.h` files in your project.

## Usage

The main function you will use is `ft_printf`. It is used just like the standard `printf` function in C.

### Function Signature:
```c
int ft_printf(const char *format, ...);
```
## Example
```c
#include "ft_printf.h"

int main() {
    int num = 42;
    char *str = "Hello, World!";
    
    ft_printf("Number: %d\n", num);
    ft_printf("String: %s\n", str);
    ft_printf("Pointer: %p\n", &num);
    ft_printf("Hex (lowercase): %h\n", num);
    ft_printf("Hex (uppercase): %H\n", num);
    
    return 0;
}
```
## Output
```bash
Number: 42
String: Hello, World!
Pointer: 0x7ffebf5c44d8
Hex (lowercase): 2a
Hex (uppercase): 2A
```
## Files
- ft_printf.c: Contains the implementation of the main function (ft_printf) and the helper function ft_check_type.
- ft_printf.h: Header file that includes function declarations and necessary library imports.
- ft_putchar.c: Contains the ft_putchar function to print individual characters.
- ft_putstr.c: Contains the ft_putstr function to print strings.
- ft_putnbr.c: Contains the ft_putnbr function to print integers.
- ft_puthex.c: Contains the ft_puthex and ft_putHEX functions to print hexadecimal numbers (lowercase and uppercase).
- ft_putptr.c: Contains the ft_putptr function to print pointers.
- ft_putunsigned.c: Contains the ft_putunsigned function to print unsigned integers.
## Lisence
```markdown
### Explanation:

1. **Title and Introduction**: The README starts with a brief description of what the project is, 
    focusing on the `ft_printf` implementation and its features.
  
2. **Features**: Lists the core functionalities of the `ft_printf` function, like printing integers, 
    strings, characters, pointers, hexadecimal values, and special characters.

3. **Installation**: Explains how to clone the project and include it in your own.

4. **Usage**: Provides an example of how to use the `ft_printf` function, 
    showing the format specifiers and their expected output.

5. **File Descriptions**: A brief rundown of the core files in the project.

6. **License**: Mentions that the project uses the MIT license, 
    or you can replace it with another if you prefer.

This should give users a clear understanding of your project and how to use your `ft_printf` function effectively.
```







