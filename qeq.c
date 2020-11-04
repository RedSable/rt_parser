/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   qeq.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/30 18:48:31 by dmelessa          #+#    #+#             */
/*   Updated: 2020/11/04 19:47:23 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "string.h"

typedef struct	s_vec
{
	float	x;
	float	y;
	float	z;
}				t_vec;

typedef struct s_a	t_a;

void	read_vec(char *str, int offset, void *data)
{
	t_vec	*vec_ptr;
	unsigned char	*p;

	p = (unsigned char *)data;
	p = p + offset;

	vec_ptr = (t_vec *)p;
	vec_ptr->x = 1.0f;
	vec_ptr->y = 2.0f;
	vec_ptr->z = 3.0f;
}

struct	s_a
{
	char	name[32];
	int		offset;
	void	(*func)();
};

t_a	g_array[] = { {"origin", 0, read_vec },
					{ "rotation", 12, read_vec } };
int	g_array_size = sizeof(g_array) / sizeof(t_a);

typedef struct s_obj	t_obj;

struct	s_obj
{
	t_vec	origin;
	t_vec	rotation;
};

int	main(void)
{
	char	name[256];
	int		i;
	t_obj	obj;

	strcpy(name, "rotation");
	i = 0;
	while (i < g_array_size)
	{
		if (strcmp(name, g_array[i].name) == 0)
		{
			g_array[i].func(NULL, g_array[i].offset, &obj, 1);
			printf("%f %f %f\n", obj.rotation.x, obj.rotation.y, obj.rotation.z);
			return (0);
		}
		i++;
	}
}
