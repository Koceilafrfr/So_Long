/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yzidani <yzidani@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/20 12:31:28 by yzidani           #+#    #+#             */
/*   Updated: 2025/05/21 16:16:09 by yzidani          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdio.h>

int		ft_printf(const char *param, ...);

void	ft_putnbr_base(unsigned long long nb, char *base, size_t *count);
void	ft_putadd(unsigned long long adresse, size_t *count);
void	ft_putstr(char *str, size_t *count);
void	ft_type(char type, va_list args, size_t *count);
void	ft_putchar(char c, size_t *count);
void	ft_putnbr(int n, size_t *count);

#endif