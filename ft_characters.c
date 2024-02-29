/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_characters.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davmart2 <davmart2@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 15:16:35 by davmart2          #+#    #+#             */
/*   Updated: 2024/01/27 15:39:49 by davmart2         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_char(int c)
{
	return (write(1, &c, 1));
}

int	print_string(char *str)
{
	int	count;

	count = 0;
	if (!str)
		str = "(null)";
	while (*str != '\0')
	{
		print_char((int)*str);
		count++;
		str++;
	}
	return (count);
}
