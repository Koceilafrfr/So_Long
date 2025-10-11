/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 14:00:03 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/21 16:16:38 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	ft_putnbr_base(unsigned long long nb, char *base, size_t *count)
{
	size_t	base_len;

	base_len = ft_strlen(base);
	if (nb >= base_len)
		ft_putnbr_base(nb / base_len, base, count);
	ft_putchar(base[nb % base_len], count);
}

void	ft_putadd(unsigned long long adresse, size_t *count)
{
	if (!adresse)
	{
		ft_putstr("(nil)", count);
		return ;
	}
	ft_putstr("0x", count);
	ft_putnbr_base(adresse, "0123456789abcdef", count);
}

void	ft_putchar(char c, size_t *count)
{
	write(1, &c, 1);
	(*count)++;
}

void	ft_putnbr(int n, size_t *count)
{
	long	nb;

	nb = (long)n;
	if (nb < 0)
	{
		nb *= -1;
		ft_putchar('-', count);
	}
	if (nb > 9)
	{
		ft_putnbr(nb / 10, count);
		ft_putchar(nb % 10 + '0', count);
	}
	else
		ft_putchar(nb % 10 + '0', count);
}
