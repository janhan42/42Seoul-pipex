/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parsing_cmd_utils_bonus.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 16:19:33 by janhan            #+#    #+#             */
/*   Updated: 2023/12/11 21:22:07 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

static int	ft_tab_len(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != '\0' && s[i] != c)
	{
		i++;
		len++;
	}
	return (len);
}

void	ft_single_quota(char *cmd, char **res, t_parsing *tab)
{
	tab->i++;
	res[tab->j] = ft_calloc(sizeof(char), ft_tab_len(cmd, 39, tab->i) + 1);
	if (!res)
		return ;
	while (cmd[tab->i] != '\0' && cmd[tab->i] != 39)
		res[tab->j][tab->count++] = cmd[tab->i++];
}

void	ft_double_quota(char *cmd, char **res, t_parsing *tab)
{
	tab->i++;
	res[tab->j] = ft_calloc(sizeof(char), ft_tab_len(cmd, 34, tab->i) + 1);
	if (!res)
		return ;
	while (cmd[tab->i] != '\0' && cmd[tab->i] != 34)
		res[tab->j][tab->count++] = cmd[tab->i++];
}

void	ft_space_case(char *cmd, char **res, t_parsing *tab)
{
	res[tab->j] = ft_calloc(sizeof(char), ft_tab_len(cmd, ' ', tab->i) + 1);
	if (!res)
		return ;
	while (cmd[tab->i] != '\0' && cmd[tab->i] != ' ')
		res[tab->j][tab->count++] = cmd[tab->i++];
}
