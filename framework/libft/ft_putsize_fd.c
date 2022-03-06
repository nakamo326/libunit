/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsize_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkamei <mkamei@student.42tokyo.jp>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/12 14:56:05 by ynakamot          #+#    #+#             */
/*   Updated: 2022/03/06 13:33:34 by mkamei           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	output_num(size_t n, int fd)
{
	if (n / 10 == 0)
	{
		ft_putchar_fd('0' + n, fd);
		return ;
	}
	output_num(n / 10, fd);
	ft_putchar_fd('0' + n % 10, fd);
}

void	ft_putsize_fd(size_t n, int fd)
{
	output_num(n, fd);
}
