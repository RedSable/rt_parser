/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_default_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:11:17 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/01 18:20:07 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "offset.h"

void			get_default_amb_occ_samp(t_sampler *sampler)
{
	sampler->count = 1;
	sampler->disk_samples_offset = 1;
	sampler->hemisphere_samples_offset = 1;
	sampler->jump = 1;
	sampler->num_samples = 1;
	sampler->num_sets = 1;
	sampler->offset = 1;
	sampler->samples_type = 1;
	sampler->type = none;
}

t_rt_options	get_default_options()
{
	t_rt_options	options;

	options.aa_id = 1;
	get_deafult_amb_occ_samp(&options.ambient_occluder_sampler);
	options.ambient_occlusion = 1;
	options.area_lightning = 1;
	options.background_color = (t_color){255.0f, 255.0f, 255.0f};
	options.depth = 1;
	options.reset = 0;
	options.shadows = 1;
	options.spp = 0.0f;
	return (options);
}