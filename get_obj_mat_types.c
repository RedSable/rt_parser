/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_types.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 21:18:59 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 21:34:29 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "offset.h"
#include "parser.h"

int					get_obj_type_value(char *str)
{
	if (!ft_strcmp(str, "cone"))
		return (cone);
	else if (!ft_strcmp(str, "cylinder"))
		return (cylinder);
	else if (!ft_strcmp(str, "parabaloid"))
		return (paraboloid);
	else if (!ft_strcmp(str, "plane"))
		return (plane);
	else if (!ft_strcmp(str, "sphere"))
		return (sphere);
	else if (!ft_strcmp(str, "torus"))
		return (torus);
	else if (!ft_strcmp(str, "triangle"))
		return (triangle);
	else if (!ft_strcmp(str, "box"))
		return (box);
	else if (!ft_strcmp(str, "disk"))
		return (disk);
	else if (!ft_strcmp(str, "rectangle"))
		return (rectangle);
	else if (!ft_strcmp(str, "generic_sphere"))
		return (generic_shere);
	return (-1);
}

int					get_mat_type_value(char *str)
{
	if (!ft_strcmp(str, "matte"))
		return (matte);
	else if (!ft_strcmp(str, "phong"))
		return (phong);
	else if (!ft_strcmp(str, "emissive"))
		return (emissive);
	else if (!ft_strcmp(str, "reflective"))
		return (reflective);
	else if (!ft_strcmp(str, "metal"))
		return (metal);
	else if (!ft_strcmp(str, "dielectric"))
		return (dielectric);
	else if (!ft_strcmp(str, "diffuse_light"))
		return (diffuse_light);
	return (-1);
}

void				get_obj_type(char *str, int offset, void *data)
{
	unsigned char	*v;
	t_type			type;

	v = (unsigned char *)data + offset;
	type = (t_type *)v;
	type = get_obj_type_value(str);
	// if (type == -1)
	// 	die("No valid object type");  if error. or we can get default value
}

void				get_mat_type(char *str, int offset, void *data)
{
	unsigned char	*v;
	t_material_type	type;

	v = (unsigned char *)data + offset;
	type = (t_material_type *)v;
	type = get_mat_type_value(str);
}