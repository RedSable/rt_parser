/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   material_pars.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:14:07 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/04 21:05:17 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "offset.h"

t_selector		g_selector_mat[] = { {"type", offsetof(t_parsed_object, material.type), get_mat_type},
									{"ka", offsetof(t_parsed_object, material.ka), get_float},
									{"kd", offsetof(t_parsed_object, material.kd), get_float},
									{"kr", offsetof(t_parsed_object, material.kr), get_float},
									{"ks", offsetof(t_parsed_object, material.ks), get_float},
									{"kt", offsetof(t_parsed_object, material.kt), get_float},
									{"reflective_color", offsetof(t_parsed_object, material.reflective_color), get_color},
									{"is_reflective", offsetof(t_parsed_object, material.is_reflective), get_uchar},
									{"is_transparent", offsetof(t_parsed_object, material.is_transparent), get_uchar} };

int				g_mat_selector_size = sizeof(g_selector_mat) / sizeof(t_selector);

// void		pars_material(char *str, int offset, void *data)
// {
// 	char			*a;
// 	char			*b;
// 	// t_parsed_object	obj;

// 	while (*str != '\0')
// 	{
// 		a = get_key(str);
// 		str += str_len(a);
// 		b = get_value(str);
// 		str += str_len(b);
// 		printf("%s\n%s\n====\n", a, b);
// 		free(a);
// 		free(b);
// 		while (*str == ';' || *str == '}')
// 			str++;
// 		// while (i < g_obj_selector_size)
// 		// {
// 		// 	if (!ft_strcmp(g_selector_obj[i].name, a))
// 		// 		g_selector_obj[i].func(b, g_selector_obj[i].offset, &obj);
// 		// 	i++;
// 		// }
// 	}
// }

void		pars_material(char *str, int offset, void *data)
{
	unsigned char	*v;
	t_material		*material;

	v = (unsigned char *)data;
	v = v + offset;
	material = (t_material *)v;
	material->type = dielectric;
	material->kt = 1.5f;
}