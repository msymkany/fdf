/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 20:18:26 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/26 20:18:31 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/libftprintf.h"
#include <mlx.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

/*
** open, read, write, close
** malloc, free
** perror, strerror
** exit
** All the functions defined in the math library (-lm and man 3 math)
** All the functions defined in the miniLibX library.
*/

typedef struct s_coord	t_coord;
typedef struct s_raw	t_raw;
typedef struct s_gen	t_gen;

typedef struct 		s_coord
{
	int				x;
	int				y;
	int				z;
	int 			col;
}					t_coord;

typedef struct 		s_raw
{
	t_coord			cor[100][100];
	size_t			hight;
	size_t			width;
}					t_raw;

typedef struct 		s_gen
{
	t_raw			*raw;
}					t_gen;


void		ft_usage(char *name);
int			read_map(t_raw *raw, int fd);