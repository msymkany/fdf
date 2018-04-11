/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_it.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/11 20:40:29 by msymkany          #+#    #+#             */
/*   Updated: 2018/04/11 20:40:30 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	move_it(t_gen *gen, int x, int y)
{
	size_t  	j;
	size_t	    i;

	i = 0;
	while (i < gen->raw->hight)
	{
		j = 0;
		while (j < gen->raw->width)
		{
			gen->raw->cor[i][j].x += x;
			gen->raw->cor[i][j].y += y;
			j++;
		}
		i++;
	}
}

void	rotate_z(t_gen *gen, int an)
{
	size_t  	j;
	size_t	    i;
//	double 		x;
//	double 		y;

	i = 0;
	while (i < gen->raw->hight)
	{
		j = 0;
		while (j < gen->raw->width)
		{
			gen->raw->cor[i][j].x = gen->raw->cor[i][j].x * cos(an) - gen->raw->cor[i][j].y * sin(an);
			gen->raw->cor[i][j].y += gen->raw->cor[i][j].x * sin(an) + gen->raw->cor[i][j].y * cos(an);
			j++;
		}
		i++;
	}
}
