/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:14:07 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 22:03:42 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "offset.h"

void		pars_material(char *str, int offset, void *data)
{
	char			*a;
	char			*b;
	// t_parsed_object	obj;

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
}