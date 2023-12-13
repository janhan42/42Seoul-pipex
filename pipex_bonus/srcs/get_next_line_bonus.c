/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 20:59:21 by janhan            #+#    #+#             */
/*   Updated: 2023/12/12 14:19:35 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/pipex_bonus.h"

int	ft_line(char *str, char **line, int result)
{
	int	i;

	i = 0;
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	if (str != NULL && str[i] == '\n')
		*line = ft_substr(str, 0, i);
	if (result == 0 && str == NULL)
	{
		*line = ft_strdup("");
		return (0);
	}
	if (result == 0 && str[i] == '\0')
	{
		*line = ft_strdup(str);
		return (0);
	}
	return (1);
}

char	*ft_rest(char *str)
{
	int		i;
	int		len;
	char	*temp;

	i = 0;
	len = ft_strlen(str);
	if (str != NULL)
	{
		while (str[i] != '\0' && str[i] != '\n')
			i++;
	}
	if (str[i] == '\n' && str != NULL)
	{
		temp = str;
		str = ft_substr(str, i + 1, len - i - 1);
		free(temp);
	}
	return (str);
}

char	*ft_read_line(char *str, int fd, int *result)
{
	char	buf[BUFFER_SIZE + 1];
	char	*temp;

	*result = 1;
	while ((*result) > 0)
	{
		*result = read(fd, buf, BUFFER_SIZE);
		if (*result <= 0)
			break ;
		buf[*result] = '\0';
		if (str == NULL)
			str = ft_strdup(buf);
		else
		{
			temp = str;
			str = ft_strjoin(str, buf);
			free(temp);
		}
		if (ft_strchr(str, '\n') != 0)
			break ;
	}
	return (str);
}

int	get_next_line(int fd, char **line)
{
	int			result;
	static char	*str;
	int			value;

	if (fd < 0 || line == NULL || BUFFER_SIZE == 0)
		return (-1);
	str = ft_read_line(str, fd, &result);
	if (result < 0)
		return (-1);
	value = ft_line(str, line, result);
	if (value == 1)
		str = ft_rest(str);
	if (value == 0)
	{
		free(str);
		str = NULL;
		return (0);
	}
	return (1);
}
