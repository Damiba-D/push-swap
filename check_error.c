/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddamiba <ddamiba@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/02 12:46:09 by ddamiba           #+#    #+#             */
/*   Updated: 2025/06/02 17:20:43 by ddamiba          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_countdigit(int nb)
{
	int	count;

	if (nb < 0)
		nb *= -1;
	count = 1;
	while (nb > 9)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

int check_error(int argc, char **argv)
{
	int i;
	int num;
	int len;
	
	i = 1;
	while (i < argc)
	{
		num = ft_atoi(argv[i]);
		len = ft_strlen(argv[i]);
		if (num < 0)
			len--;
		if (len != ft_countdigit(num))
			return (-1);
		i++;
	}
	return (0);
}
