/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:41:52 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 18:26:17 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
// #include "parser.h"
// #include "camera.h"
// #include "rt_options.h"
// #include "offset.h"

void				pars_object(char *str)
{
	char			a[32];
	char			b[32];
	// t_parsed_object	obj;
	int				i;

	i = 0;
	while (*str != '{')
		str++;
	str++;
	while (*str != '\0')
	{
		while (*str != '=' && *str != '{')
		{
			a[i] = *str;
			i++;
			str++;
		}
		a[i] = '\0';
		str++;
		i = 0;
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
		printf("%s\n%s\n====\n", a, b);
		i = 0;
		while (*str == ';' || *str == '}')
			str++;
		// while (i < g_obj_selector_size)
		// {
		// 	if (!ft_strcmp(g_selector_obj[i].name, a))
		// 		g_selector_obj[i].func(b, g_selector_obj[i].offset, &obj);
		// 	i++;
		// }
		i = 0;
	}
	// add_parsed_object(obj);
}

int		main(int ac, char **av)
{
	char	*str="object{type=torus;radius=1.0f;radius2=0.2f;origin={1,2,3};rotate={x=45;y=30};scale={2.0f,2.0f,2.0f};material={type=dielectric;kt=1.5f}}";
	// char	*str="object{type=torus;material={type=dielectric;kt=1.5f}}";
	pars_object(str);
	return (0);
}