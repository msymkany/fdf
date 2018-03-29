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
	st.x = (cor.x - cor.z) / sqrt(2);
	st.y = (cor.x + cor.z + cor.y * 2) / sqrt(6);
	st.col = cor.col;
    return (st);
}

void    draw_1(t_gen *gen, int dx, int dy, int sx, int sy)
{
    int d = (dy << 1) - dx;
    int d1 = dy << 1;
    int d2 = (dy - dx) << 1;

    for(int x = gen->c0.x + sx, y = gen->c0.y, i = 1; i <= dx; i++, x += sx)
    {
        if (d > 0)
        {
            d += d2;
            y += sy;
        }
        else
            d += d1;
        put_pixel_to_image(gen, x, y, gen->c0.col);
//            putpixel(x, y, color);
    }
}

void    draw_2(t_gen *gen, int dx, int dy, int sx, int sy)
{
    int d = (dx << 1) - dy;
    int d1 = dx << 1;
    int d2 = (dx - dy) << 1;
    put_pixel_to_image(gen, gen->c0.x, gen->c0.y, gen->c0.col);
    for(int y = gen->c0.y + sy, x = gen->c0.x, i = 1; i <= dy; i++, y += sy)
    {
        if ( d >0)
        {
            d += d2;
            x += sx;
        }
        else
            d += d1;
        put_pixel_to_image(gen, x, y, gen->c0.col);
    }
}

void	bresenham(t_gen *gen)
{
//void segment(int x0, int y0, int x1, int y1, int color)
    int     dx;
    int     dy;
    int     sx;
    int     sy;

    dx = fabs(gen->c1.x - gen->c0.x);
    dy = fabs(gen->c1.y - gen->c0.y);
    sx = gen->c1.x >= gen->c0.x ? 1 : -1;
    sy = gen->c1.y >= gen->c0.y ? 1 : -1;
    put_pixel_to_image(gen, gen->c0.x, gen->c0.y, gen->c0.col);
    if (dy <= dx)
    {
        draw_1(gen, dx, dy, sx, sy);
    }
    else
    {
        draw_2(gen, dx, dy, sx, sy);
    }
}

void	draw_it_all(t_gen *gen)
{
	size_t  	j;
	size_t	    i;

	i = 0;
	j = 0;
	while (i < gen->raw->hight)
	{
		while (j < gen->raw->width)
		{
			gen->c0 = to_izo(gen->raw->cor[i][j], gen->c0);
			if (j + 1 < gen->raw->width)
			{
				gen->c1 = to_izo(gen->raw->cor[i][j + 1], gen->c1);
				bresenham(gen); // 1 for right step, 2 for down
			}
			if (i + 1 < gen->raw->hight)
			{
				gen->c1 = to_izo(gen->raw->cor[i + 1][j], gen->c1);
				bresenham(gen); // 1 for right step, 2 for down
			}
		}
		i++;
	}
}