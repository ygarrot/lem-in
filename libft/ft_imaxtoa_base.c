/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_imaxtoa_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ygarrot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 10:15:15 by ygarrot           #+#    #+#             */
/*   Updated: 2018/01/10 12:53:26 by ygarrot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_imaxtoabase(intmax_t nbr, int base)
{
	uintmax_t	value;
	uintmax_t	result;
	int			neg;
	int			i;
	char		*str;

	neg = (base == 10 && (nbr < 0)) ? 1 : 0;
	i = neg;
	value = (nbr > 0) ? nbr : -nbr;
	result = value;
	while (result /= base)
		i++;
	if (!(str = (char*)malloc((i + (value ? 0 : 1) + 1) * sizeof(char))))
		return (NULL);
	str[i + 1] = '\0';
	while (value > 0)
	{
		str[i--] = ((value % base) < 10) ?
			(value % base) + '0' : (value % base) - 10 + 'a';
		value /= base;
	}
	str[0] = neg ? '-' : str[0];
	str[0] = nbr ? str[0] : '0';
	return (str);
}
