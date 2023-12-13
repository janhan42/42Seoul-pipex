/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_main_process.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:49:52 by janhan            #+#    #+#             */
/*   Updated: 2023/12/12 14:57:22 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"

/*
** pipe[0] -> read / pipe[1] -> write
** 0 : STDin, 1 : STDout
*/

static void	ft_child_process(t_info *info, char **av, char **ev)
{
	info->infile_fd = open(av[1], O_RDONLY);
	if (info->infile_fd < 0)
	{
		ft_putendl_fd("pipex: input: No such file or directory", 2);
		exit(1);
	}
	close(info->fd_pipe[0]);
	dup2(info->fd_pipe[1], STDOUT_FILENO);
	close(info->fd_pipe[1]);
	dup2(info->infile_fd, STDIN_FILENO);
	info->cmd_arg = ft_parsing_cmd(av[2]);
	info->path = ft_get_path(ev, info, info->cmd_arg[0]);
	if (execve(info->path, info->cmd_arg, ev) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(info->cmd_arg[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_info(info);
		exit(127);
	}
}

void	ft_parent_process(t_info *info, char **av, char **ev, pid_t *pid)
{
	waitpid(*pid, &info->pid_status, WNOHANG);
	info->outfile_fd = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (info->outfile_fd < 0)
	{
		ft_putendl_fd("file2(output) doesn't exist", 2);
		exit(1);
	}
	close(info->fd_pipe[1]);
	dup2(info->fd_pipe[0], STDIN_FILENO);
	close(info->fd_pipe[0]);
	dup2(info->outfile_fd, STDOUT_FILENO);
	info->cmd_arg = ft_parsing_cmd(av[3]);
	info->path = ft_get_path(ev, info, info->cmd_arg[0]);
	if (execve(info->path, info->cmd_arg, ev) < 0)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(info->cmd_arg[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_info(info);
		exit(127);
	}
}

void	ft_pipex_main_process(t_info *info, char **av, char **ev)
{
	pid_t	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_putendl_fd("fork failed", 2);
		exit(1);
	}
	else if (pid == 0)
		ft_child_process(info, av, ev);
	else if (pid > 0)
		ft_parent_process(info, av, ev, &pid);
}
/*
** pipe[0] -> read / pipe[1] -> write
** 0 : STDin, 1 : STDout
*/
