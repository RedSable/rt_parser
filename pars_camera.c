/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_pars.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/04 18:52:00 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/04 18:53:28 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "offset.h"

t_selector		g_selector_cam[] = { {"type", offsetof(t_camera, type), get_cam_type},
									{"d", offsetof(t_camera, d), get_float},
									{"direction", offsetof(t_camera, direction), get_vector},
									{"f", offsetof(t_camera, f), get_float},
									{"l", offsetof(t_camera, l), get_float},
									{"origin", offsetof(t_camera, origin), get_vector},
									{"zoom", offsetof(t_camera, zoom), get_float} };

int				g_cam_selector_size = sizeof(g_selector_cam) / sizeof(t_selector);

void		pars_material(char *str, int offset, void *data)
{
	;
}