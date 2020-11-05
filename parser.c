/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/19 19:56:06 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/05 20:49:44 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "parser.h"
#include "offset.h"
// #include "rt.h"

void		to_lower(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
	{
		str[i] = ft_tolower(str[i]);
		i++;
	}
}

int			check_block_type(char *str)
{
	int		i;

	i = 0;
	to_lower(str);
	if (!ft_strcmp(str, "ambient_light"))
		i = 1;
	if (!ft_strcmp(str, "object"))
		i = 2;
	if (!ft_strcmp(str, "light"))
		i = 3;
	if (!ft_strcmp(str, "camera"))
		i = 4;
	if (!ft_strcmp(str, "options"))
		i = 5;
	free(str);
	return (i);
}

int			block_type_lengh(char *str)
{
	int		i;

	i = 0;
	while (str[i] != '{' && str[i] != '=')
		i++;
	return (i);
}

int			get_block_type(char *str)
{
	int		i;
	char	*type;
	int		j;

	i = 0;
	j = 0;
	if (str[0] == '=' || str[0] == '{')
		return (-1);
	type = (char *)malloc(sizeof(char) * (block_type_lengh(str) + 1));
	while (str[i] != '{' && str[i] != '=')
	{
		type[j] = str[i];
		i++;
		j++;
	}
	type[j] = '\0';
	return (check_block_type(type));
}

int			check_brackets(char *str)
{
	int		i;
	int		brackets;
	int		count;

	i = 0;
	count = 0;
	brackets = 0;
	while (str[i] != '\0')
	{
		if (count == 0 && brackets != 0)
			return (-1);
		if (str[i] == '{')
		{
			brackets++;
			count++;
		}
		else if (str[i] == '}')
		{
			brackets++;
			count--;
		}
		i++;
	}
	if (count != 0 || brackets == 0)
		return (-1);
	return (1);
}

int			char_count(char *str)
{
	int		i;
	int		count;

	count = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
			count++;
		i++;
	}
	return (count);
}

char		*delete_tabs(char *str)
{
	char	*res;
	int		i;
	int		j;

	j = 0;
	i = 0;
	res = (char *)malloc(sizeof(char) * (char_count(str) + 1));
	while (str[i] != '\0')
	{
		if (str[i] != '\t' && str[i] != ' ' && str[i] != '\n')
		{
			res[j] = str[i];
			j++;
		}
		i++;
	}
	res[j] = '\0';
	free(str);
	return (res);
}

char		*get_read_block(int fd)
{
	char	*current_line;
	char	*block_line;
	char	*tmp;
	int		i;

	block_line = NULL;
	while ((i = get_next_line(fd, &current_line)) == 1)
	{
		if (!ft_strcmp(current_line, "\0") && block_line != NULL)
		{
			free(current_line);
			break ;
		}
		else
		{
			if (block_line == NULL)
				block_line = ft_strdup(current_line);
			else
			{
				tmp = block_line;
				block_line = ft_strjoin(tmp, current_line);
				free(tmp);
			}
		}
		free(current_line);
	}
	return (block_line);
}

int			parser(char *file_name)  //t_tr *rt
{
	int		fd;
	char	*line;
	int		i;

	i = 0;
	if ((fd = open(file_name, O_RDONLY)) < 0)
		;
	while ((line = get_read_block(fd)) != NULL)
	{
		line = delete_tabs(line);
		printf("%d:\n\n", i);
		if (check_brackets(line) == 1)
		{
			if (get_block_type(line) == ambient_light)
				printf("ambient_light:\n");
			else if (get_block_type(line) == object)
				pars_object(line);
			else if (get_block_type(line) == light)
				printf("light:\n");
			else if (get_block_type(line) == camera)
				printf("camera:\n");
			else if (get_block_type(line) == options)
				printf("options:\n");
			else if (get_block_type(line) == 0)
			{
				printf("Unknown type\n\n");
				i++;
				free(line);
				continue;
			}
			else if (get_block_type(line) == -1)
			{
				printf("Name or type does not exist\n\n");
				i++;
				free(line);
				continue;
			}
			printf("%s\n\n", line);
		}
		else
			printf("Invalid block\n\n");
		free(line);
		i++;
	}
	close(fd);
	return (0);
}

int		main(int ac, char **av)
{
	parser(av[1]);
	return (0);
}
