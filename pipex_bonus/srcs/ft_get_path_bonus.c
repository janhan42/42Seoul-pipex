/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_path_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:24:11 by janhan            #+#    #+#             */
/*   Updated: 2023/12/11 21:30:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_find_pathline(char **ev, t_info *info)
{
	int	i;

	i = 0;
	while (ev[i])
	{
		if (!ft_strncmp(ev[i], "PATH=", 5))
			info->pathline = ev[i] + 5;
		i++;
	}
}

char	*ft_get_path(char **ev, t_info *info, char *cmd)
{
	char	**path_split;
	char	*temp1;
	char	*temp2;
	int		i;

	i = 0;
	if (!ft_strncmp(cmd, "/", 1))
		return (cmd);
	ft_find_pathline(ev, info);
	path_split = ft_split(info->pathline, ':');
	while (path_split[i])
	{
		temp1 = ft_strjoin(path_split[i], "/");
		temp2 = ft_strjoin(temp1, cmd);
		free(temp1);
		if (access(temp2, F_OK | X_OK) == 0)
		{
			ft_free_tab(path_split);
			return (temp2);
		}
		free(temp2);
		i++;
	}
	ft_free_tab(path_split);
	return (NULL);
}
