/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:28:07 by janhan            #+#    #+#             */
/*   Updated: 2023/12/11 21:35:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_heredoc_cmd_flag(int ac, char **av, t_info *info)
{
	if (ac == 6)
	{
		if (ft_strcmp(av[1], "hero_doc") != 0)
		{
			ft_putendl_fd("cmmand here_doc not corrected", 2);
			exit(1);
		}
		else
			info->h_flag = 1;
	}
}

int	main(int ac, char **av, char **ev)
{
	t_info	info;

	if (ac < 5 || ac > 6)
	{
		ft_putendl_fd("usage1: ./pipex here_doc LIMITER cmd1 cmd2 file", 2);
		ft_putendl_fd("usage1: ./pipex file1 cmd1 cmd2 file2", 2);
		exit(1);
	}
	info.h_flag = 0;
	ft_heredoc_cmd_flag(ac, av, &info);
	if (pipe(info.fd_pipe) == -1)
	{
		ft_putendl_fd("pipe failed", 2);
		exit(1);
	}
	ft_pipex_bonus_process(&info, av, ev);
}
