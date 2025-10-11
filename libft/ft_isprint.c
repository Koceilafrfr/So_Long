/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/29 00:50:11 by yzidani           #+#    #+#             */
/*   Updated: 2025/04/29 02:23:57 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
/*int	main(void)
{
	int	i;

	i = 31;
	printf("%d\n", isprint(i));
	printf("%d\n", ft_isprint(i));
	return (0);
}*/