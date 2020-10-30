/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:41:52 by aapricot          #+#    #+#             */
/*   Updated: 2020/10/31 01:48:52 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "camera.h"
#include "rt_options.h"
#include "offset.h"

void				pars_object(char *str)
{
	char			a[32];
	char			b[32];
	t_parsed_object	obj;
	int				i;

	i = 0;
	while (*str != '{')
		*str++;
	str++;
	while (*str != '\0')
	{
		while (*str != '=' && *str != '{')
		{
			a[i] = *str;
			i++;
			*str++;
		}
		a[i] = '\0';
		i = 0;
		if (*str == '{')
		{
			*str++;
			while (*str != '}')
			{
				b[i] = *str;
				i++;
				*str++;
			}
			*str++;
		}
		else
		{
			while (*str != ';' && *str != '}')
			{
				b[i] = *str;
				i++;
				*str++;
			}
		}
		*str++;
		b[i] = '\0';
		i = 0;
		*str++;
		if (*str == ';')
			*str++;
		while (i < g_obj_selector_size)
		{
			if (!ft_strcmp(g_selector_obj[i].name, a))
				g_selector_obj[i].func(b, g_selector_obj[i].offset, &obj);
			i++;
		}
		i = 0;
	}
	add_parsed_object(obj);
}
