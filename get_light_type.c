/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_type.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:48:15 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/05 20:06:38 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "offset.h"
#include "parser.h"

int					get_tex_type_value(char *str)
{
	if (!ft_strcmp(str, "solid"))
		return (solid);
	else if (!ft_strcmp(str, "checker"))
		return (checker);
	else if (!ft_strcmp(str, "checker2d"))
		return (checker2d);
	else if (!ft_strcmp(str, "transparent_checker"))
		return (transparent_checker);
	else if (!ft_strcmp(str, "reflective_checker"))
		return (reflective_checker);
	else if (!ft_strcmp(str, "perlin"))
		return (perlin);
	else if (!ft_strcmp(str, "smooth_perlin"))
		return (smooth_perlin);
	else if (!ft_strcmp(str, "turbulence_perlin"))
		return (turbulence_perlin);
	else if (!ft_strcmp(str, "wave_perlin"))
		return (wave_perlin);
	else if (!ft_strcmp(str, "image"))
		return (image);
	return (-1);
}

int					get_light_type_value(char *str)
{
	if (!ft_strcmp(str, "ambient"))
		return (ambient);
	else if (!ft_strcmp(str, "ambient_occluder"))
		return (ambient_occluder);
	else if (!ft_strcmp(str, "directional"))
		return (directional);
	else if (!ft_strcmp(str, "point"))
		return (point);
	else if (!ft_strcmp(str, "area"))
		return (area);
	else if (!ft_strcmp(str, "enviromental"))
		return (enviromental);
	return (-1);
}

void				get_tex_type(char *str, int offset, void *data)
{
	t_texture_type	*type;

	type = (t_texture_type *)((unsigned char *)data + offset);
	*type = get_tex_type_value(str);
}

void				get_light_type(char *str, int offset, void *data)
{
	unsigned char	*v;
	t_light_type	*type;

	v = (unsigned char *)data + offset;
	type = (t_light_type *)v;
	*type = get_light_type_value(str);
}