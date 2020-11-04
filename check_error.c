/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/03 22:41:06 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 23:04:04 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "errors.h"
#include "parser.h"

static t_cl_errors	err_array = { {CL_DEVICE_NOT_FOUND, "CL_DEVICE_NOT_FOUND"},
									{CL_DEVICE_NOT_AVAILABLE, "CL_DEVICE_NOT_AVAILABLE"},
									{CL_COMPILER_NOT_AVAILABLE, "CL_COMPILER_NOT_AVAILABLE"},
									{CL_MEM_OBJECT_ALLOCATION_FAILURE, "CL_MEM_OBJECT_ALLOCATION_FAILURE"},
									{CL_OUT_OF_RESOURCES, "CL_OUT_OF_RESOURCES"},
									{CL_OUT_OF_HOST_MEMORY, "CL_OUT_OF_HOST_MEMORY"},
									{CL_PROFILING_INFO_NOT_AVAILABLE, "CL_PROFILING_INFO_NOT_AVAILABLE"},
									{CL_MEM_COPY_OVERLAP, "CL_MEM_COPY_OVERLAP"},
									{CL_IMAGE_FORMAT_MISMATCH, "CL_IMAGE_FORMAT_MISMATCH"},
									{CL_IMAGE_FORMAT_NOT_SUPPORTED, "CL_IMAGE_FORMAT_NOT_SUPPORTED"},
									{CL_BUILD_PROGRAM_FAILURE, "CL_BUILD_PROGRAM_FAILURE"},
									{CL_MAP_FAILURE, "CL_MAP_FAILURE"},
									{CL_MISALIGNED_SUB_BUFFER_OFFSET, "CL_MISALIGNED_SUB_BUFFER_OFFSET"},
									{CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST, "CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST"},
									{CL_COMPILE_PROGRAM_FAILURE, "CL_COMPILE_PROGRAM_FAILURE"},
									{CL_LINKER_NOT_AVAILABLE, "CL_LINKER_NOT_AVAILABLE"},
									{CL_LINK_PROGRAM_FAILURE, "CL_LINK_PROGRAM_FAILURE"},
									{CL_DEVICE_PARTITION_FAILED, "CL_DEVICE_PARTITION_FAILED"},
									{CL_KERNEL_ARG_INFO_NOT_AVAILABLE, "CL_KERNEL_ARG_INFO_NOT_AVAILABLE"}};