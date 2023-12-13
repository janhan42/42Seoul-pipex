/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_info.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:28:26 by janhan            #+#    #+#             */
/*   Updated: 2023/12/11 15:29:06 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

void	ft_free_info(t_info *info)
{
	free(info->path);
	ft_free_tab(info->cmd_arg);
	info->path = NULL;
	info->cmd_arg = NULL;
}
