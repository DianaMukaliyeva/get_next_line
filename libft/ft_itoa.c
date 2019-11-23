/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmukaliy <dmukaliy@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 18:50:38 by dmukaliy          #+#    #+#             */
/*   Updated: 2019/10/28 19:13:52 by dmukaliy         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		get_size(long n)
{
	int	size;
	int	sign;

	sign = n < 0 ? 1 : 0;
	n = sign == 0 ? n : n * -1;
	size = 0;
	while (n >= 10)
	{
		n = n / 10;
		size++;
	}
	return (size + sign);
}

char	*ft_itoa(int n)
{
	long	num;
	char	*res;
	int		size;

	size = get_size(n);
	num = (long)n;
	if (!(res = ft_strnew(size + 1)))
		return (NULL);
	if (num < 0)
		num *= -1;
	while (num >= 10)
	{
		res[size--] = num % 10 + '0';
		num /= 10;
	}
	res[size--] = num + '0';
	if (n < 0)
		res[size] = '-';
	return (res);
}
