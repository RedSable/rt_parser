/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:43:41 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/05 20:49:20 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include <fcntl.h>
# include <stdlib.h>
# include "OpenCL/opencl.h"
# include "color.h"
# include "./libft/includes/libft.h"
# include <math.h>

typedef struct s_material			t_material; //64 bytes
typedef enum e_material_type		t_material_type;
typedef struct s_color	t_color;
typedef enum e_types		t_type;
typedef enum e_texture_type			t_texture_type;
typedef struct s_texture			t_texture; //32 bytes
typedef enum e_block_type			t_block_type;

enum	e_block_type
{
	ambient_light = 1,
	object,
	light,
	camera,
	options
};

enum	e_texture_type
{
	solid,
	checker,
	checker2d,
	transparent_checker,
	reflective_checker,
	perlin,
	smooth_perlin,
	turbulence_perlin,
	wave_perlin,
	image
};

enum	e_types
{
	cone,
	cylinder,
	paraboloid,
	plane,
	sphere,
	torus,
	triangle,
	box,
	disk,
	rectangle,
	generic_shere
	//todo(dmelessa): another generic types
};

struct		s_solid_texture
{
	t_color	color;
};

struct		s_checker_texture
{
	t_color	odd;
	t_color	even;
};

struct			s_smooth_perlin_texture
{
	cl_float	scale;
};

struct	s_image_texture
{
	int	offset;
	int	width;
	int	height;
};

union							u_texture_data
{
	struct s_solid_texture			solid;
	struct s_checker_texture		checker;
	struct s_smooth_perlin_texture	smooth_perlin;
};

struct						s_texture		//32bytes
{
	union u_texture_data	data;		//16 bytes
	t_texture_type			type;		//4 bytes
	char					gap[12];	//12 byte gap
};

enum e_material_type
{
	matte, //kd, ka
	phong,
	emissive,
	reflective,
	metal,		//mirror
	dielectric,	//transparance

	diffuse_light
};

struct					s_material //kd + ks < 1.0
{
	t_color				reflective_color;					//16 bytes
	t_material_type		type;								//4		20
	cl_float			kd; //diffuse reflection[0, 1]		//4		24
	cl_float			ka; //ambient reflection			//4		28
	cl_float			ks; //specular reflection [0, 1]	//4		32
	cl_float			kr;	//reflective coefficient		//4		36
	cl_float			kt; //transparent coefficient		//4		40
	cl_float			exp;								//4		44

	int					texture_id;							//4		48

	cl_uchar 			is_reflective;						//1		49
	cl_uchar			is_transparent;						//1		50
	cl_uchar			gap[14];							//2		64
};

typedef enum e_light_types			t_light_type;
typedef struct s_light				t_light;
typedef struct s_ambient_occluder	t_ambient_occluder;

//NOTE: some types will be removed from that list
enum	e_light_types
{
	ambient,
	ambient_occluder,
	directional,
	point,
	area,
	enviromental
};

struct				s_light
{
	cl_float4		origin;
	cl_float4		direction;
	t_color			color;
	cl_float		ls; //radiance scaling factor [0, inf)
	t_light_type	type;
	cl_int			object_id; //for area lights
	cl_int			gap;
};

struct				s_ambient_occluder
{
	cl_float4		u;
	cl_float4		v;
	cl_float4		w;
	t_color			color;
	t_color			min_amount;
	cl_float		ls; //radiance scaling factor [0, inf)
	cl_int			sampler_id;
	cl_int			gap[2];
};

typedef struct s_parsed_object
{
	t_material	material;
	t_texture	texture;
	cl_float4	origin;
	cl_float4	vector1;
	cl_float4	vector2;
	cl_float4	direction;
	cl_float3	rotation;
	cl_float3	scaling;
	cl_float	minm;
	cl_float	maxm;
	cl_float	radius;
	cl_float	radius2;
	t_type		type;
}				t_parsed_object;


// int			char_count(char *str);
// int		block_pars(char *line, int block_type);
int				str_len(char *str);
char			*get_key(char *str);
char			*get_value(char *str);
t_parsed_object		get_default_obj();
void			get_default_material(t_material *material);
void			get_default_texture(t_texture *texture);
void			pars_object(char *str);

#endif