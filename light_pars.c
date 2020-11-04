/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:56:59 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/04 18:58:30 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "offset.h"

t_selector		g_selector_light[] = { {"origin", offsetof(t_light, origin), get_vector},
									{"direction", offsetof(t_light, direction), get_vector},
									{"color", offsetof(t_light, color), get_color},
									{"ls", offsetof(t_light, ls), get_float},
									{"type", offsetof(t_light, type), get_light_type},
									{"object_id", offsetof(t_light, object_id), get_int} };

int				g_light_selector_size = sizeof(g_selector_light) / sizeof(t_selector);

void		par_light(char *str)
{
	;
}