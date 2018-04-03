/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_del_2arr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msymkany <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 20:38:05 by msymkany          #+#    #+#             */
/*   Updated: 2018/02/28 20:38:10 by msymkany         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/libft.h"

void		ft_del_2arr(char ***arr)
{
	size_t		i;
	char 		**ptr;

	ptr = *arr;
	i = 0;
	while (ptr[i])
    {
        ft_strdel(&ptr[i]);
        i++;
    }
	free(ptr);
	ptr = NULL;
}
