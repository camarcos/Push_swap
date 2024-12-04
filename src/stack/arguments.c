/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: carolinamc <carolinamc@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/14 11:55:24 by camarcos          #+#    #+#             */
/*   Updated: 2024/12/04 17:28:35 by carolinamc       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/push_swap.h"

void	sort_two(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
}
//cuando hay solo dos argumentos

void	sort_three(t_stack *a)
{
	int	f;
	int	s;
	int	t;

	f = a->top->value;
	s = a->top->next->value;
	t = a->top->next->next->value;
	if (f > s && s < t && f < t)
		sa(a);
	else if (f > s && s > t)
	{
		sa(a);
		rra(a);
	}
	else if (f > s && s < t && f > t)
		ra(a);
	else if (f < s && s > t && f < t)
	{
		sa(a);
		ra(a);
	}
	else if (f < s && s > t && f > t)
		rra(a);
}
//cuando hay tres argumentos

void	sort_four(t_stack *a)
{
	if (a->top->value > a->top->next->value)
		sa(a);
	if (a->top->next->value > a->top->next->next->value)
	{
		ra(a);
		sa(a);
		rra(a);
	}
	if (a->top->value > a->top->next->value)
		sa(a);
}
//cuando hay cuatro argumentos

void	sort_small_stack(t_stack *a, t_stack *b)
{
	while (a->size > 3)
		pb(a, b);
	if (a->size == 3)
		sort_three(a);
	while (b->size > 0)
	{
		pa(a, b);
		if (a->top->value > a->top->next->value)
			sa(a);
	}
	if (a->size == 4)
		sort_four(a);
	else if (a->size == 5)
	{
		if (a->top->value > a->top->next->value)
			sa(a);
	}
}
//para contolar con pocos argumentos

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
	else if (a->size == 4 || a->size == 5)
		sort_small_stack(a, b);
	else
		sort_large_stack(a, b);
	free_list(a);
	free_list(b);
}
//determinar el algoritmo de ordenación según el tamaño de la pila
//Libera memoria antes de salir, asegurando que no haya fugas
