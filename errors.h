/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:41:16 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 22:59:29 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERORRS_H
# define ERRORS_H

# include "libft.h"

typedef struct s_cl_errors		t_cl_errors;

struct							s_cl_errors
{
	int							numerror;
	char						*nem_message;
};

#endif