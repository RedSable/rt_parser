/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   option_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:55:24 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/04 18:56:46 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "offset.h"

t_selector		g_selector_opt[] = { //{"ambient_occluder_sampler", NULL, pars_ambient_occluder_sampler}, //maybe does not need
									{"ambient_occlusion", offsetof(t_rt_options, ambient_occlusion), get_int},
									{"background_color", offsetof(t_rt_options, background_color), get_color},
									{"depth", offsetof(t_rt_options, depth), get_int},
									{"shadows", offsetof(t_rt_options, shadows), get_int},
									{"area_lightning", offsetof(t_rt_options, area_lightning), get_int},
									{"spp", offsetof(t_rt_options, spp), get_float},
									{"aa_id", offsetof(t_rt_options, aa_id), get_int} };

int				g_opt_selector_size = sizeof(g_selector_opt) / sizeof(t_selector);

void		pars_option(char *str)
{
	;
}