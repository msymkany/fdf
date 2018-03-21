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

#ifndef FDF_H
# define FDF_H

# include "../libft/includes/libft.h"
# include "../libft/includes/libftprintf.h"
# include <mlx.h>
# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
//#include <ncurses.h>

#define MAXMAP 100
#define WINHIGHT 1000
#define WINLEN 1000

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
	t_coord			cor[MAXMAP][MAXMAP];
	size_t			hight;
	size_t			width;
}					t_raw;

typedef struct 		s_gen
{
	t_raw			*raw;
	void			*ptr;
	void			*wnd;
	int 			not_over;
}					t_gen;


void		ft_usage(char *name);
int			read_map(t_raw *raw, int fd);
int 	key_hook(int key_code, t_gen *gen);

#endif