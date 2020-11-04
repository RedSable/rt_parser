/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_default.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 17:11:31 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/04 20:52:07 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "offset.h"

t_camera		get_default_camera()
{
	t_camera	camera;

	camera.angle = 0.0f;
	camera.d = 0.0f;
	camera.direction = (cl_float4){0.0f, 0.0f, 0.0f};
	camera.exposure_time = 0.0f;
	camera.f = 0.0f;
	camera.fov = 90;
	camera.inv_h = 0.0f;
	camera.inv_w = 0.0f;
	camera.l = 0.0f;
	camera.normalized = 1;
	camera.origin = (cl_float4){0.0f, 0.0f, 0.0f};
	camera.ratio = 0.0f;
	camera.sampler_id = 1;
	camera.type = perspective;
	camera.up = (cl_float4){0.0f, 1.0f, 0.0f};
	camera.zoom = 1.0f;
	return (camera);
}

t_light			get_default_light()
{
	t_light		light;

	light.color = (t_color){0.0f, 0.0f, 0.0f};
	light.direction = (cl_float4){0.0f, 0.0f, 0.0f};
	light.ls = 0.0f;
	light.origin = (cl_float4){0.0f, 0.0f, 0.0f};
	light.type = point;
	light.object_id = 0;
	return (light);
}

void			get_default_texture(t_texture *texture)
{
	texture->type = solid;
	texture->data.solid.color = (t_color){255.0f, 0.0f, 0.0f};
	texture->data.checker.even = (t_color){255.0f, 0.0f, 0.0f};
	texture->data.checker.odd = (t_color){255.0f, 0.0f, 0.0f};
	texture->data.smooth_perlin.scale = 0.0f;
}

void			get_default_material(t_material *material)
{
	material->exp = 0.0f;
	material->is_reflective = "false";
	material->is_transparent = "false";
	material->ka = 0.0f;
	material->kd = 0.0f;
	material->kr = 0.0f;
	material->ks = 0.0f;
	material->kt = 0.0f;
	material->reflective_color = (t_color){255.0f, 0.0f, 0.0f};
	material->type = matte;
}

t_parsed_object		get_default_obj()
{
	t_parsed_object	obj;

	obj.direction = (cl_float4){0.0f, 0.0f, 0.0f};
	get_default_material(&obj.material);
	get_default_texture(&obj.texture);
	obj.maxm = 0.0f;
	obj.minm = 0.0f;
	obj.origin = (cl_float4){0.0f, 0.0f, 0.0f};
	obj.radius2 = 0.0f;
	obj.radius = 0.0f;
	obj.rotation = (cl_float3){0.0f, 0.0f, 0.0f};
	obj.scaling = (cl_float3){0.0f, 0.0f, 0.0f};
	obj.type = sphere;
	obj.vector1 = (cl_float4){0.0f, 0.0f, 0.0f};
	obj.vector2 = (cl_float4){0.0f, 0.0f, 0.0f};
	return (obj);
}
