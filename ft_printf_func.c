/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:18:23 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/04 11:04:21 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
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
			ft_putnbr_fd(nb / 10);
			ft_putnbr_fd(nb % 10);
		}
		else
		{
			ft_putchar_fd(nb + '0');
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


ft_putunsigned(unsigned int);

void	ft_puthex(uintptr_t num)
{
	char hex_digit;

	hex_digit = "0123456789abcdef"[num % 16];
	if(num >= 16)
	{
		ft_puthex(num / 16);
		ft_putchar(hex_digit);
	}
}

void	ftputHEX(uintptr_t num)
{
	char hex_digit;

	hex_digit = "0123456789ABCDEF"[num % 16];
	if(num >= 16)
	{
		ft_putHEX(num / 16);
		ft_putchar(hex_digit);
	}
}

ft_putpercent(void);

int ft_putptr(void *ptr)
{
	if (ptr == NULL)
		write(1, "NULL", 4);
	else
		write(1, "0x", 2);
		ft_puthex((uintptr_t)ptr);

}
