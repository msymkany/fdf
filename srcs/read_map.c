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

// turn gen to t_raw

int			validate_coord(char *coor, t_gen *gen, size_t col)
{
	char	**arr;
	int 	is_val;
	int 	res;

	ft_printf("%s ", coor);//test
	is_val = 0;
	res = 0;
	arr = ft_strsplit(coor, ',');
	res = (arr[2]) ? 1 : res;
	gen->raw->cor[gen->raw->hight][col].z = ft_getnbr(arr[0], &is_val);
	res = (!is_val) ? 1 : res;
	gen->raw->cor[gen->raw->hight][col].y = gen->raw->hight;
	gen->raw->cor[gen->raw->hight][col].x = col;
	gen->raw->cor[gen->raw->hight][col].col = 0;
	if (arr[1])
		gen->raw->cor[gen->raw->hight][col].col = 1;
	ft_del_2arr(&arr);
	ft_printf("%d ", gen->raw->cor[gen->raw->hight][col].z); // test
	return (res);
}

int			parse_line(char *line, t_gen *gen)
{
	char	**arr;
	size_t	x;
	size_t	j;
	int 	res;

	j = 0;
	res = 0;
	arr = ft_strsplit(line, ' ');
	x = ft_arrhight(arr);
//	ft_printf("%d\n", x);//test
	if (x != gen->raw->width)
		res = 1;
	while (j < x)
	{
		if (validate_coord(arr[j], gen, j))
		{
			ft_del_2arr(&arr);
			return (res);
		}
		j++;
	}
	ft_del_2arr(&arr);
	return (res);
}

int		read_map(t_gen *gen, int fd)
{
	char 	*line;

	line = NULL;
	gen->raw = ft_memalloc(sizeof(t_raw));
	get_next_line(fd, &line);
	gen->raw->width = (size_t)ft_w_c(line, ' ');
	ft_printf("%d\n", gen->raw->width);//test
	if (parse_line(line, gen))
	{
		ft_strdel(&line);
		return (1);
	}
	while (get_next_line(fd, &line))
	{
		(gen->raw->hight)++;
		if (parse_line(line, gen))
		{
			ft_strdel(&line);
			return (1);
		}
		ft_printf("\n"); //test
	}
	(gen->raw->hight)++;
	return (0);
}
