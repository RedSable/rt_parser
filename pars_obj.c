/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_pars.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/24 21:41:52 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/05 20:49:26 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "parser.h"
// #include "camera.h"
// #include "rt_options.h"
#include "offset.h"

t_selector		g_selector_obj[] = {
	{"origin", offsetof(t_parsed_object, origin), get_vector},
	{"direction", offsetof(t_parsed_object, direction), get_vector},
	{"rotation", offsetof(t_parsed_object, rotation), get_vector},
	{"scaling", offsetof(t_parsed_object, scaling), get_vector},
	{"vector1", offsetof(t_parsed_object, vector1), get_vector},
	{"vector2", offsetof(t_parsed_object, vector2), get_vector},
	{"type", offsetof(t_parsed_object, type), get_obj_type},
	{"radius", offsetof(t_parsed_object, radius), get_float},
	{"radius2", offsetof(t_parsed_object, radius2), get_float},
	{"maxm", offsetof(t_parsed_object, maxm), get_float},
	{"minm", offsetof(t_parsed_object, minm), get_float},
	{"material", offsetof(t_parsed_object, material), pars_material},
	{"texture", offsetof(t_parsed_object, texture), pars_texture}
};

int				g_obj_selector_size = sizeof(g_selector_obj) / sizeof(t_selector);

void			add_parsed_object(t_parsed_object *object)
{
	printf("type = %d\n", object->type);
	printf("origin.x = %f\n", object->origin.x);
	printf("origin.x = %f\n", object->origin.y);
	printf("origin.x = %f\n", object->origin.z);
	printf("direction.x = %f\n", object->direction.x);
	printf("direction.y = %f\n", object->direction.y);
	printf("direction.z = %f\n", object->direction.z);
	printf("rotation.x = %f\n", object->rotation.x);
	printf("rotation.y = %f\n", object->rotation.y);
	printf("rotation.z = %f\n", object->rotation.z);
	printf("scaling.x = %f\n", object->scaling.x);
	printf("scaling.y = %f\n", object->scaling.y);
	printf("scaling.z = %f\n", object->scaling.z);
	// printf("vector1 = %s\n", object->vector1);
	printf("radius = %f\n", object->radius);
	printf("radius2 = %f\n", object->radius2);
	printf("material\ntype = %d\n", object->material.type);
	printf("kt = %f\n", object->material.kt);
	printf("texture\ntype = %d\n", object->texture.type);
}

int				str_len(char *str)
{
	int			count;

	count = 0;
	while (str[count] != '\0')
		count++;
	count++;
	return (count);
}

char			*get_key(char *str)
{
	char			*a;
	int				i;

	a = (char *)malloc(sizeof(char) * 256);
	i = 0;
	while (*str != '=' && *str != '\0' && i < 256)
	{
		a[i] = *str;
		i++;
		str++;
	}
	a[i] = '\0';
	return (a);
}

char			*get_value(char *str)
{
	char		*b;
	int			i;

	b = (char *)malloc(sizeof(char) * 256);
	i = 0;
	if (*str == '{')
	{
		str++;
		while (*str != '}' && *str != '\0' && i < 256)
		{
			b[i] = *str;
			i++;
			str++;
		}
		str++;
	}
	else
	{
		while (*str != ';' && *str != '}' && *str != '\0' && i < 256)
		{
			b[i] = *str;
			i++;
			str++;
		}
	}
	b[i] = '\0';
	return (b);
}

void			pars_object(char *str)
{
	char			*a;
	char			*b;
	t_parsed_object	obj;
	int				i;

	i = 0;
	obj = get_default_obj();
	while (*str != '{' && *str != '\0')
		str++;
	str++;
	while (*str != '\0')
	{
		a = get_key(str);
		str += str_len(a);
		b = get_value(str);
		str += str_len(b);
		// printf("%s\n%s\n====\n", a, b);
		while (*str == ';' || *str == '}')
			str++;
		while (i < g_obj_selector_size)
		{
			if (!ft_strcmp(g_selector_obj[i].name, a))
			{
				g_selector_obj[i].func(b, g_selector_obj[i].offset, &obj);
				break ;
			}
			// printf("key = %s\ncheck = %s\n\n", a, g_selector_obj[i].name);
			i++;
		}
		i = 0;
		free(a);
		free(b);
	}
	add_parsed_object(&obj);
}

// int				main(int ac, char **av)
// {
// 	char	*str="object{type=torus;radius=1.0f;radius2=0.2f;origin={1,2,3};rotation={x=45;y=30};scaling={2.0f,2.0f,2.0f};material={type=dielectric;kt=1.5f}}";
// 	char	*line = "object{rotate={x=45;y=30}}";
// 	// char	*str="object{type=torus;material={type=dielectric;kt=1.5f}}";
// 	pars_object(str);
// 	printf("\n\n%s\n", str);
// 	return (0);
// }
