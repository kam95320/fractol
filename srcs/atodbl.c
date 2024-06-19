/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atodbl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahoumou <kahoumou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/21 16:35:07 by kahoumou          #+#    #+#             */
/*   Updated: 2024/02/21 16:35:14 by kahoumou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

static int	check2(char *s)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] == '.')
			count++;
		i++;
	}
	if (count > 1)
		return (1);
	return (0);
}

static int	check(char *s)
{
	int	i;

	i = 0;
	if (check2(s) != 0)
	{
		return (0);
	}
	while (s[i])
	{
		if ((s[i] >= '0' && s[i] <= '9') || s[i] == '.')
		{
			i++;
		}
		else
			return (0);
	}
	return (1);
}

double	atodbl(char *s)
{
	long (integer_part) = 0;
	double (fractional_part) = 0;
	double (pow) = 1;
	int (sign) = +1;
	while ((*s >= 9 && *s <= 13) || 32 == *s)
		++s;
	while ('+' == *s || '-' == *s)
		if ('-' == *s++)
			sign = -sign;
	if (check(s) == 0)
	{
		write(1, "Arguments invalid!\n", 19);
		exit(0);
	}
	while (*s != '.' && *s)
		integer_part = (integer_part * 10) + (*s++ - 48);
	if ('.' == *s)
		++s;
	while (*s)
	{
		pow /= 10;
		fractional_part = fractional_part + (*s++ - 48) * pow;
	}
	return ((integer_part + fractional_part) * sign);
}
