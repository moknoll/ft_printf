/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:17:25 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/04 14:00:41 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_puthex(uintptr_t num)
{
	int count = 0;
	char hex_digit;

	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (num >= 16)
		count += ft_puthex(num / 16);
	hex_digit = "0123456789abcdef"[num % 16];
	count += ft_putchar(hex_digit);
	return (count);
}

int	ft_putHEX(uintptr_t num)
{
	char	hex_digit;
	int count;

	count = 0;
	hex_digit = "0123456789ABCDEF"[num % 16];
	if (num == 0)
	{
		ft_putchar('0');
		return (1);
	}
	if (num >= 16)
		count += ft_putHEX(num / 16);
	count += ft_putchar(hex_digit);
	return(count);
}
