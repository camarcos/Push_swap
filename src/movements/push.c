/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: camarcos <camarcos@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 17:42:05 by camarcos          #+#    #+#             */
/*   Updated: 2024/11/26 16:29:04 by camarcos         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	push(t_stack *from, t_stack *to, int print, const char *move)
{
	t_node	*temp;

	if (from->size == 0)
		return ;
	temp = from->top;
	from->top = from->top->next;
	temp->next = to->top;
	to->top = temp;
	from->size--;
	to->size++;
	if (print)
		write(1, move, ft_strlen(move));
}

void	pa(t_stack *a, t_stack *b)
{
	push(b, a, 1, "pa\n");
}
void	pb(t_stack *a, t_stack *b)
{
	push(a, b, 1, "pb\n");
}
void pp(t_stack *a, t_stack *b)
{
	push(b, a, 0, NULL);
	push(a, b, 0, NULL);
	write(1, "pp\n", 3);
}