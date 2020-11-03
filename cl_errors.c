/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cl_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aapricot <aapricot@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 18:49:39 by aapricot          #+#    #+#             */
/*   Updated: 2020/11/03 17:58:39 by aapricot         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		die(char *str)
{
	ft_putstr(str);
	exit(-1);
}

void		error_5(num)
{
	if (num == CL_INVALID_EVENT_WAIT_LIST)
		die("CL_INVALID_EVENT_WAIT_LIST\n");
	else if (num == CL_INVALID_EVENT)
		die("CL_INVALID_EVENT\n");
	else if (num == CL_INVALID_EVENT)
		die("CL_INVALID_EVENT\n");
	else if (num == CL_INVALID_GL_OBJECT)
		die("CL_INVALID_GL_OBJECT\n");
	else if (num == CL_INVALID_BUFFER_SIZE)
		die("CL_INVALID_BUFFER_SIZE\n");
	else if (num == CL_INVALID_MIP_LEVEL)
		die("CL_INVALID_MIP_LEVEL\n");
	else if (num == CL_INVALID_GLOBAL_WORK_SIZE)
		die("CL_INVALID_GLOBAL_WORK_SIZE\n");
	else if (num == CL_INVALID_PROPERTY)
		die("CL_INVALID_PROPERTY\n");
	else if (num == CL_INVALID_IMAGE_DESCRIPTOR)
		die("CL_INVALID_IMAGE_DESCRIPTOR'\n");
	else if (num == CL_INVALID_COMPILER_OPTIONS)
		die("CL_INVALID_COMPILER_OPTIONS\n");
	else if (num == CL_INVALID_LINKER_OPTIONS)
		die("CL_INVALID_LINKER_OPTIONS\n");
	else if (num == CL_INVALID_DEVICE_PARTITION_COUNT)
		die("CL_INVALID_DEVICE_PARTITION_COUNT\n");
}

void		error_4(int num)
{
	if (num == CL_INVALID_KERNEL_DEFINITION)
		die("CL_INVALID_KERNEL_DEFINITION\n");
	else if (num == CL_INVALID_KERNEL)
		die("CL_INVALID_KERNEL\n");
	else if (num == CL_INVALID_ARG_INDEX)
		die("CL_INVALID_ARG_INDEX\n");
	else if (num == CL_INVALID_ARG_VALUE)
		die("CL_INVALID_ARG_VALUE\n");
	else if (num == CL_INVALID_ARG_SIZE)
		die("CL_INVALID_ARG_SIZE\n");
	else if (num == CL_INVALID_KERNEL_ARGS)
		die("CL_INVALID_KERNEL_ARGS\n");
	else if (num == CL_INVALID_WORK_DIMENSION)
		die("CL_INVALID_WORK_DIMENSION\n");
	else if (num == CL_INVALID_WORK_GROUP_SIZE)
		die("CL_INVALID_WORK_GROUP_SIZE\n");
	else if (num == CL_INVALID_WORK_ITEM_SIZE)
		die("CL_INVALID_WORK_ITEM_SIZE\n");
	else if (num == CL_INVALID_GLOBAL_OFFSET)
		die("CL_INVALID_GLOBAL_OFFSET\n");
	error_5(num);
}

void		error_3(int num)
{
	if (num == CL_INVALID_QUEUE_PROPERTIES)
		die("CL_INVALID_QUEUE_PROPERTIES\n");
	else if (num == CL_INVALID_COMMAND_QUEUE)
		die("CL_INVALID_COMMAND_QUEUE\n");
	else if (num == CL_INVALID_HOST_PTR)
		die("CL_INVALID_HOST_PTR\n");
	else if (num == CL_INVALID_MEM_OBJECT)
		die("CL_INVALID_MEM_OBJECT\n");
	else if (num == CL_INVALID_IMAGE_FORMAT_DESCRIPTOR)
		die("CL_INVALID_IMAGE_FORMAT_DESCRIPTOR\n");
	else if (num == CL_INVALID_IMAGE_SIZE)
		die("CL_INVALID_IMAGE_SIZE\n");
	else if (num == CL_INVALID_SAMPLER)
		die("CL_INVALID_SAMPLER\n");
	else if (num == CL_INVALID_BINARY)
		die("CL_INVALID_BINARY\n");
	else if (num == CL_INVALID_BUILD_OPTIONS)
		die("CL_INVALID_BUILD_OPTIONS\n");
	else if (num == CL_INVALID_PROGRAM)
		die("CL_INVALID_PROGRAM\n");
	else if (num == CL_INVALID_PROGRAM_EXECUTABLE)
		die("CL_INVALID_PROGRAM_EXECUTABLE\n");
	else if (num == CL_INVALID_KERNEL_NAME)
		die("CL_INVALID_KERNEL_NAME\n");
	error_4(num);
}

void		error_2(int num)
{
	if (num == CL_MISALIGNED_SUB_BUFFER_OFFSET)
		die("CL_MISALIGNED_SUB_BUFFER_OFFSET\n");
	else if (CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST)
		die("CL_EXEC_STATUS_ERROR_FOR_EVENTS_IN_WAIT_LIST");
	else if (CL_COMPILE_PROGRAM_FAILURE)
		die("CL_COMPILE_PROGRAM_FAILURE\n");
	else if (num == CL_LINKER_NOT_AVAILABLE)
		die("CL_LINKER_NOT_AVAILABLE\n");
	else if (num == CL_LINK_PROGRAM_FAILURE)
		die("CL_LINK_PROGRAM_FAILURE\n");
	else if (num == CL_DEVICE_PARTITION_FAILED)
		die("CL_DEVICE_PARTITION_FAILED\n");
	else if (num == CL_KERNEL_ARG_INFO_NOT_AVAILABLE)
		die("CL_KERNEL_ARG_INFO_NOT_AVAILABLE\n");
	else if (num == CL_INVALID_VALUE)
		die("CL_INVALID_VALUE\n");
	else if (num == CL_INVALID_DEVICE_TYPE)
		die("CL_INVALID_DEVICE_TYPE\n");
	else if (num == CL_INVALID_PLATFORM)
		die("CL_INVALID_PLATFORM\n");
	else if (num == CL_INVALID_DEVICE)
		die("CL_INVALID_DEVICE\n");
	else if (num == CL_INVALID_CONTEXT)
		die("CL_INVALID_CONTEXT\n");
	error_3(num);
}

void		ft_cl_error(int num)
{
	if (num == CL_DEVICE_NOT_FOUND)
		die("CL_ERROR! Device not found!\n");
	else if (num == CL_DEVICE_NOT_AVAILABLE)
		die("CL_ERROR! Device not available!\n");
	else if (num == CL_COMPILER_NOT_AVAILABLE)
		die("CL_ERROR! Compiler not available!\n");
	else if (num == CL_MEM_OBJECT_ALLOCATION_FAILURE)
		die("CL_ERROR! Mem object allocation failure!\n");
	else if (num == CL_OUT_OF_RESOURCES)
		die("CL_ERROR! Out of resourses!\n");
	else if (num == CL_OUT_OF_HOST_MEMORY)
		die("CL_ERROR! Out of host memory!\n");
	else if (num == CL_PROFILING_INFO_NOT_AVAILABLE)
		die("CL_ERROR! Profiling info not available!\n");
	else if (num == CL_MEM_COPY_OVERLAP)
		die("CL_MEM_COPY_OVERLAP\n");
	else if (num == CL_IMAGE_FORMAT_MISMATCH)
		die("CL_IMAGE_FORMAT_MISMATCH\n");
	else if (num == CL_IMAGE_FORMAT_NOT_SUPPORTED)
		die("CL_IMAGE_FORMAT_NOT_SUPPORTED\n");
	else if (num == CL_BUILD_PROGRAM_FAILURE)
		die("CL_BUILD_PROGRAM_FAILURE\n");
	else if (num == CL_MAP_FAILURE)
		die("CL_MAP_FAILURE\n");
	error_2(num);
}
