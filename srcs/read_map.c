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

int 		get_col(char *str)
{
	int     j;
	int     num;

	num = 0;
	j = 2;
	if (str[0] != '0' && str[1] != 'x')
		return (0XFFFFAA);
	while (str[j])
	{
		if (j == 8)
			return (0XFFFFAA);
		if (str[j] >= '0' && str[j] <= '9')
			num = num * 16 + (str[j] - '0');
		else if (str[j] >= 'A' && str[j] <= 'F')
			num = num * 16 + (str[j] - 'A' + 10);
		else
			return (0XFFFFAA);
		j++;
	}
	printf(",%X ", num);
	return(num);
}

int			validate_coord(char *coor, t_raw *raw, size_t col, int step)
{
	char	**arr;
	int 	is_val;
	int 	res;

	is_val = 0;
	res = 0;
	arr = ft_strsplit(coor, ',');
	res = ((arr[1] && arr[2]) ? 1 : res);
	raw->cor[raw->hight][col].z = (ft_getnbr(arr[0], &is_val)) * step / 4; // maybe not z, first row problem
	res = ((!is_val) ? 1 : res);
    if (res)
    {
        ft_del_2arr(&arr);
        return (res);
    }
	raw->cor[raw->hight][col].y = (int)raw->hight * step;// + WINH / 20;
	raw->cor[raw->hight][col].x = (int)col * step;// + WINW / 20;
	raw->cor[raw->hight][col].col = 0XFFFFFF;
	if (arr[1])
		raw->cor[raw->hight][col].col = get_col(arr[1]);
	ft_del_2arr(&arr);
	printf("%.0f ", raw->cor[raw->hight][col].z); // test
	return (res);
}

int			parse_line(char *line, t_raw *raw, int step)
{
	char	**arr;
	size_t	x;
	size_t	j;

	j = 0;
	arr = ft_strsplit(line, ' ');
	x = ft_arrhight(arr);
	if (x != raw->width)
    {
        ft_del_2arr(&arr);
        return (1);
    }
	while (j < x)
	{
		if (validate_coord(arr[j], raw, j, step))
		{
			ft_del_2arr(&arr);
			return (1);
		}
		j++;
	}
	ft_del_2arr(&arr);
    return (0);
}

int		read_map(t_raw *raw, int fd)
{
	char 	*line;
	int 	step;

	line = NULL;
	step = 0;
	if (!get_next_line(fd, &line))
		return (1);
	raw->width = (size_t)ft_w_c(line, ' ');
	step = (raw->width > 1) ? (IMGW / (raw->width - 1)) : IMGW; // think about that
	printf("%d\n", step);//test
	if (parse_line(line, raw, step))
	{
		ft_strdel(&line);
		return (1);
	}
    ft_strdel(&line);
	printf("\n"); //test
	while (get_next_line(fd, &line))
	{
		(raw->hight)++;
		if (parse_line(line, raw, step))
		{
			ft_strdel(&line);
			return (1);
		}
        ft_strdel(&line);
		printf("\n"); //test
	}
    ft_strdel(&line);
    return (0);
}
