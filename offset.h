/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:08:33 by aapricot          #+#    #+#             */
/*   Updated: 2020/10/31 01:07:25 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OFFSET_H
# define OFFSET_H

# include "parser.h"
# include "camera.h"
# include "color.h"
# include "rt_options.h"
# include <stddef.h>

typedef struct s_selector	t_selector;

struct			s_selector
{
	char		name[32];
	int			offset;
	void		(*func)();
};

void			get_vector(char *str, int offset, void *data);
void			get_type(char *str, int offset, void *data);
void			get_float(char *str, int offset, void *data);
void			pars_material(char *str, int offset, void *data);
void			get_color(char *str, int offset, void *data);
void			get_uchar(char *str, int offset, void *data);
void			pars_texture(char *str, int offset, void *data);
void			pars_ambient_occluder_sampler(char *str, int offset, void *data);
void			get_int(char *str, int offset, void *data);

t_selector		g_selector_obj[] = { {"origin", offsetof(t_parsed_object, origin), get_vector},
									{"direction", offsetof(t_parsed_object, direction), get_vector},
									{"rotation", offsetof(t_parsed_object, rotation), get_vector},
									{"scaling", offsetof(t_parsed_object, scaling), get_vector},
									{"vector1", offsetof(t_parsed_object, vector1), get_vector},
									{"vector2", offsetof(t_parsed_object, vector2), get_vector},
									{"type", offsetof(t_parsed_object, type), get_type},
									{"r", offsetof(t_parsed_object, r), get_float},
									{"r2", offsetof(t_parsed_object, r2), get_float},
									{"maxm", offsetof(t_parsed_object, maxm), get_float},
									{"minm", offsetof(t_parsed_object, minm), get_float},
									{"material", NULL, pars_material},
									{"texture", NULL, pars_texture} };

t_selector		g_selector_mat[] = { {"type", offsetof(t_parsed_object, material.type), get_type},
									{"ka", offsetof(t_parsed_object, material.ka), get_float},
									{"kd", offsetof(t_parsed_object, material.kd), get_float},
									{"kr", offsetof(t_parsed_object, material.kr), get_float},
									{"ks", offsetof(t_parsed_object, material.ks), get_float},
									{"kt", offsetof(t_parsed_object, material.kt), get_float},
									{"reflective_color", offsetof(t_parsed_object, material.reflective_color), get_color},
									{"is_reflective", offsetof(t_parsed_object, material.is_reflective), get_uchar},
									{"is_transparent", offsetof(t_parsed_object, material.is_transparent), get_uchar} };

t_selector		g_selector_tex[] = { {"type", offsetof(t_texture, type), get_type},
									{"color", offsetof(t_texture, data.solid.color), get_color},
									{"color2", offsetof(t_texture, data.checker.even), get_color},
									{"scale", offsetof(t_texture, data.smooth_perlin.scale), get_float} };

t_selector		g_selector_cam[] = { {"type", offsetof(t_camera, type), get_type},
									{"d", offsetof(t_camera, d), get_float},
									{"direction", offsetof(t_camera, direction), get_vector},
									{"f", offsetof(t_camera, f), get_float},
									{"l", offsetof(t_camera, l), get_float},
									{"origin", offsetof(t_camera, origin), get_vector},
									{"zoom", offsetof(t_camera, zoom), get_float} };

t_selector		g_selector_opt[] = { {"ambient_occluder_sampler", NULL, pars_ambient_occluder_sampler}, //maybe does not need
									{"ambient_occlusion", offsetof(t_rt_options, ambient_occlusion), get_int},
									{"background_color", offsetof(t_rt_options, background_color), get_color},
									{"depth", offsetof(t_rt_options, depth), get_int},
									{"shadows", offsetof(t_rt_options, shadows), get_int},
									{"area_lightning", offsetof(t_rt_options, area_lightning), get_int},
									{"spp", offsetof(t_rt_options, spp), get_float},
									{"aa_id", offsetof(t_rt_options, aa_id), get_int} };

t_selector		g_selector_light[] = { {"origin", offsetof(t_light, origin), get_vector},
									{"direction", offsetof(t_light, direction), get_vector},
									{"color", offsetof(t_light, color), get_color},
									{"ls", offsetof(t_light, ls), get_float},
									{"type", offsetof(t_light, type), get_type},
									{"object_id", offsetof(t_light, object_id), get_int} };

int				g_obj_selector_size = sizeof(g_selector_obj) / sizeof(t_selector);
int				g_mat_selector_size = sizeof(g_selector_mat) / sizeof(t_selector);
int				g_tex_selector_size = sizeof(g_selector_tex) / sizeof(t_selector);
int				g_cam_selector_size = sizeof(g_selector_cam) / sizeof(t_selector);
int				g_opt_selector_size = sizeof(g_selector_opt) / sizeof(t_selector);
int				g_light_selector_size = sizeof(g_selector_light) / sizeof(t_selector);

#endif
