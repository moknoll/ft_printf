/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:39:20 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/04 11:33:05 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>
#include <stdint.h>


static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	ft_putnbr(int nb)
{
	if (nb == -2147483648)
	{
		write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(1, "-", 1);
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr(nb / 10);
			ft_putnbr(nb % 10);
		}
		else
		{
			ft_putchar(nb + '0');
		}
	}
}

static void	ft_putstr(char *s)
{
	int	c;

	c = 0;
	while (s[c])
	{
		write(1, &s[c], 1);
		c++;
	}
}


// ft_putunsigned(unsigned int);

void	ft_puthex(uintptr_t num)
{
	char hex_digit;

	hex_digit = "0123456789abcdef"[num % 16];
	 if (num == 0)
    {
        ft_putchar('0');
        return;
    }
	if(num >= 16)
		ft_puthex(num / 16);
	ft_putchar(hex_digit);
}

void	ft_putHEX(uintptr_t num)
{
	char hex_digit;

	hex_digit = "0123456789ABCDEF"[num % 16];
	 if (num == 0)
    {
        ft_putchar('0');
        return;
    }
	if(num >= 16)
		ft_putHEX(num / 16);
	ft_putchar(hex_digit);
}

// ft_putpercent(void);

void	ft_putptr(void *ptr)
{
	if (ptr == NULL)
		ft_putstr("(nil)");
	else
	{
		ft_putstr("0x");
		ft_puthex((uintptr_t)ptr);
	}
}

void	ft_check_type(char type, va_list args)
{
	if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(args, int));
	else if (type == 's')
		if (args)
			ft_putstr(va_arg(args, char *));
		else
			ft_putstr("(null)");
	else if (type == 'c')
		ft_putchar(va_arg(args, int));
	else if (type == 'p')
		ft_putptr(va_arg(args, void*));

	// }
	// else if (type == 'u')
	// {

	// }
	// else if (type == '%')
}

int	ft_printf(const char *format, ...) {
	va_list args;
	int i ;
	int printed_chars;

	va_start(args, format);
	i = 0;
	printed_chars = 0;
	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			i++;
			ft_check_type(format[i], args);
		}
		else
		{
			ft_putchar(format[i]);
			i++;
		}
	}
	va_end(args);
	return printed_chars;
}


int main()
{
	char *str =  "helllo";
	int a = 42;
    int *ptr = &a;

	ft_printf("The adress is %p, the value is %d\n", ptr, *ptr);
    printf("The adress is %p, the value is %d\n", ptr, *ptr);
}
