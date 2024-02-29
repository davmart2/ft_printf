/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numbers.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmart2 <davmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:20:12 by davmart2          #+#    #+#             */
/*   Updated: 2024/01/28 11:41:28 by davmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_nbr(int n, char *base)
{
	int		count;
	int		n_len;

	count = 0;
	n_len = 10;
	if (n == -2147483648)
	{
		write (1, "-2147483648", 11);
		return (11);
	}
	if (n < 0)
	{
		write (1, "-", 1);
		count++;
		n = -n;
	}
	if (n >= n_len)
		count += print_nbr(n / n_len, base);
	count += print_char(base[n % n_len]);
	return (count);
}

int	print_unbr(unsigned int n, char *base)
{
	int			count;
	unsigned int		n_len;

	count = 0;
	n_len = 10;
	if (n >= n_len)
		count += print_unbr(n / n_len, base);
	count += print_char(base[n % n_len]);
	return (count);
}

int	print_hexnbr(unsigned int n, char *base)
{
	int			count;
	unsigned int		n_len;

	count = 0;
	n_len = 16;
	if (n >= n_len)
		count += print_hexnbr(n / n_len, base);
	count += print_char(base[n % n_len]);
	return (count);
}

int	point(unsigned long n, char *base)
{
	int			count;
	unsigned int		n_len;

	count = 0;
	n_len = 16;
	if (n >= n_len)
		count += point(n / n_len, base);
	count += print_char(base[n % n_len]);
	return (count);
}
