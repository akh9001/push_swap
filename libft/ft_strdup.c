/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhalidy <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/15 21:55:10 by akhalidy          #+#    #+#             */
/*   Updated: 2019/10/17 07:46:42 by akhalidy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	l;

	l = ft_strlen(s1);
	str = (char *)malloc(l + 1);
	if (str)
		ft_strlcpy(str, s1, l + 1);
	return (str);
}
