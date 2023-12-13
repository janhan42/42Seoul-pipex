/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:44:10 by janhan            #+#    #+#             */
/*   Updated: 2023/12/11 16:33:47 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex.h"
#include <stdlib.h>

/*
** if pipe() success, fd_pipe[0]는 파이프의 읽기 끝단을 의미하는 파일 디스크립터가 되고,
** fd_pipe[1]은 파이프의 쓰기 끝단을 의미하는 파일 디스크립터가 된다.
*/

int	main(int ac, char **av, char **ev)
{
	t_info	info;

	if (ac != 5)
	{
		ft_putendl_fd("usage: ./pipex file1 cm1 cmd2 file2", 2);
		exit(1);
	}
	if (pipe(info.fd_pipe) == -1)
	{
		ft_putendl_fd("pipe failed", 2);
		exit(1);
	}
	ft_pipex_main_process(&info, av, ev);
	ft_free_info(&info);
	close(info.outfile_fd);
	close(info.infile_fd);
	return (EXIT_SUCCESS);
}
