/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   logs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 16:10:52 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/09 17:55:40 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LOGS_H
# define LOGS_H

# include "parser.h"

# define UNKNOWN_SCENE_TYPE					-1
# define SCENE_TYPE_DOES_NOT_EXIST			-2
# define OBJ_TYPE_DOES_NOT_EXIST			-3
# define MATERIAL_TYPE_DOES_NOT_EXIST		-4
# define TEXTURE_TYPE_DOES_NOT_EXIST		-5
# define WRITE_BLOCK						-6
# define COMMENT							-7
# define BAD_BRACKETS						-8

void		write_logs(int num_log, int fd, char *str);

#endif