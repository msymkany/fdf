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

void	rotate_z(t_gen *gen, float an)
{
	size_t  	j;
	size_t	    i;
	double 		x;
	double 		y;

	i = 0;
	while (i < gen->raw->hight)
	{
		j = 0;
		while (j < gen->raw->width)
		{
			x = gen->raw->cor[i][j].x;
			y = gen->raw->cor[i][j].y;
			gen->raw->cor[i][j].x =  x * cosf(an) - y * sinf(an);
			gen->raw->cor[i][j].y = x * sinf(an) + y * cosf(an);
			j++;
		}
		i++;
	}
}

void	rotate_x(t_gen *gen, float an)
{
	size_t  	j;
	size_t	    i;
	double 		z;
	double 		y;

	i = 0;
	while (i < gen->raw->hight)
	{
		j = 0;
		while (j < gen->raw->width)
		{
			z = gen->raw->cor[i][j].z;
			y = gen->raw->cor[i][j].y;
			gen->raw->cor[i][j].z = z * cosf(an) - y * sinf(an);
			gen->raw->cor[i][j].y = z * sinf(an) + y * cosf(an);
			j++;
		}
		i++;
	}
}

void	rotate_y(t_gen *gen, float an)
{
	size_t  	j;
	size_t	    i;
	double 		x;
	double 		z;

	i = 0;
	while (i < gen->raw->hight)
	{
		j = 0;
		while (j < gen->raw->width)
		{
			x = gen->raw->cor[i][j].x;
			z = gen->raw->cor[i][j].z;
			gen->raw->cor[i][j].x = x * cosf(an) + z * sinf(an);
			gen->raw->cor[i][j].z = -x * sinf(an) + z * cosf(an);
			j++;
		}
		i++;
	}
}
