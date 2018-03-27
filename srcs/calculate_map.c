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

t_cor 	convert_to_izo(t_coord cor, t_cor st)
{
	st.x = (cor.x - cor.z) / sqrt(2);
	st.y = (cor.x + cor.z + cor.y * 2) / sqrt(6);
}

void	bresenham_kurwa(t_gen *gen, t_cor first, t_cor next)
{

//	convert_to_izo(gen->raw->cor[i][j], &x1, &y1);
//	if (dir == 1)
//		(gen->raw->cor[i][j + 1], &x2, &y2);
//	else
//		(gen->raw->cor[i + 1][j], &x2, &y2);


}

void	draw_it_all(t_gen *gen)
{

	int 		j;
	int 		i;
	t_cor		first;
	t_cor		next;

	i = 0;
	j = 0;
	while (i < gen->raw->hight)
	{
		while (j < gen->raw->width)
		{
			first = convert_to_izo(gen->raw->cor[i][j], first);
			if (j + 1 < gen->raw->width)
			{
				next = convert_to_izo(gen->raw->cor[i][j + 1], next);
				bresenham_kurwa(gen, first, next); // 1 for right step, 2 for down
			}
			if (i + 1 < gen->raw->hight)
			{
				next = convert_to_izo(gen->raw->cor[i + 1][j], next);
				bresenham_kurwa(gen, first, next); // 1 for right step, 2 for down
			}
		}
		i++;
	}
}