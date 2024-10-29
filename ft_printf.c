/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 18:39:20 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/29 19:19:26 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <stdarg.h>



void	ft_check_type(char type, va_list args)
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
