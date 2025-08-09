/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: absouman <absouman@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/19 19:48:31 by absouman          #+#    #+#             */
/*   Updated: 2025/08/07 15:19:19 by absouman         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	unsigned char	*tmp;
	unsigned int	i;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	i = 0;
	tmp = malloc(count * size);
	if (!tmp)
	{
		return (NULL);
	}
	while (i < count * size)
	{
		tmp[i++] = 0;
	}
	return (tmp);
}
