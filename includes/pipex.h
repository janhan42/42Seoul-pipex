/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 15:21:53 by janhan            #+#    #+#             */
/*   Updated: 2023/12/14 10:38:28 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

/*============== struct =============*/
typedef struct s_parsing {
	int		len;
	int		i;
	int		j;
	int		count;
}	t_parsing;

typedef struct s_info {
	int		infile_fd;
	int		outfile_fd;
	int		fd_pipe[2];
	int		pid_status;
	char	*pathline;
	char	**env;
	char	*path;
	char	**cmd_arg;
}	t_info;

/*============== utils ==============*/
void	ft_putchar(const char c);
void	ft_putstr(const char *str);

/*========= pipex alt utils =========*/
void	ft_free_tab(char **str);
void	ft_free_info(t_info *info);
char	**ft_parsing_cmd(const char *cmd);
void	ft_single_quota(char *cmd, char **res, t_parsing *tab);
void	ft_double_quota(char *cmd, char **res, t_parsing *tab);
void	ft_space_case(char *cmd, char **res, t_parsing *tab);
char	*ft_get_path(char **ev, t_info *info, char *cmd);

/*======== pipex main process ========*/
void	ft_pipex_main_process(t_info *info, char **av, char **ev);

#endif
