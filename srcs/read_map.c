/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 20:23:02 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/27 20:23:05 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//t_coord		*write_to_struct(double x, double y, double z, int col)
//{
//	t_coord *cor;
//
//	cor = (t_coord *)malloc(sizeof(t_coord));
//	cor->x = x;
//	cor->y = y;
//	cor->z = z;
//	cor->col = col;
//	return (cor);
//}
//
//t_coord		*validate_coord()
//{
//
//}

void		read_map(char *map)
{
	int 	fd;
	char 	*line;

	line = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	while (get_next_line(fd, &line))
	{

		ft_strdel(&line);
	}

//	return
}
