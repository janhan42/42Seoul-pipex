/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: janhan <janhan@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 21:19:49 by janhan            #+#    #+#             */
/*   Updated: 2023/10/11 13:17:05 by janhan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*next_node;
	t_list	*now;

	if (*lst == NULL || *del == NULL)
		return ;
	now = *lst;
	while (now)
	{
		next_node = now->next;
		ft_lstdelone(now, del);
		now = next_node;
	}
	*lst = NULL;
}
