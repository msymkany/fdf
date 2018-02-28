/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_getnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 19:48:54 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/28 19:48:57 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

static int			arg_check(char *str)
{
	int		i;

	i = 0;
	if (*str == '-' || *str == '+')
		str++;
	if (!*str)
		return (1);
	while (str[i])
	{
		if (str[i] > '9' || str[i] < '0')
			return (1);
		i++;
	}
	if (i > 10)
		return (1);
	return (0);
}

static long int		atoi_s(const char *str)
{
	int					s;
	long int			r;

	r = 0;
	s = 1;
	if (*str == '-')
	{
		s = -1;
		str++;
	}
	else if (*str == '+')
		str++;
	while (*str)
	{
		r = r * 10 + (*str - '0');
		str++;
	}
	return ((r * s));
}

int					ft_getnbr(char *str, int *is_valid)
{
	long int	l;

	l = 0;
	if (arg_check(str))
		*is_valid = 0;
	l = atoi_s(str);
	if (l > 2147483647 || l < -2147483648)
		*is_valid = 0;
	return ((int)l);
}
