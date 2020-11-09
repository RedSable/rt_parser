/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_pars.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 16:28:12 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/05 19:59:27 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "offset.h"

t_selector		g_selector_tex[] = {
	{"type", offsetof(t_texture, type), get_tex_type},
	{"color", offsetof(t_texture, data.solid.color), get_color},
	{"color2", offsetof(t_texture, data.checker.even), get_color},
	{"scale", offsetof(t_texture, data.smooth_perlin.scale), get_float} };

int				g_tex_sel_size = sizeof(g_selector_tex) / sizeof(t_selector);

void		pars_texture(char *str, int offset, void *data)
{
	char			*a;
	char			*b;
	int				i;
	t_texture		*texture;

	texture = (t_texture *)((unsigned char *)data + offset);
	i = 0;
	while (*str != '\0')
	{
		ft_putstr("!!!!!:");
		ft_putendl(str);
		a = get_key(&str);
		b = get_value(&str);
		// printf("%s\n%s\n====\n", a, b);
		// while (*str == ';' || *str == '}')
		// 	str++;
		while (i < g_tex_sel_size)
		{
			if (!ft_strcmp(g_selector_tex[i].name, a))
			{
				g_selector_tex[i].func(b, g_selector_tex[i].offset, texture);
				break ;
			}
			// printf("key = %s\ncheck = %s\n\n", a, g_selector_tex[i].name);
			i++;
		}
		i = 0;
		free(a);
		free(b);
	}
}
