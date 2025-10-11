/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/07 14:38:59 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/16 15:59:10 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_ocb(long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		n = n / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		len;
	long	nn;
	int		flag;

	flag = 0;
	nn = n;
	if (nn < 0)
	{
		flag = 1;
		nn *= -1;
	}
	len = count_ocb(nn) + flag;
	str = malloc(sizeof(char) * (len + 1));
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nn % 10) + 48;
		nn = nn / 10;
	}
	if (flag == 1)
		str[0] = '-';
	return (str);
}
// int	main(void)
// {
// 	printf("%s", ft_itoa(-2147483648));
// 	return (0);
// }