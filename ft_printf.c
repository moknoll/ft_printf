/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:39:20 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/29 18:58:45 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>

static void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

static void	ft_putnbr_fd(int nb, int fd)
{
	if (nb == -2147483648)
	{
		write(fd, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			write(fd, "-", 1);
			nb *= -1;
		}
		if (nb > 9)
		{
			ft_putnbr_fd(nb / 10, fd);
			ft_putnbr_fd(nb % 10, fd);
		}
		else
		{
			ft_putchar_fd(nb + '0', fd);
		}
	}
}

static void	ft_putstr_fd(char *s, int fd)
{
	int	c;

	c = 0;
	while (s[c])
	{
		write(fd, &s[c], 1);
		c++;
	}
}

void	check_type(char type, va_list args)
{
	if (type == 'd' || type == 'i')
	{
		int num = va_arg(args, int);
		ft_putnbr_fd(num, 1);
	}
	else if (type == 's')
	{
		char *str = va_arg(args, char *);
		if (str)
			ft_putstr_fd(str, 1);
		else
			ft_putstr_fd("(null)", 1);
	}
	else if (type == 'c')
	{
		char c = va_arg(args, int);
		ft_putchar_fd(c, 1);
	}
	// else if (type == 'p')
	// {

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
			check_type(format[i], args);
		}
		else
		{
			ft_putchar_fd(format[i], 1);
		}
		i++;
	}
	va_end(args);
	return printed_chars;
}


int main()
{
	char *str =  "helllo";

	ft_printf("how ARRE %s NF\n", str);
	ft_printf("bcidsbc %d\n", -13);
	ft_printf("%c", 'c');
}
