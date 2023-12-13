/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 17:13:43 by janhan            #+#    #+#             */
/*   Updated: 2023/12/12 14:23:10 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <sys/wait.h>
# include <fcntl.h>
# include <stdio.h>
# include "../libft/libft.h"

# define BUFFER_SIZE 1

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
	int		h_flag;
}	t_info;

/*============== utils ==============*/
int			get_next_line(int fd, char **line);
void		ft_putchar(const char c);
void		ft_putstr(const char *str);
int			ft_strcmp(char *s1, char *s2);

/*========= pipex alt utils =========*/
void		ft_parent_process(t_info *info, char **av, char **env, pid_t *pid);
void		ft_child_process(t_info *info, char **av, char **env);
char		**ft_parsing_cmd(const char *cmd);
void		ft_single_quota(char *cmd, char **res, t_parsing *tab);
void		ft_double_quota(char *cmd, char **res, t_parsing *tab);
void		ft_space_case(char *cmd, char **res, t_parsing *tab);
void		ft_free_tab(char **str);
void		ft_free_info(t_info *info);
/*=========== pipex bonus =============*/
void		ft_heredoc(char **av, char **ev, t_info *info);
void		ft_pipex_bonus_process(t_info *info, char **av, char **ev);
char		*ft_get_path(char **ev, t_info *info, char *cmd);
#endif
