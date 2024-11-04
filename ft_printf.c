/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mknoll <mknoll@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:39:20 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/04 12:47:00 by mknoll           ###   ########.fr       */
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
	if (!s)
	{
		return ;
	}
	while (s[c])
	{
		write(1, &s[c], 1);
		c++;
	}
}


void	ft_puthex(uintptr_t num)
{
	char	hex_digit;

	hex_digit = "0123456789abcdef"[num % 16];
	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (num >= 16)
		ft_puthex(num / 16);
	ft_putchar(hex_digit);
}

void	ft_putHEX(uintptr_t num)
{
	char	hex_digit;

	hex_digit = "0123456789ABCDEF"[num % 16];
	if (num == 0)
	{
		ft_putchar('0');
		return ;
	}
	if (num >= 16)
		ft_putHEX(num / 16);
	ft_putchar(hex_digit);
}

void	ft_putpercent(void)
{
	ft_putchar('%');
}

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

int	ft_putunsigned(unsigned int nb)
{
	char	buffer[10];
	int		i;
	int		printed_chars;

	i = 0;
	if (nb == 0)
		ft_putchar('0');
	while (nb > 0)
	{
		buffer[i++] = (nb % 10) + '0';
		nb /= 10;
	}
	printed_chars = i;
	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
	return (printed_chars);
}

void	ft_check_type(char type, va_list args)
{
	if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(args, int));
	else if (type == 's')
		ft_putstr(va_arg(args, char *));
	else if (type == 'c')
		ft_putchar(va_arg(args, int));
	else if (type == 'p')
		ft_putptr(va_arg(args, void *));
	else if (type == 'h')
		ft_puthex(va_arg(args, uintptr_t));
	else if (type == 'H')
		ft_putHEX(va_arg(args, uintptr_t));
	else if (type == 'u')
		ft_putunsigned(va_arg(args, unsigned int));
	else if (type == '%')
		write(1, "%", 1);
}

int	ft_printf(const char *format, ...) {
	va_list	args;
	int		i;
	int		printed_chars;

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
			printed_chars++;
		}
		i++;
	}
	va_end(args);
	return (printed_chars);
}


int main()
{

	ft_printf("%u\n", -123456);
	printf("%u",-123456);
}
