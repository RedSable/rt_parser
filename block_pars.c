/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   block_pars.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:41:52 by aapricot          #+#    #+#             */
/*   Updated: 2020/10/30 19:50:06 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "camera.h"
#include "rt_options.h"

// t_selector	selector = {{"type", func()},
// 						{"color", func()}}

int		pars_ambient_light(char *line)
{
	
	return (0);
}

t_material	get_obj_material(char *line)
{
	t_material	material;
	t_texture	texture;

	texture.type = get_texture_type(line);
	texture.data.solid.color = get_solid_color(line);
	texture.data.checker.even = get_checker_even(line);
	texture.data.checker.odd = get_checker_odd(line);
	texture.data.smooth_perlin.scale = get_smooth_perlin_scale(line);
	material.type = get_material_type(line);
	material.ka = get_ka(line);
	material.kd = get_kd(line);
	material.kr = get_kr(line);
	material.ks = get_ks(line);
	material.kt = get_kt(line);
	material.reflective_color = get_reflective_color(line);
	material.is_reflective = get_reflective(line);
	material.is_transparent = get_transparent(line);
	material.texture_id = add_texture(texture);
	return (material);
}

int		pars_object(char *line)
{
	t_parsed_object		obj;

	obj.type = get_obj_type(line);
	obj.direction = get_obj_direction(line);
	obj.rotation = get_obj_rotation(line);
	obj.material = get_obj_material(line);
	obj.origin = get_obj_origin(line);
	obj.scaling = get_obj_scaling(line);
	obj.vector1 = get_obj_vec1(line);
	obj.vector2 = get_obj_vec2(line);
	obj.r = get_obj_r(line);
	obj.r2 = get_obj_r2(line);
	obj.maxm = get_obj_maxm(line);
	obj.minm = get_obj_minm(line);
	add_parsed_object(obj);
	return (0);
}

int		pars_light(char *line)
{
	return (0);
}

t_camera		pars_camera(char *line)
{
	t_camera	camera;

	camera.d = get_camera_d(line);
	camera.direction = get_camera_direction(line);
	camera.f = get_camera_f(line);
	camera.l = get_camera_l(line);
	camera.origin = get_camera_origin(line);
	camera.type = get_camera_type(line);
	camera.zoom = get_camera_zoom(line);
	return (camera);
}

int		pars_options_token(t_rt_options options, char check[256])
{
	char	a[256];
	char	b[256];
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (check[i] != '=' && check != '{')
	{
		a[j] = check[i];
		i++;
		j++;
	}
	a[j] = '\0';
	i++;
	j = 0;
	while (check[i] != '\0')
	{
		b[j] = check[i];
		i++;
		j++;
	}
	b[j] = '\0';
}

int		pars_options(char *line)
{
	t_rt_options	options;
	char			check[256];
	char			*tmp;
	int				i;

	i = 0;
	tmp = line;
	options = get_default_options();
	while (*line != '{')
		*line++;
	*line++;
	while (*line != '\0')
	{
		while (*line != ';' && *line != '\0')
		{
			check[i] = *line;
			*line++;
			i++;	
		}
		check[i] = '\0';
		*line++;
		i = 0;
		pars_options_token(options, check);
	}
	// options.ambient_occlusion = get_ambient_occlusion(line);
	// options.area_lightning = get_area_lightning(line);
	// options.background_color = get_background_color(line);
	// options.depth = get_depth(line);
	// options.shadows = get_shadows(line);
	return (0);
}
