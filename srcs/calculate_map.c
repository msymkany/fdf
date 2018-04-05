/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/03/23 19:23:29 by msymkany          #+#    #+#             */
/*   Updated: 2018/03/23 19:23:32 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

t_cor 	to_izo(t_coord cor, t_cor st)
{
//	st.x = (cor.x - cor.z)/ sqrt(2);
//	st.y = (cor.x + cor.z + cor.y * 2) / sqrt(6);
	st.x = cor.x;
	st.y = cor.y;
	st.col = cor.col;
	return (st);
}

void    draw_1(t_gen *gen, t_bres br)
{
	int i;
	int		x;
	int		y;

	i = 1;
	br.d = (br.dy << 1) - br.dx;
	br.d1 = br.dy << 1;
	br.d2 = (br.dy - br.dx) << 1;
	x = gen->c0.x + br.sx;
	y = gen->c0.y;
	while (i <= br.dx)
	{
		if (br.d > 0)
		{
			br.d += br.d2;
			y += br.sy;
		}
		else
			br.d += br.d1;
		if (x >= 0 && y >= 0)
			put_pixel_to_image(gen, x, y, gen->c0.col);
		i++;
		x += br.sx;
	}
}

void    draw_2(t_gen *gen, t_bres br)
{
	int		i;
	int		x;
	int		y;

	i = 1;
	br.d = (br.dx << 1) - br.dy;
	br.d1 = br.dx << 1;
	br.d2 = (br.dx - br.dy) << 1;
	y = gen->c0.y + br.sy;
	x = gen->c0.x;
	while (i <= br.dy)
	{
		if (br.d > 0)
		{
			br.d += br.d2;
			x += br.sx;
		}
		else
			br.d += br.d1;
		if (x >= 0 && y >= 0)
			put_pixel_to_image(gen, x, y, gen->c0.col);
		i++;
		y += br.sy;
	}
}

void	bresenham(t_gen *gen)
{
	t_bres		br;

	br.dx = fabs(gen->c1.x - gen->c0.x);
	br.dy = fabs(gen->c1.y - gen->c0.y);
	br.sx = gen->c1.x >= gen->c0.x ? 1 : -1;
	br.sy = gen->c1.y >= gen->c0.y ? 1 : -1;
	if (gen->c0.x >= 0 && gen->c0.y >= 0)
		put_pixel_to_image(gen, gen->c0.x, gen->c0.y, gen->c0.col);
	if (br.dy <= br.dx)
	{
		draw_1(gen, br);
	}
	else
	{
		draw_2(gen, br);
	}
}

void	draw_it_all(t_gen *gen)
{
	size_t  	j;
	size_t	    i;

	i = 0;
	while (i < gen->raw->hight)
	{
		j = 0;
		while (j < gen->raw->width)
		{
			gen->c0 = to_izo(gen->raw->cor[i][j], gen->c0);
			if (j + 1 < gen->raw->width)
			{
				gen->c1 = to_izo(gen->raw->cor[i][j + 1], gen->c1);
				bresenham(gen);
			}
			if (i + 1 < gen->raw->hight)
			{
				gen->c1 = to_izo(gen->raw->cor[i + 1][j], gen->c1);
				bresenham(gen);
			}
			j++;
		}
		i++;
	}
}