/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex_process_bonus.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:38:59 by janhan            #+#    #+#             */
/*   Updated: 2023/12/12 14:34:11 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_heredoc_process(int piped_heredoc_fd[2], char **av)
{
	char	*line;

	if (pipe(piped_heredoc_fd) == -1)
	{
		ft_putendl_fd("pipe failed", 2);
		exit(1);
	}
	write(STDOUT_FILENO, "pipe heredoc>> ", 14);
	while (get_next_line(0, &line) != 0)
	{
		if (ft_strcmp(line, av[2]) == 0)
		{
			free(line);
			break ;
		}
		write(STDOUT_FILENO, "pipe heredoc>> ", 14);
		write(piped_heredoc_fd[1], line, ft_strlen(line));
		write(piped_heredoc_fd[1], "\n", 1);
		free(line);
	}
}

static void	ft_heredoc_parent(char **av, char **ev, t_info *info, pid_t *pid)
{
	waitpid(*pid, &info->pid_status, WNOHANG);
	info->outfile_fd = open(av[5], O_RDWR | O_CREAT | O_APPEND, 0644);
	if (info->outfile_fd < 0)
	{
		ft_putendl_fd("file(output) doesn't exist", 2);
		exit(1);
	}
	close(info->fd_pipe[1]);
	dup2(info->fd_pipe[0], STDIN_FILENO);
	close(info->fd_pipe[0]);
	dup2(info->outfile_fd, STDOUT_FILENO);
	info->cmd_arg = ft_parsing_cmd(av[4]);
	info->path = ft_get_path(ev, info, info->cmd_arg[0]);
	if (execve(info->path, info->cmd_arg, ev) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(info->cmd_arg[0], 2);
		ft_putendl_fd(": command not found", 2);
		ft_free_info(info);
		exit(1);
	}
}

void	ft_heredoc(char **av, char **ev, t_info *info)
{
	int	piped_heredoc_fd[2];

	ft_heredoc_process(piped_heredoc_fd, av);
	dup2(piped_heredoc_fd[0], STDIN_FILENO);
	close(piped_heredoc_fd[1]);
	dup2(info->fd_pipe[1], STDOUT_FILENO);
	close(info->fd_pipe[0]);
	info->cmd_arg = ft_parsing_cmd(av[3]);
	info->path = ft_get_path(ev, info, info->cmd_arg[0]);
	if (execve(info->path, info->cmd_arg, ev) == -1)
	{
		ft_putstr_fd("pipex: ", 2);
		ft_putstr_fd(info->cmd_arg[0], 2);
		ft_putendl_fd(": command not found", 2);
		exit(127);
	}
}

void	ft_pipex_bonus_process(t_info *info, char **av, char **ev)
{
	pid_t	pid;

	pid = fork();
	if (pid < 0)
		ft_putendl_fd("fork failed", 2);
	else if (pid == 0)
	{
		if (ft_strcmp(av[1], "here_doc") == 0 && info->h_flag == 1)
			ft_heredoc(av, ev, info);
		else
			ft_child_process(info, av, ev);
	}
	else if (pid > 0)
	{
		if (ft_strcmp(av[1], "here_doc") == 0 && info->h_flag == 1)
			ft_heredoc_parent(av, ev, info, &pid);
		else
			ft_parent_process(info, av, ev, &pid);
	}
}
