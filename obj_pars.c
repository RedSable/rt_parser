/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:41:52 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 21:11:57 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
// #include "camera.h"
// #include "rt_options.h"
// #include "offset.h"

int				str_len(char *str)
{
	int			count;

	count = 0;
	while (str[count] != '\0')
		count++;
	count++;
	return (count);
}

char			*get_key(char *str)
{
	char			*a;
	int				i;

	a = (char *)malloc(sizeof(char) * 32);
	i = 0;
	while (*str != '=' && *str != '\0')
	{
		a[i] = *str;
		i++;
		str++;
	}
	a[i] = '\0';
	str++;
	return (a);
}

char			*get_value(char *str)
{
	char		*b;
	int			i;

	i = 0;
	b = (char *)malloc(sizeof(char) * 32);
	if (*str == '{')
	{
		str++;
		while (*str != '}')
		{
			b[i] = *str;
			i++;
			str++;
		}
		str++;
	}
	else
	{
		while (*str != ';' && *str != '}')
		{
			b[i] = *str;
			i++;
			str++;
		}
	}
	b[i] = '\0';
	return (b);
}

void				pars_object(char *str)
{
	char			*a;
	char			*b;
	// t_parsed_object	obj;

	while (*str != '{')
		str++;
	str++;
	while (*str != '\0')
	{
		a = get_key(str);
		str += str_len(a);
		b = get_value(str);
		str += str_len(b);
		printf("%s\n%s\n====\n", a, b);
		free(a);
		free(b);
		while (*str == ';' || *str == '}')
			str++;
		// while (i < g_obj_selector_size)
		// {
		// 	if (!ft_strcmp(g_selector_obj[i].name, a))
		// 		g_selector_obj[i].func(b, g_selector_obj[i].offset, &obj);
		// 	i++;
		// }
	}
	// add_parsed_object(obj);
}

int		main(int ac, char **av)
{
	char	*str="object{type=torus;radius=1.0f;radius2=0.2f;origin={1,2,3};rotate={x=45;y=30};scale={2.0f,2.0f,2.0f};material={type=dielectric;kt=1.5f}}";
	char	*line = "object{rotate={x=45;y=30}}";
	// char	*str="object{type=torus;material={type=dielectric;kt=1.5f}}";
	pars_object(str);
	return (0);
}