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

t_selector		g_selector_tex[] = { {"type", offsetof(t_texture, type), get_tex_type},
									{"color", offsetof(t_texture, data.solid.color), get_color},
									{"color2", offsetof(t_texture, data.checker.even), get_color},
									{"scale", offsetof(t_texture, data.smooth_perlin.scale), get_float} };

int				g_tex_selector_size = sizeof(g_selector_tex) / sizeof(t_selector);

void		pars_texture(char *str, int offset, void *data)
{
	;
}