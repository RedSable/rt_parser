/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   offset.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 20:08:33 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/04 21:02:43 by aapricot         ###   ########.fr       */
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
void			get_obj_type(char *str, int offset, void *data);
void			get_mat_type(char *str, int offset, void *data);
// void			get_tex_type(char* str, int offset, void *data);
void			get_cam_type(char *str, int offset, void *data);
void			get_light_type(char *str, int offset, void *data);
void			get_float(char *str, int offset, void *data);
void			pars_material(char *str, int offset, void *data);
void			get_color(char *str, int offset, void *data);
void			get_uchar(char *str, int offset, void *data);
void			pars_texture(char *str, int offset, void *data);
// void			pars_ambient_occluder_sampler(char *str, int offset, void *data); maybe does not need
void			get_int(char *str, int offset, void *data);

extern t_selector		g_selector_obj[];
extern t_selector		g_selector_mat[];
// extern t_selector		g_selector_tex[];
extern t_selector		g_selector_cam[];
extern t_selector		g_selector_opt[];
extern t_selector		g_selector_light[];

extern int				g_obj_selector_size;
extern int				g_mat_selector_size;
// extern int				g_tex_selector_size;
extern int				g_cam_selector_size;
extern int				g_opt_selector_size;
extern int				g_light_selector_size;

#endif
