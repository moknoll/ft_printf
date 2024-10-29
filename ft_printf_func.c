/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_func.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: moritzknoll <moritzknoll@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/29 19:18:23 by moritzknoll       #+#    #+#             */
/*   Updated: 2024/10/29 19:18:25 by moritzknoll      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
