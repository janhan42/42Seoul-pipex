/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cmd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:02:03 by janhan            #+#    #+#             */
/*   Updated: 2023/12/11 21:20:37 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static void	ft_count_cmd(const char *cmd, int *i, int *count)
{
	if (cmd[*i] == 39)
	{
		(*i)++;
		while (cmd[*i] != 39 && cmd[*i] != '\0')
			(*i)++;
		(*count)++;
	}
	else if (cmd[*i] == 34)
	{
		(*i)++;
		while (cmd[*i] != 34 && cmd[*i] != '\0')
			(*i)++;
		(*count)++;
	}
	else
	{
		while (cmd[*i] != ' ' && cmd[*i] != '\0')
			(*i)++;
		(*count)++;
	}
}

static int	ft_count_cmd_groups(const char *cmd)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (cmd[i] != '\0')
	{
		if (cmd[i] != ' ')
			ft_count_cmd(cmd, &i, &count);
		if (cmd[i] == '\0')
			break ;
		else
			i++;
	}
	return (count);
}

static char	**ft_parsing_malloc_cmd(char *cmd, char **result, t_parsing *tab)
{
	tab->i = 0;
	tab->j = 0;
	while (cmd[tab->i] && tab->j < tab->len)
	{
		tab->count = 0;
		if (cmd[tab->i] != ' ')
		{
			if (cmd[tab->i] == 39)
				ft_single_quota(cmd, result, tab);
			else if (cmd[tab->i] == 34)
				ft_double_quota(cmd, result, tab);
			else
				ft_space_case(cmd, result, tab);
		}
		result[tab->j][tab->count] = '\0';
		tab->i++;
		tab->j++;
	}
	result[tab->j] = NULL;
	return (result);
}
/*
typedef struct s_parsing {
	int		len;
	int		i;
	int		j;
	int		count;
}	t_parsing;
*/

char	**ft_parsing_cmd(const char *cmd)
{
	t_parsing	tab;
	char		**result;

	if (cmd == NULL)
		return (NULL);
	tab.len = ft_count_cmd_groups(cmd);
	result = ft_calloc(sizeof(char *), tab.len + 1);
	if (!result)
		return (NULL);
	return (ft_parsing_malloc_cmd((char *)cmd, result, &tab));
}
