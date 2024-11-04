/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putptr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 13:28:28 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/11/04 16:43:44 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putptr(void *ptr)
{
	if (!ptr)
		return (ft_putstr("NULL"));
	int printed_chars = 0;
	printed_chars += ft_putstr("0x");
	printed_chars += ft_puthex((uintptr_t)ptr);
	return (printed_chars);
}
