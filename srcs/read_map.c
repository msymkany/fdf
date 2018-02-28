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

// parse every line and write to struct t_raw
int 		parse_line(char *line, char **arr, size_t x)
{
	arr = ft_strsplit(line, ' ');
	x = ft_arrhight(arr);
}

void		read_map(char *map)
{
	int 	fd;
	char 	*line;
	char	**arr;
	size_t	x;
	size_t	y;

	line = NULL;
	x = 0;
	y = 0;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	get_next_line(fd, &line);
	arr = ft_strsplit(line, ' ');
	x = ft_arrhight(arr);
	while (get_next_line(fd, &line))
	{


		ft_strdel(&line);
	}

//	return
}
