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
int			validate_coord(char *coor, t_gen *gen)
{
	char	**arr;
	int 	is_val;
	int 	num;
	int 	res;

	is_val = 0;
	res = 1;
	arr = ft_strsplit(coor, ',');
	if (arr[2])
		res = 0;
	num = ft_getnbr(arr[0], &is_val);
	if (!is_val)
		res = 0;
	else
		//write num to struct(iterate through arr)
//	else if (arr[1])
//		ft_printf("color\n");
//	else
//	{
//	}
	ft_del_2arr(&arr);
	return (res);
}

// parse every line and write to struct t_raw
int			parse_line(char *line, t_gen *gen)
{
	char	**arr;
	size_t	x;
	size_t	j;
	int 	res;

	j = 0;
	arr = ft_strsplit(line, ' ');
	x = ft_arrhight(arr);
	if (x != gen->raw->width)
		res = 0;
	while (j < x)
	{
		// validate_coord(arr[j], gen);
		j++;
	}
	ft_del_2arr(&arr);
	return (res);
}

void		read_map(char *map, t_gen *gen)
{
	int 	fd;
	char 	*line;

	line = NULL;
	fd = open(map, O_RDONLY);
	if (fd < 0)
		return ;
	gen->raw = ft_memalloc(sizeof(t_raw));
	get_next_line(fd, &line);
//	(gen->raw->hight)++;
	parse_line(line, gen);
//	arr = ft_strsplit(line, ' ');
//	ft_strdel(&line);
//	gen->raw->width = ft_arrhight(arr);

	while (get_next_line(fd, &line))
	{


		ft_strdel(&line);
	}

}
