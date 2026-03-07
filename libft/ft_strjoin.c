/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/29 18:18:44 by abegou            #+#    #+#             */
/*   Updated: 2025/11/10 19:58:25 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*ret;
	int		j;

	if (!s1 || !s2)
		return (NULL);
	ret = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (ret == NULL)
		return (NULL);
	j = -1;
	while (s1[++j])
		ret[j] = s1[j];
	ret[j] = '\0';
	j = -1;
	while (s2[++j])
		ret[ft_strlen(s1) + j] = s2[j];
	ret[ft_strlen(s1) + j] = '\0';
	return (ret);
}
