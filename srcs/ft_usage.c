/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_usage.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/22 18:17:23 by msymkany          #+#    #+#             */
/*   Updated: 2017/03/22 18:20:44 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	ft_usage(char *name)
{
	write(1, "Usage: ", 7);
	ft_putstr(name);
	write(1, " <filename>\n", 16);
}
