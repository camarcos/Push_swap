/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pruebas.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/26 13:28:44 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/29 00:08:51 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

// static long	ft_atol_strict(char **split, long i)
// {
// 	long	result;
// 	int		j;
// 	int		sign;

// 	result = 0;
// 	j = 0;
// 	sign = check_sign(split, i, &j);
// 	while (split[i][j])
// 	{
// 		if (!ft_isdigit(split[i][j]))
// 		{
// 			ft_free_matrix(split);
// 			ft_error();
// 		}
// 		result = result * 10 + split[i][j++] - '0';
// 	}
// 	result = result * sign;
// 	check_fit_int(result, split);
// 	return (result);
// }

void	sort_small_stack(t_stack *a, t_stack *b)
{
	printf("--------------");
	while (a->size > 3)
		pb(a, b);
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	while (b->size > 0)
	{
		pa(a, b);
		if (a->top->value > a->top->next->value)
			sa(a);
	}
}

void	sort_stack(t_stack *a, t_stack *b)
{
	if (is_sorted(a))
	{
		free_list(a);
		free_list(b);
		exit(0);
	}
	if (a->size == 2)
		sort_two(a);
	else if (a->size == 3)
		sort_three(a);
	else if (a->size <= 5)
		sort_small_stack(a, b);
	else
		sort_large_stack(a, b);
	
	free_list(a);
	free_list(b);
}
