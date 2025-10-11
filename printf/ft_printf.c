/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 12:35:54 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/22 15:35:36 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_type(char type, va_list args, size_t *count)
{
	if (type == 'c')
		ft_putchar(va_arg(args, int), count);
	else if (type == 's')
		ft_putstr(va_arg(args, char *), count);
	else if (type == 'p')
		ft_putadd(va_arg(args, unsigned long long), count);
	else if (type == 'd' || type == 'i')
		ft_putnbr(va_arg(args, int), count);
	else if (type == 'u')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789", count);
	else if (type == 'x')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789abcdef", count);
	else if (type == 'X')
		ft_putnbr_base(va_arg(args, unsigned int), "0123456789ABCDEF", count);
	else if (type == '%')
		ft_putchar('%', count);
}

int	ft_printf(const char *param, ...)
{
	va_list	args;
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	va_start(args, param);
	if (param == NULL)
		return (-1);
	while (param[i])
	{
		if (param[i] == '%')
		{
			ft_type(param[i + 1], args, &count);
			i += 2;
		}
		else
		{
			ft_putchar(param[i], &count);
			i++;
		}
	}
	va_end(args);
	return (count);
}

void	ft_putstr(char *str, size_t *count)
{
	int	i;

	if (!str)
	{
		ft_putstr("(null)", count);
		return ;
	}
	i = 0;
	while (str[i])
	{
		(*count)++;
		i++;
	}
	write(1, str, i);
}

// int main()
// {
// 	int count = ft_printf(" %x ", -99);
// 	int count2 = printf(" %x ", -99);
// 	printf("ft_printf = %d, printf = %d\n", count, count2);
// } 
